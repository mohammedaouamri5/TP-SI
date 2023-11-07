@echo off

pushd ..
vendor\bin\premake\Windows\premake5.exe --file=premake5.lua vs2022 
popd
pause