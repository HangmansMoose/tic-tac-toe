@echo off
if not exist ..\build mkdir ..\build
pushd ..\build
del *.pdb > NUL 2> NUL
echo WAITING FOR PDB > lock.tmp

set warnings_to_ignore=-wd4201 -wd4204 -wd4255 -wd4668 -wd4820 -wd4100 -wd4189 -wd4711 -wd4710 -wd4101 -wd4296 -wd4311 -wd4115 -wd4702 -wd4456 -wd4555

set debug_flags=-nologo -Zi -Wall -FC

set library_paths=/ling user32.lib gdi32.lib

cl %debug_flags% %library_paths% %warnings_to_ignore%