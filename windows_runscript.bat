cd prog1lib/lib/
make
cd..
cd..
@echo ">> prog1lib successfully compiled!"
set PFAD="%cd%\adventure.exe"
IF EXIST %PFAD% DEL /F %PFAD%
make adventure && adventure.exe
exit