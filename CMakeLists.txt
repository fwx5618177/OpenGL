# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (AircraftWar)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

include_directories(/usr/local/Cellar/glfw/3.3.4/include) #添加头文件目径
link_directories(/usr/local/Cellar/glfw/3.3.4/lib) #添加链接库路径
include_directories(/usr/local/Cellar/glad/include) #添加头文件
include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)

# 指定生成目标
set(SOURCE main.cc include/glad.c)

# 非静态库
add_executable(${PROJECT_NAME} ${SOURCE} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} libglfw.dylib)

# 静态库
# add_executable(${PROJECT_NAME} ${SOURCE} ${SRC_LIST})
# set(LIBLISTS serial_t)
# target_link_libraries(${PROJECT_NAME} ${LIBLISTS})


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 调试信息
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")

