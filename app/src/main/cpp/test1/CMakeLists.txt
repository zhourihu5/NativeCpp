#child目录下的cmake就是：
cmake_minimum_required (VERSION 3.6.0)
#查找当前目录所有源文件 并将名称保存到 DIR_SRCS 变量
#不能查找子目录
aux_source_directory(. DIR_TEST1_SRCS)
# 生成链接库 默认生成静态库
add_library (test1 ${DIR_TEST1_SRCS})

#指定编译为静态库
#add_library (child STATIC ${DIR_LIB_SRCS})
#指定编译为动态库
#add_library (child SHARED ${DIR_LIB_SRCS})