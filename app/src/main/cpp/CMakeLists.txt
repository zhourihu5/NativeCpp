cmake_minimum_required (VERSION 3.6.0)
project (Main)
#查找当前目录所有源文件 并将名称保存到 DIR_SRCS 变量
#不能查找子目录
aux_source_directory(. DIR_SRCS)
# 添加 child 子目录下的cmakelist
add_subdirectory(child)
add_subdirectory(test1)
add_subdirectory(spider)
add_subdirectory(day2)

# 指定生成目标
add_executable(main ${DIR_SRCS})

#NDK中已经有一部分预构建库 ndk库已经是被配置为cmake搜索路径的一部分 所以可以
#findLibrary(log-lib log)

# 添加链接库
target_link_libraries(main child test1 )


#target_link_libraries( native-lib
#        ${log-lib} )