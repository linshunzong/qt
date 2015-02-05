set QTDIR=g:\Qt\4.8.0
set PATH=g:\Qt\4.8.0\bin;g:\Qt\MinGw\bin;c:\Windows\System32
set QMAKESPEC=win32-g++
qmake -project
qmake *.pro
::make debug
::make release
make all
