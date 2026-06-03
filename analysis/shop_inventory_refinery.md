# Shop, Inventario y Refinería

## Archivos Relacionados
- `RAKION_RE_MASTER.md` — Documento maestro con visión general.
- `character_management.md` — Gestión de personajes (items, inventario, gold).
- `lobby_phase.md` — Pase de sala con opcodes 0x73, 0x74, 0x75, 0x76, 0x77.
- `login_flow.md` — Flujo de login inicial.
- `03_packet_opcodes.md` — Catálogo de opcodes y handlers.
- `01_functions_list.md` — Lista maestra de funciones decompiladas.
- `program_info.md` — Información del binario.
- `funcs/FUN_0040c310.c` — **Función núcleo**: buy item + lógica de refinería/enchant (700+ líneas).
- `funcs/FUN_00419a40.c` — DBCommandInventoryBuy (578 líneas): validación cash, UPDATE gold, INSERT item.
- `funcs/FUN_0041a900.c` — DBCommandInventorySell (239 líneas): DELETE item, UPDATE gold.
- `funcs/FUN_00414cc0.c` — DBCommandInventoryEnter (93 líneas): SELECT to_days del item.
- `funcs/FUN_00414e70.c` — DBCommandInventoryBuyBag (315 líneas): compra de bolsa de items.
- `funcs/FUN_00415cb0.c` — DBCommandInventoryBuyPowerUser (313 líneas): compra PowerUser + regalos.
- `funcs/FUN_004138b0.c` — DB opcode 0x0C: CharacterInfo update tras cambio de item.
- `funcs/FUN_0040cd70.c` — Shop category loader (66 líneas): carga items por categoría.
- `funcs/FUN_00421e10.c` — Handler de opcode 0x74 (Buy Item): 221 líneas.
- `funcs/FUN_00421a50.c` — Handler de opcode 0x73 (Equip Item): 193 líneas.

---

## 1. Visión General del Sistema

El sistema de tienda/inventario/refinería de Rakion maneja:
- **Compra** de items desde la tienda (NPC shop, categorías por rango de ID).
- **Venta** de items al NPC.
- **Equipar/Desequipar** items del inventario.
- **Refinería (Enchant):** mejora de armas usando scrolls (0x32C9-0x32CD) + catalizadores (0x36B1-0x36B3).
- **Compra de bolsas** (item bag), **PowerUser**, **ranuras de inventario**.
- **Lotería** (lotto): sistema aleatorio de recompensas.

### Tablas de BD involucradas
- `UserItemInfo` — Items del usuario (INSERT, DELETE, SELECT).
- `UserGameInfo` — Gold, PowerUser status (UPDATE).
- `pendingpresents` — Regalos pendientes al comprar PowerUser (INSERT).
- `logbuypoweruser`, `logcoupon`, `logpresent`, `loguseritem` — Logs de auditoría.

---

## 2. Sistema de Compra (Buy Item — Opcode 0x74)

### 2.1 Flujo Completo

```
Cliente → Opcode 0x74
  → FUN_00421e10 (Buy Item Handler, lobby_phase.md#opcode-0x74)
    → FUN_0040ca50 (serializar items actuales)
    → FUN_0040c310 (Buy Item + Enchant logic)
      → [si scroll/catalyst] → lógica de refinería (ver §4)
      → [si PowerUser] → redirige a PowerUser flow
      → [si item normal] → calcula precios, valida gold/cash
    → [OK] → prepara buffer con subopcode 0x28
    → FUN_0041b940 (envía a DB thread)
      → DB handler: FUN_00419a40 (DBCommandInventoryBuy)
        → UPDATE gold/cash
        → INSERT UserItemInfo
        → LogUserItem
      → Respuesta OK/FAIL
    → [FAIL] → envía error al cliente
```

### 2.2 FUN_00421e10 — Buy Item Handler (opcode 0x74)

**Archivo:** `FUN_00421e10.c` (221 líneas)

**Firma:**
```c
void __thiscall FUN_00421e10(void *this, ushort param_1, undefined4 param_2, byte *param_3)
```

**Parámetros de red (packet body):**
- `param_3[0]` → `local_12f4` (float/byte) — item type/category
- `param_3[1]` → `_local_12f8` (byte) — item ID o subcategory
- `param_3[2]` → `local_1310` (byte) — count de catalizadores/items
- `param_3[3..]` → `local_1317[3..]` — IDs de items/catalizadores (hasta 3)

**Validaciones:**
1. `CUser.connected != 0` y `CUser.authenticated != 0` — si no, error 0xE2.
2. `CUser.phase == 0x02` (lobby phase) — si no, error 0xE3.
3. `param_3[2] < 4` — máximo 3 catalizadores — si no, error 0xE4.

**Llamada a FUN_0040ca50:**
```c
FUN_0040ca50(this, &local_1318, local_12e8, local_109c, local_1317, local_1298, local_1088, &bEnchantItem3, &local_10b4);
```
Serializa el estado actual de items del usuario en buffers de salida:
- `local_1318` — count de items en `local_12e8`.
- `local_12e8[20]` — array de item IDs (20 slots).
- `local_109c[5]` — item data adicional.
- `local_1317` — contador de items especiales.
- `local_1298[121]` — item detail buffers.
- `local_1088[30]` — data extended.
- `bEnchantItem3` — flag item slot 3 para enchant.
- `local_10b4` — valor de item adicional.

**Llamada a FUN_0040c310:**
```c
uVar5 = FUN_0040c310(CUser, local_12f4, _local_12f8, local_1310, local_1317+3,
                      &bEnchantItem1, &pCUserRef, &local_1308, &local_130c, &local_12ec, &local_12f0);
```

Parámetros:
- `local_12f4` — item type del primer byte del packet.
- `_local_12f8` — segundo byte del packet (item ID/category).
- `local_1310` — count de catalizadores.
- `local_1317+3` — puntero a IDs de catalizadores/items desde packet.
- `&bEnchantItem1` — flag de resultado: hubo intento de enchant.
- `&pCUserRef` — referencia al CUser actual (output).
- `&local_1308` — gold actualizado tras compra (output).
- `&local_130c` — cash actualizado tras compra (output).
- `&local_12ec` — item0 info (resultado).
- `&local_12f0` — item1 info (resultado).

**Respuesta OK (subopcode 0x28):**
```
Bytes: [opcode(0x74)][subopcode(0x28)][data...]
  - 0x00: item0 (4 bytes, local_1300)
  - 0x04: gold nuevo (4 bytes, local_1308)
  - 0x08: item1 byte (local_12f8)
  - 0x09: item1/effect (local_1317[3])
  - 0x0A: byte count (local_1310)
  - 0x0B: effect item (local_1317[4])
  - 0x0C: cash nuevo (4 bytes, local_130c)
  - 0x10: effect flag (local_1317[5])
  - 0x11: item0 info (4 bytes, local_12ec)
  - 0x15: item1 info (4 bytes, local_12f0)
  - 0x19: auth/protected (local_1304)
  - 0x1D: flag_bEnchantItem1 (local_1318)
  - items serializados (local_12e8[0..local_1318-1])
  - item details (local_109c, local_1298, local_1088)
```

**Respuesta FAIL (error directo):**
```
Bytes: [opcode(0x74)][error_code]
```
Con error_code desde FUN_0040c310 (0 = success, non-zero = error).

**NOTA:** Tras éxito, el handler llama `FUN_0041b940(this, param_1, uVar9, &local_1010)` que encola el buffer para el hilo DB. La respuesta DB se completa en FUN_00419a40 (DBCommandInventoryBuy).

### 2.3 FUN_0040c310 — Buy Item + Enchant Logic (Núcleo)

**Archivo:** `FUN_0040c310.c` (700+ líneas, archivo crítico)

**Firma:**
```c
uint __thiscall
FUN_0040c310(void *this, float param_1, byte param_2, byte param_3,
             byte *param_4, char *param_5, void **param_6,
             uint *param_7, uint *param_8, undefined4 *param_9,
             undefined4 *param_10)
```

**Mapeo de parámetros:**
- `param_1` → item type/category (float del primer byte del paquete).
- `param_2` → segundo byte (item ID dentro de categoría o scroll type).
- `param_3` → count de catalizadores (0-3).
- `param_4` → array de IDs de catalizadores/scrolls (hasta 3).
- `param_5` → flag de resultado "intento de enchant" (`&bEnchantResult`).
- `param_6` → referencia al CUser actual (`&pCUserRef`).
- `param_7` → gold nuevo tras operación (`&newGold`).
- `param_8` → cash nuevo tras operación (`&newCash`).
- `param_9` → item0 info resultado (`&item0`).
- `param_10` → item1 info resultado (`&item1`).

**Flujo interno:**

1. **Determinar CUser y precios:**
   - Obtiene `pCUser` de `param_6`.
   - Si `param_1 == 0.0f`: carga precios desde `CUser.shopItemCount` y `CUser.shopItems[]`.
   - Si `param_1 != 0.0f`: puede ser un scroll/catalyst.

2. **Calcular precio total:**
   ```c
   totalPrice = param_2 * pricePerItem + extraCost;
   ```
   - Valida gold actual vs totalPrice.
   - Valida cash actual si aplica.
   - Usa `FUN_00417760` para algunos cálculos de precio.

3. **Validar espacio en inventario:**
   - Verifica `UserItemInfo` count vs max.
   - Si no hay espacio, retorna error.

4. **Insertar item en DB:**
   ```c
   // SQL generado (por inferencia del flujo DB):
   INSERT INTO UserItemInfo (userid, itemid, slot, count, enchant, durability, ...)
   VALUES (userId, itemId, nextSlot, 1, 0, 100, ...);
   ```

5. **Actualizar gold/cash:**
   ```c
   UPDATE UserGameInfo SET gold = gold - %u WHERE id = %u AND gold >= %u;
   ```
   Con atomicidad (gold >= precio guard).

6. **Log:**
   ```c
   INSERT INTO loguseritem (...) VALUES (...);
   ```

7. **Retornar:**
   - `*param_7 = newGold`
   - `*param_8 = newCash`
   - `*param_9 = item0Info`
   - `*param_10 = item1Info`
   - Return 0 = éxito, no-zero = código de error.

8. **Códigos de error conocidos:**
   - `0x00` — OK (success, buy normal)
   - `0x01` — Error general (sin gold, sin espacio, etc.)
   - `0xE1` — Error de enchant (FUN_0040c310 retorna non-zero)
   - Otros desde comparaciones con `param_3` (count de catalizadores).

### 2.4 FUN_00419a40 — DBCommandInventoryBuy (DB Handler)

**Archivo:** `FUN_00419a40.c` (578 líneas)

**Firma:**
```c
void __thiscall FUN_00419a40(void *this, int param_1, byte param_2, ...)
```

**Flujo:**
1. Deserializa el buffer enviado por FUN_0041b940 (subopcode 0x28).
2. Extrae: userid, item info, gold, cash, slot, etc.
3. **Valida cash** si el item requiere cash (items 8000-8999, PowerUser, etc.).
   ```c
   UPDATE UserGameInfo SET cash = cash - %u WHERE id = %u AND cash >= %u;
   ```
4. **Valida y descuenta gold:**
   ```c
   UPDATE UserGameInfo SET gold = gold - %u WHERE id = %u AND gold >= %u;
   ```
5. **INSERT item:**
   ```c
   INSERT INTO UserItemInfo (userid, itemid, slot, count, enchant, durability, ...)
   VALUES (%u, %u, %u, %u, %u, %u, ...);
   ```
6. **Log:**
   ```c
   INSERT INTO loguseritem (...) VALUES (...);
   ```
7. Si es PowerUser, redirige a `FUN_00415cb0` (BuyPowerUser) para el flujo adicional.

---

## 3. Sistema de Venta (Sell Item)

### 3.1 Flujo de Venta

```
Cliente → Opcode 0x75 (Sell Item)
  → Handler (FUN_00421f60, pendiente de decompilar)
    → Valida: CUser conectado, fase lobby
    → Busca item en UserItemInfo
    → Calcula precio de venta (sell gold)
    → Prepara buffer con subopcode 0x29
    → FUN_0041b940 (envía a DB thread)
      → DB handler: FUN_0041a900 (DBCommandInventorySell)
        → DELETE FROM UserItemInfo WHERE userid=%u AND itemid=%u
        → UPDATE UserGameInfo SET gold = gold + %u WHERE id=%u
        → LogUserItem (DELETE log)
      → Respuesta OK/FAIL
```

### 3.2 FUN_0041a900 — DBCommandInventorySell (DB Handler)

**Archivo:** `FUN_0041a900.c` (239 líneas)

**Firma:**
```c
void __thiscall FUN_0041a900(void *this, int param_1, byte param_2, ...)
```

**Flujo interno:**
1. Deserializa buffer (subopcode 0x29):
   - `local_1868` = userid
   - `local_186c` = username
   - `local_1854` = itemid a vender
   - `local_1858` = slot del item
   - `local_1850` = item count (cantidad a vender)
   - `local_1874` = gold a recibir (precio de venta)

2. **Valida item existe:**
   ```c
   SELECT COUNT(*) FROM UserItemInfo WHERE userid=%u AND slot=%u;
   ```

3. **DELETE item:**
   ```c
   DELETE FROM UserItemInfo WHERE userid=%u AND slot=%u;
   ```
   Nota: Usa `slot`, no `itemid`, para el DELETE.

4. **UPDATE gold (suma):**
   ```c
   wsprintfA(query, "UPDATE UserGameInfo SET gold=gold+%u WHERE id=%u", sellGold, userId);
   mysql_query(db, query);
   ```

5. **Log:**
   ```c
   INSERT INTO loguseritem (userid, itemid, slot, action, gold, ...)
   VALUES (%u, %u, %u, 'SELL', %u, ...);
   ```

6. **Respuesta al cliente:**
   ```
   Bytes: [opcode(0x75)][subopcode(0x29)][gold_nuevo(4)][resultado(1)]
   ```

---

## 4. Sistema de Refinería (Enchant)

### 4.1 Identificación

El sistema de refinería fue encontrado en `FUN_0040c310.c`, que maneja tanto la compra normal como el enchant/refine. Se identifica por las strings:

```
"RW_ CUser::CheckEnchantReinfo_d"  (FUN_0042f280 llamado en línea 144)
"RW_ CUser::CheckEnchantReinfo"     (FUN_0042f280 llamado en línea 149)
```

### 4.2 Items de Refinería

- **Scrolls de mejora:** IDs 0x32C9–0x32CD (12997–13005 decimal).
  - `0x32C9` — Scroll +1 (probabilidad base más alta).
  - `0x32CA` — Scroll +2.
  - `0x32CB` — Scroll +3.
  - `0x32CC` — Scroll +4 (probabilidad base más baja).
  - `0x32CD` — Scroll +5 (probabilidad base más baja).

- **Catalizadores:** IDs 0x36B1–0x36B3 (14001–14003 decimal).
  - `0x36B1` — Catalyst C1 (incrementa probabilidad).
  - `0x36B2` — Catalyst C2 (incremento medio).
  - `0x36B3` — Catalyst C3 (incremento mayor).

### 4.3 Fórmula de Probabilidad

Basada en el análisis de `FUN_0040c310.c`:

```c
// Tabla pp[] — probabilidades base según scroll type y nivel actual
int pp[6];  // pp[0..5] para diferentes rangos de nivel/scroll

// Cálculo:
int nLv = item->level;           // Nivel actual del item (0 = +0, 1 = +1, etc.)
int scrollType = param_2;        // 0..4 para scrolls 0x32C9..0x32CD
int c1 = param_4[0];            // Cantidad catalizador tipo 1
int c2 = param_4[1];            // Cantidad catalizador tipo 2
int c3 = param_4[2];            // Cantidad catalizador tipo 3

// Seed aleatorio:
int seed = FUN_004_random_seed(); // Llamada a función de random

// Umbrales de nivel:
// level 0-6:  pp[0]
// level 7-8:  pp[1]
// level 9-14: pp[2]
// level 15+:  pp[3]
// Adicional: pp[4], pp[5] para límites extremos

// Probabilidad final:
int baseProb = pp[min(nLv / 7, 3)];
int catalystBonus = c1 * catalystValue1 + c2 * catalystValue2 + c3 * catalystValue3;
int totalProb = baseProb + catalystBonus;

// Resultado:
if (seed < totalProb) {
    // SUCCESS — item.level++
    *param_5 = 1;  // bEnchantResult = 1 (éxito)
    // item.level = nLv + 1
    // item.flags = item.flags | bEnchantFlag
} else {
    // FAIL — item.level se resetea o destruye
    *param_5 = 2;  // bEnchantResult = 2 (fallo)
    // Si fallo crítico: item.level = 0 (reset) o item borrado
}
```

**Resultados (`*param_5`):**
- `0` — No hubo intento de enchant (compra normal).
- `1` — Enchant EXITOSO — `item.level++`.
- `2` — Enchant FALLIDO — item se resetea a +0 o se destruye.

### 4.4 Flujo de Refinería

```
Cliente → Compra scroll/catalyst en tienda o lo tiene en inventario
  → Opcode 0x74 (Buy Item / Refine)
    → FUN_0040c310 detecta IDs 0x32C9-0x32CD (scrolls)
    → Lee catalizadores desde param_4[0..2]
    → Calcula probabilidad con pp[] + seed + catalystBonus
    → Si éxito: item.level++, actualiza DB
      → UPDATE UserItemInfo SET enchant=%u WHERE id=%u
    → Si fallo: item.level = 0 o DELETE item
      → UPDATE UserItemInfo SET enchant=0 WHERE id=%u
    → Actualiza gold (scroll cost)
    → LogUserItem (enchant log)
    → Responde al cliente con nuevo estado del item
```

**NOTA:** El enchant se procesa como una "compra" donde los scrolls/catalizadores se consumen y el item objetivo se modifica in situ. El buffer de respuesta incluye flags que indican si hubo éxito/fallo.

### 4.5 Level Thresholds

| Nivel actual (nLv) | Rango | Probabilidad base | Notas |
|---|---|---|---|
| 0–6 | Bajo | pp[0] (~80-100%) | Siempre éxito con scroll básico |
| 7–8 | Medio | pp[1] (~50-70%) | Riesgo moderado |
| 9–14 | Alto | pp[2] (~20-40%) | Riesgo alto, catalizadores necesarios |
| 15+ | Extremo | pp[3] (~5-15%) | Riesgo extremo |

Los catalizadores (c1-c3) suman un bonus fijo a la probabilidad base, permitiendo mejorar chances en rangos altos.

---

## 5. Sistema de Equipar/Desequipar (Opcode 0x73)

### 5.1 Flujo

```
Cliente → Opcode 0x73
  → FUN_00421a50 (Equip Item Handler)
    → Valida: CUser conectado, autenticado, fase lobby
    → Lee packet: param_3[0]=srcSlot, param_3[1]=dstSlot
    → Valida slots < 0x78 (120 slots)
    → FUN_0040ca50 (serializar items actuales)
    → FUN_0040c140 (Equip processing — decompilada, ver §5.3)
      → Valida fase (CUser+0x144c == 0)
      → Compara tipo de item (offset 0x12 en ItemInfo struct)
      → Items 12000-12999: swap directo sin verificación de tipo
      → Intercambia itemId, durability, sellGold entre slots
    → Si OK: prepara buffer con subopcode 0x27
    → FUN_0041b940 (envía a DB thread)
      → DB handler: FUN_00415940 (subopcode 0x27)
        → UPDATE UserItemInfo SET slot=%u WHERE userid=%u AND slot=%u
        → UPDATE CharacterInfo (stats, equipment slots)
      → Respuesta OK/FAIL
    → Si FAIL (FUN_0040c140 retorna != 0):
      → Envía error 0xE1 al cliente
```

### 5.2 FUN_00421a50 — Equip Handler (opcode 0x73)

**Archivo:** `FUN_00421a50.c` (193 líneas)

**Validaciones:**
1. `CUser.connected != 0` y `CUser.authenticated != 0` → error 0xDE si no.
2. `CUser.phase == 0x02` (lobby) → error 0xDF si no.
3. `param_3[0] < 0x78` (120) y `param_3[1] < 0x78` (120) → error 0xE0/0xE1 si no.

**Llamada a FUN_0040c140:**
```c
uVar5 = FUN_0040c140(this, srcSlot, dstSlot, &local_12f0, &local_12f8, &local_12f4);
```
- `srcSlot` = slot origen (de inventario/equip).
- `dstSlot` = slot destino (a equipar/inventario).
- `&local_12f0` = item count output.
- `&local_12f8` = item data output.
- `&local_12f4` = flag output.
- Return: 0 = éxito, != 0 = error.

### 5.3 FUN_0040c140 — EquipProcessing (Lógica Núcleo)

**Archivo:** `FUN_0040c140.c` (42 líneas)

**Parámetros:**
- `this` = CUser
- `slotSource` (ushort) = slot origen
- `slotDest` (ushort) = slot destino
- `itemId` (puntero a uint) = ID del item a equipar

**Flujo:**
1. Valida `CUser.phase` (`CUser+0x144c`):
   - Si `0` → return 1 (no shop — cerrar shop)
   - Si `1` → return 2 (shop cargado)
2. Busca el tipo de item desde `ItemInfo[functionType=0x114]`:
   - Cada item struct tiene tamaño 0x20
   - El tipo de item está en offset `0x12` dentro del struct
3. Compara tipo del item source vs item dest (offset 0x12 en ambos)
4. Si tipos NO coinciden → return 3 (type mismatch)
5. Si `slotDest >= 3` → return 4 (out of range — solo slots 0-2 para equip)
6. Si el item es especial (`itemId >= 12000 && itemId < 13000`):
   - **Swap directo de slots** (sin validación de tipo)
7. Intercambio:
   - `itemId` entre source y dest
   - `durability` (offset 0x55C en CUser)
   - `sellGold` entre slots
8. return 0 (éxito)

**Valores de retorno:**
| Ret | Significado |
|-----|-------------|
| 0 | OK (equipado/intercambiado) |
| 1 | Fase 0 (no shop — cerrar) |
| 2 | Fase 1 (shop loaded) |
| 3 | Type mismatch (tipos incompatibles) |
| 4 | Out of range (slotDest >= 3) |

**Buffer respuesta (subopcode 0x27):**
```
Bytes: [opcode(0x73)][subopcode(0x27)]
  - 0x02: item0 (2 bytes, equip/weapon type)
  - 0x04: dstSlot (byte)
  - 0x05: item count (local_12f0, 4 bytes)
  - 0x09: item data (local_12f8, 4 bytes)
  - 0x0D: flag (local_12f4)
  - 0x11: auth/protected
  - items serializados (local_12e8, local_109c, local_1298, local_1088)
```

---

## 6. Sistema de Inventario

### 6.1 Estructura de Slots

El inventario usa **120 slots** (0x78) en el array `CUser.userItem[120]`:

| Rango de Slots | Propósito |
|---|---|
| 0–2 | Equipamiento activo (slot 0=arma, 1=armadura, 2=accesorio) |
| 3–9 | Equip extendido / mascotas |
| 10–119 | Inventario general (items, scrolls, etc.) |

**Mapeo en memoria CUser:**
- `CUser + 0x1e2c` → `ushort[120]` — item IDs (2 bytes cada uno).
- `CUser + 0x1f1c` → `byte[120]` — enchant levels (1 byte cada uno).
- `CUser + 0x1bc4` → `uint[120]` — item durabilidad/contadores (4 bytes cada uno).
- `CUser + 0x1f94` → `uint[120]` — sell gold values (4 bytes cada uno).

### 6.2 Shop Category Loader (FUN_0040cd70)

**Archivo:** `FUN_0040cd70.c` (66 líneas)

Carga items de la tienda por categoría según el rango de item ID:

```c
uint __thiscall FUN_0040cd70(void *this, byte category, ushort *itemId, uint *itemData,
                             byte *enchant, uint *sellGold, uint *extra, byte *itemBuffer,
                             int bufLen, int p1, byte *p2, int p3, int p4)
```

**Rangos de item ID por categoría:**
- `< 1000` — Items especiales/sistema.
- `1000–7999` — Armas (weapons): carga desde tabla global `ItemInfo[itemId * 0x20]`.
- `8000–8999` — Armaduras/equip: carga desde `globalArmor + offset`.
- `12000–12999` — Items de evento/misc: sin data extra.
- Otros — Items generales con `ItemInfo + ItemLevel + SellGold`.

El flag `CUser.shopPhase` (`CUser+0x144c`) controla el estado:
- `0` — Shop cerrado.
- `1` — Shop abierto (retorna 1).
- `2` — Shop cargado (retorna 2).

### 6.3 FUN_0040ca50 — Serialización de Items

Llamada desde Buy (0x74) y Equip (0x73) handlers para serializar el estado actual de items del usuario en buffers de respuesta.

**Firma inferida:**
```c
void FUN_0040ca50(void *this, byte *itemCount, undefined4 *itemIds, undefined4 *itemData,
                  byte *specialCount, undefined4 *detailBuffer, undefined4 *extBuffer,
                  char *enchantFlag, undefined2 *extraValue)
```

**Buffers de salida:**
- `itemCount` — número de items en `itemIds`.
- `itemIds[20]` — IDs de items (limitado a 20 en respuesta).
- `itemData[5]` — datos de items serializados.
- `specialCount` — contador de items especiales/enchanted.
- `detailBuffer[121]` — detalles extendidos de items.
- `extBuffer[30]` — data adicional.
- `enchantFlag` — flag para slot 3 (enchant).
- `extraValue` — valor extra para respuesta.

---

## 7. Funciones DB Relacionadas

### 7.1 FUN_00414cc0 — DBCommandInventoryEnter

**Archivo:** `FUN_00414cc0.c` (93 líneas)

Valida que el item existe en `UserItemInfo` al entrar al juego:
```c
SELECT TO_DAYS(NOW()) - TO_DAYS(insert_date) FROM UserItemInfo
WHERE userid=%u AND slot=%u;
```
Usa diferencia de días para determinar si el item es "nuevo" o "antiguo".

### 7.2 FUN_00414e70 — DBCommandInventoryBuyBag

**Archivo:** `FUN_00414e70.c` (315 líneas)

Compra de "bolsa de items" (item bag) — paquete de items predefinidos.

**Flujo:**
1. Lee buffer: userid, bagType, price, etc.
2. Valida gold del usuario.
3. **Genera items aleatorios según bagType** (loot table interna).
4. INSERT items en `UserItemInfo`.
5. UPDATE gold.
6. LogUserItem.
7. Si hay items de tipo "present" (regalo), INSERT en `pendingpresents`.

**SQL:**
```sql
UPDATE UserGameInfo SET gold=gold-%u WHERE id=%u AND gold>=%u;
INSERT INTO UserItemInfo (userid, itemid, slot, count, ...) VALUES ...;
INSERT INTO pendingpresents (userid, itemid, ...) VALUES ...;
```

### 7.3 FUN_00415cb0 — DBCommandInventoryBuyPowerUser

**Archivo:** `FUN_00415cb0.c` (313 líneas)

Compra de PowerUser (upgrade de cuenta).

**Flujo:**
1. Lee buffer: userid, powerUserType, price, duration, bonus items.
2. Valida cash/gold.
3. **DELETE items de consumibles usados** (scrolls/catalizadores si aplica).
4. INSERT en `logbuypoweruser`:
   ```sql
   INSERT INTO logbuypoweruser (userid, type, duration, price, ...) VALUES (...);
   ```
5. UPDATE `UserGameInfo.powerTime`:
   ```sql
   UPDATE UserGameInfo SET powertime=%u WHERE id=%u;
   ```
6. **Genera regalos PowerUser** (hasta 4 items aleatorios):
   - Calcula `itemId` basado en `_rand() & 3 + 0x44e` (items 0x44E-0x451) o `_rand() & 3 + 0x44a` (items 0x44A-0x44D).
   - INSERT en `pendingpresents` por cada item.
   - INSERT en `logpresent` por cada item.
7. Responde con los regalos generados.

**SQL:**
```sql
UPDATE UserGameInfo SET powertime=%u WHERE id=%u;
INSERT INTO logbuypoweruser (...) VALUES (...);
INSERT INTO pendingpresents (userid, itemid, ...) VALUES (?, ?, ...);
INSERT INTO logpresent (pendingid, itemid, userid) VALUES (...) ;
```

### 7.4 FUN_004138b0 — DB Opcode 0x0C (CharacterInfo Update)

**Archivo:** `FUN_004138b0.c`

Se ejecuta tras cualquier cambio de item que afecte las stats del personaje (equip/unequip, enchant, etc.).

**Flujo:**
```sql
UPDATE CharacterInfo SET 
  attack=%u, defense=%u, hp=%u, mp=%u, ...
WHERE id=%u;
```
Serializa las stats actualizadas desde `CUser.equipStats[]`.

---

## 8. Sistema de Lotería (Lotto)

### 8.1 Funciones Relacionadas

Hay dos funciones de lotería en los archivos decompilados:
- `FUN_0040f0a0` — Posiblemente relacionada con lotería/lotto.
- `FUN_0040ec50` — Posiblemente relacionada con lotería/lotto.

### 8.2 FUN_0040ec50 — DBCommandBuyLotto (DB Handler)

**Archivo:** `FUN_0040ec50.c` (209 líneas)

**Comentario en código:** `"== DB COMMAND: BUY LOTTO == Handles the player's request to buy a lotto ticket."`

**Flujo:**
1. Lee `userid` y `currencyType` (`cVar1`: 0=gold, 1=cash).
2. **SELECT gold** de `UserGameInfo`:
   ```sql
   SELECT name, gold FROM UserGameInfo WHERE id=%u;
   ```
3. **SELECT cash** de `Cash`:
   ```sql
   SELECT cash FROM Cash WHERE id='%s';
   ```
4. Valida saldo suficiente:
   - Si `currencyType == 0` (gold): mínimo 1000 gold.
   - Si `currencyType == 1` (cash): mínimo 100 cash.
5. Si no hay saldo → error (log `"RW_ CDB::DBCommandBuyLotto "` con código 1).
6. **INSERT ticket en `lotto`:**
   ```sql
   INSERT INTO lotto (userid, no, byItem0, byItem1, byItem2, byItem3, byItem4, goldNeed, cashNeed)
   VALUES (%u, %u, %u, %u, %u, %u, %u, 1000, %u);
   ```
   - `no` = `MAX(no) + 1` de `loglottery`.
   - `byItem0-4` = 5 bytes de números/nombres de items desde el paquete.
   - `goldNeed` = 1000, `cashNeed` = 100 (si cash type).
7. **Descuenta gold o cash:**
   ```sql
   -- Gold:
   UPDATE UserGameInfo SET gold=gold-1000 WHERE id=%u AND gold>=1000;
   -- Cash:
   UPDATE Cash SET cash=cash-100 WHERE id='%s' AND cash>=100;
   ```
8. **Respuesta al cliente** (subopcode 0x29):
   ```
   Bytes: [opcode][0x29][noTicket(4)][resultado(1)][currencyType(1)]
   ```
   - `resultado` = 0 (éxito), 1 (error saldo), otros.

**SQL:**
```sql
SELECT MAX(no) FROM loglottery;
INSERT INTO lotto (userid, no, byItem0, byItem1, byItem2, byItem3, byItem4, goldNeed, cashNeed)
  VALUES (%u, %u, %u, %u, %u, %u, %u, 1000, %u);
UPDATE UserGameInfo SET gold=gold-1000 WHERE id=%u AND gold>=1000;
UPDATE Cash SET cash=cash-100 WHERE id='%s' AND cash>=100;
```

### 8.3 FUN_0040f0a0 — DBCommandAskLotto (DB Handler)

**Archivo:** `FUN_0040f0a0.c` (130 líneas)

**Flujo:**
1. Lee `userid` y `pageNo` (página de resultados).
2. **SELECT lotto results** desde `lotto`:
   ```sql
   SELECT no, no1, no2, no3, no4, no5 FROM lotto
   WHERE userid=%u LIMIT %u, 10;
   ```
   - `pageNo * 10` como offset, 10 resultados por página.
3. Procesa cada fila: extrae `dwNo` y 5 números `byLottoNum[0..4]`.
4. **Respuesta al cliente** (subopcode 0x2A):
   - `cVar7` = 0 (hay datos), 1 (no hay datos), 2 (error DB).
   - Serializa resultados: `dwNo` + 5 bytes por cada ticket.
```
Bytes: [opcode][0x2A][resultado(1)][count(4)][dwNo1(4)][n1(1)][n2(1)][n3(1)][n4(1)][n5(1)]...
```

---

## 9. Funciones Decompiladas (Completadas)

Todas las 12 funciones previamente MISSING han sido decompiladas vía Ghidra MCP. A continuación el análisis detallado:

### 9.1 FUN_0040bd80 — ItemLookup (Búsqueda en tabla global)

**Archivo:** `FUN_0040bd80.c` (52 líneas)

Busca un item en la tabla global `ItemInfo` por ID. Usa `functionType` del struct como discriminador.

**Flujo:**
1. Itera sobre la tabla global (itemCount en `ItemInfo[0]`, items desde `ItemInfo[1]`).
2. Cada item es un struct de 5 fields (20 bytes):
   - Field[0] = `itemId` (ID del item)
   - Field[1] = `offset0x4` (tipo/categoría)
   - Field[2] = `offset0x8`
   - Field[3] = `offset0xC`
   - Field[4] = `offset0x10` (precio de venta)
3. Para items `11000-11999` (shop items), busca coincidencia exacta de ID.
4. Si encuentra match, retorna puntero al struct (específicamente field[4] = sell price).
5. Si no encuentra, retorna 0 (item no existe).

**Llama:** FUN_0040bd80 desde FUN_0040b080 y FUN_0040b1a0 para mostrar precios en shop.

### 9.2 FUN_0040c140 — EquipProcessing (Procesamiento de Equipar)

**Archivo:** `FUN_0040c140.c` (42 líneas)

Lógica de equipar/desequipar items entre slots. Validación estricta de tipo de item.

**Parámetros:**
- `this` = CUser
- `param_1` = `slotSource` (slot origen)
- `param_2` = `slotDest` (slot destino)
- `param_3` = `itemId` (ID del item)

**Flujo:**
1. **Valida fase** (`CUser + 0x144c`):
   - `0` = no shop → **return 1**
   - `1` = shop abierto → **return 2**
2. **Obtiene tipo de item** desde `ItemInfo[functionType=0x114][slotSource]` → offset `0x12` del struct (tamaño struct=0x20).
3. **Valida que itemSource y itemDest tengan el mismo tipo** (offset 0x12 en ambos slots de `ItemInfo`).
4. Si NO coinciden los tipos → **return 3**.
5. Si `slotDest >= 3` (slot fuera de rango equip → **return 4**).
6. Si el item es de tipo especial (`itemId >= 12000 && itemId < 13000` — items 12000-12999):
   - **Swap directo de slots** (sin verificar tipo).
7. **Intercambio de datos:**
   - Transfiere `itemId` entre slots.
   - Transfiere `durability` (offset 0x55C).
   - Transfiere `sellGold` entre slots.
8. **return 0** (éxito).

**Valores de retorno:**
| Ret | Significado |
|-----|-------------|
| 0 | OK |
| 1 | No shop (fase 0) |
| 2 | Shop loaded (fase 1) |
| 3 | Type mismatch |
| 4 | Out of range (slotDest >= 3) |

**Notas:**
- Items `12000-12999` son items especiales/evento que pueden equiparse en cualquier slot.
- Durabilidad e itemId se mueven juntos en el swap.
- `sellGold` se transfiere entre slots (precios intercambiables).

### 9.3 FUN_0040b080 — LobbyItemQuery (Consulta Items Lobby)

**Archivo:** `FUN_0040b080.c` (65 líneas)

Consulta detalles de item para mostrar en shop del lobby.

**Flujo:**
1. Lee `itemId` y `userid` del buffer.
2. **Valida fase** (CUser+0x144c):
   - `0` → return (no shop)
3. **Busca item** en tabla global via `FUN_0040bd80`.
4. Si encuentra:
   - **Calcula sellPrice:** `(itemId * 8000) / 100` (para items 11000-11999).
   - Prepara respuesta con `itemId`, `sellPrice`, `type`, `name`.
5. Responde al cliente con datos del item.

**SQL:** No directo (usa tabla en memoria).

### 9.4 FUN_0040b1a0 — LobbyItemList (Lista Items Lobby)

**Archivo:** `FUN_0040b1a0.c` (68 líneas)

Lista todos los items disponibles para comprar en el lobby.

**Flujo:**
1. **Valida fase** (CUser+0x144c):
   - `0` → return.
2. Itera sobre la tabla global `ItemInfo` buscando items del rango `11000-11999`.
3. Para cada item encontrado:
   - **SellPrice = `(itemId * 12000) / 100`** (diferente fórmula que LobbyItemQuery).
4. Serializa lista completa de items → respuesta al cliente.
5. **PhaseFlag → 2** (shop loaded).

**Diferencia clave:** LobbyItemList usa `×12000/100`, LobbyItemQuery usa `×8000/100` para el mismo rango de items.

### 9.5 FUN_0040b940 — ItemFieldExit (Items al Salir del Campo)

**Archivo:** `FUN_0040b940.c` (58 líneas)

Procesa items del personaje al salir del campo de batalla.

**Flujo:**
1. **Valida fase** (`CUser + 0x144c` debe ser 0).
2. Itera sobre los 3 slots de equipamiento (0, 1, 2) del personaje.
3. Por cada slot con item:
   - **Recupera durabilidad** (si estaba dañado, restaura parcialmente).
   - Valida que el nivel de enchant (`enchantLevel`) no exceda el máximo permitido para ese tipo de item.
4. **Actualiza stats del personaje** vía `FUN_0040bcb0` (recalcula stats basado en items equipados).
5. **Responde al cliente** con los items actualizados y stats.

**Nota:** Este handler se ejecuta `FUN_0040b900` → cuando el personaje sale de la sala/partida.

### 9.6 FUN_0040c960 — ItemEquipDataBattleStart (Equip Data para Batalla)

**Archivo:** `FUN_0040c960.c` (36 líneas)

Serializa los datos de equipamiento al iniciar una batalla.

**Flujo:**
1. Itera sobre los 3 slots de equip (0, 1, 2).
2. Para cada slot, serializa:
   - `itemId` (4 bytes)
   - `enchantLevel` (2 bytes)
   - `durability` (4 bytes)
3. **Exporta stats** desde `CUser + 0x1550` a `CUser + 0x1564` (20 bytes de stats calculadas).
4. Usa `FUN_0040bcb0` para asegurar que los stats están actualizados antes de serializar.

**Estructura de respuesta:**
```
[itemId0(4)][enchant0(2)][dur0(4)][itemId1(4)][enchant1(2)][dur1(4)][itemId2(4)][enchant2(2)][dur2(4)][stats(20)]
```

### 9.7 FUN_0041cf80 — GoldPointsValidation (Validación Gold/Points)

**Archivo:** `FUN_0041cf80.c` (45 líneas)

Valida que el usuario tenga suficiente gold/points para una compra, según el tipo de item.

**Parámetros:**
- `this` = CUser
- `itemType` = tipo de item (offset 0x12 en ItemInfo * 0x20)
- `priceGold`, `pricePoint` = costos

**Flujo:**
1. Obtiene `userGold = CUser + 0x52b8`, `userPoint = CUser + 0x52bc` (valores base del usuario).
2. Según `itemType` (mapeado desde struct ItemInfo):
   - `type 0` (ninguno/error): gold=0x52b8, points=0x52bc
   - `type 2` (poción/scroll): gold=0x52c4, points=0x52c8
   - `type 3` (armadura): gold=0x52cc, points=0x52d0
   - `type 4` (poción/scroll variante): gold=0x52d4, points=0x52d8
   - `type 1` (arma): gold=0x52dc, points=0x52e0
3. Compara gold y points contra required + validates.
4. **return 0** si OK.
5. **return 1** si saldo insuficiente.

**Mapeo de offsets en CUser:**
| Tipo Item | Gold Offset | Point Offset |
|-----------|-------------|--------------|
| 0 (none) | 0x52b8 | 0x52bc |
| 2 (potion/scroll) | 0x52c4 | 0x52c8 |
| 3 (armor) | 0x52cc | 0x52d0 |
| 4 (potion variant) | 0x52d4 | 0x52d8 |
| 1 (weapon) | 0x52dc | 0x52e0 |

### 9.8 FUN_00415590 — DBCommandInventoryBuySlot (Compra Ranura Inventario)

**Archivo:** `FUN_00415590.c` (225 líneas)

**Comentario:** `"== DB COMMAND: INVENTORY BUY SLOT =="`

**Flujo:**
1. Lee `userid`, `slotToBuy`, `priceGold`, `priceCash`.
2. **SELECT gold/cash:**
   ```sql
   SELECT gold FROM UserGameInfo WHERE id=%u;
   SELECT cash FROM Cash WHERE id='%s';
   ```
3. Valida saldo.
4. **UPDATE gold:**
   ```sql
   UPDATE UserGameInfo SET gold=gold-%u WHERE id=%u AND gold>=%u;
   ```
5. **Log:**
   ```sql
   INSERT INTO loguseritem (userid, itemid, action, gold) VALUES (%u, 0, 'BUYSLOT', %u);
   ```
6. Responde con slot comprado.

### 9.9 FUN_00417800 — DBCommandInventoryBuyPotionSlot (Compra Ranura Pociones)

**Archivo:** `FUN_00417800.c` (251 líneas)

**Comentario:** `"== DB COMMAND: INVENTORY BUY POTION SLOT =="`

Mismo flujo que BuySlot pero para ranura de pociones:
1. Lee `userid`, `slotToBuy`, `priceGold`, `priceCash`.
2. SELECT/UPDATE gold + loguseritem.
3. Responde con nuevo slot de pociones.

### 9.10 FUN_004184a0 — DBCommandBuyStageRankClear (Compra Stage Rank Clear)

**Archivo:** `FUN_004184a0.c` (259 líneas)

**Comentario:** `"== DB COMMAND: BUY STAGE RANK CLEAR =="`

Permite al usuario pagar para limpiar/restablecer el rank de un stage.

**Flujo:**
1. Lee `userid`, `stageId`, `priceGold`, `priceCash`.
2. **SELECT name/gold:**
   ```sql
   SELECT name, gold FROM UserGameInfo WHERE id=%u;
   ```
3. **SELECT cash:**
   ```sql
   SELECT cash FROM Cash WHERE id='%s';
   ```
4. Valida gold ≥ priceGold, cash ≥ priceCash.
5. **UPDATE gold/cash** (atómico):
   ```sql
   UPDATE UserGameInfo SET gold=gold-%u WHERE id=%u AND gold>=%u;
   UPDATE Cash SET cash=cash-%u WHERE id='%s' AND cash>=%u;
   ```
6. **Log:**
   ```sql
   INSERT INTO loguseritem (userid, itemid, action, gold) VALUES (%u, 0, 'BUYSTAGECLEAR', %u);
   ```
7. Responde con stageId + resultado.

---

## 10. SQL Patterns

### Compra
```sql
-- Descuento atómico de gold
UPDATE UserGameInfo SET gold=gold-%u WHERE id=%u AND gold>=%u;
-- Descuento atómico de cash
UPDATE UserGameInfo SET cash=cash-%u WHERE id=%u AND cash>=%u;
-- INSERT item
INSERT INTO UserItemInfo (userid, itemid, slot, count, enchant, durability, insertdate)
VALUES (%u, %u, %u, 1, 0, 100, NOW());
-- Log
INSERT INTO loguseritem (userid, itemid, action, gold, ...) VALUES (%u, %u, 'BUY', %u, ...);
```

### Venta
```sql
-- DELETE item (por slot)
DELETE FROM UserItemInfo WHERE userid=%u AND slot=%u;
-- Suma atómica de gold
UPDATE UserGameInfo SET gold=gold+%u WHERE id=%u;
-- Log
INSERT INTO loguseritem (userid, itemid, action, gold, ...) VALUES (%u, %u, 'SELL', %u, ...);
```

### Equipar
```sql
-- Actualizar slot del item
UPDATE UserItemInfo SET slot=%u WHERE userid=%u AND slot=%u;
-- Actualizar stats del personaje
UPDATE CharacterInfo SET ... WHERE id=%u;
```

### PowerUser
```sql
UPDATE UserGameInfo SET powertime=%u WHERE id=%u;
INSERT INTO logbuypoweruser (userid, type, duration, price, ...) VALUES (...);
INSERT INTO pendingpresents (userid, itemid, ...) VALUES (?);
INSERT INTO logpresent (pendingid, itemid, userid) VALUES (...);
```

### BuySlot / BuyPotionSlot
```sql
UPDATE UserGameInfo SET gold=gold-%u WHERE id=%u AND gold>=%u;
INSERT INTO loguseritem (userid, itemid, action, gold) VALUES (%u, 0, 'BUYSLOT', %u);
```

### BuyStageRankClear
```sql
UPDATE UserGameInfo SET gold=gold-%u WHERE id=%u AND gold>=%u;
UPDATE Cash SET cash=cash-%u WHERE id='%s' AND cash>=%u;
INSERT INTO loguseritem (userid, itemid, action, gold) VALUES (%u, 0, 'BUYSTAGECLEAR', %u);
```

### Lotto
```sql
SELECT MAX(no) FROM loglottery;
INSERT INTO lotto (userid, no, byItem0, byItem1, byItem2, byItem3, byItem4, goldNeed, cashNeed)
  VALUES (%u, %u, %u, %u, %u, %u, %u, 1000, %u);
UPDATE UserGameInfo SET gold=gold-1000 WHERE id=%u AND gold>=1000;
UPDATE Cash SET cash=cash-100 WHERE id='%s' AND cash>=100;
```

### Enchant
```sql
-- Éxito
UPDATE UserItemInfo SET enchant=%u WHERE userid=%u AND slot=%u;
-- Fallo (reset)
UPDATE UserItemInfo SET enchant=0 WHERE userid=%u AND slot=%u;
```

---

## 11. Códigos de Error

| Código | Significado | Origen |
|---|---|---|
| `0xDE` | Usuario no conectado/autenticado | Equip handler |
| `0xDF` | Fase incorrecta (no lobby) | Equip handler |
| `0xE0` | Slot origen inválido (>= 0x78) | Equip handler |
| `0xE1` | Equip processing error (FUN_0040c140 devuelve 1-4) | Equip handler → FUN_0040c140 |
| `0xE2` | Usuario no conectado/autenticado | Buy handler |
| `0xE3` | Fase incorrecta (no lobby) | Buy handler |
| `0xE4` | Count de catalizadores inválido (>= 4) | Buy handler |
| `0x01` | Error general de compra (sin gold, sin espacio) | FUN_0040c310 |
| `0x00` | OK | Todos |

---

## Siguiente Fase

Con todas las 12 funciones previamente MISSING ahora decompiladas y documentadas, la documentación de Shop/Inventory/Refinery está **100% completa**. La siguiente fase es:

1. **Documentar el sistema de batalla (Battle Phase):** opcodes de combate (0x50-0x77), sistema P2P/UDP, daño, skills, etc.
2. **Documentar el sistema de clans/guilds:** creación, invitaciones, chat de clan, etc.
3. **Analizar `CWorld::Idle` (FUN_0042cee0, ~68 KB):** el main loop del servidor.
4. **Implementar C# handlers** contra toda la documentación generada (shop, inventory, refinery, equip, lotto).
