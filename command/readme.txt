rd /s/q debug     强制删除debug目录
rd /s/q release   强制删除release目录
::make clean      删除.o文件
qmake -project    生成工程文件pro
qmake command.pro 构建工程文件
::make debug      编译生成debug版本
::make release    编译生成release版本
make all          编译生成debug版本