# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
aux_source_directory(. DIR_LIB_SRCS)

#非静态库
set(SERIAL ${PROJECT_SOURCE_DIR}/src/window.cc ${SRC_LIST})
set(SRC_LIST ${SERIAL} PARENT_SCOPE)

# 静态库
# add_library(serial_t ${DIR_LIB_SRCS})

