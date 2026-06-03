@echo off
title Detener servicio
color 0A
echo Deteniendo servicio...
RakionWorldServ.exe -stop
cls
echo Servicio detenido correctamente.
pause > nul
exit