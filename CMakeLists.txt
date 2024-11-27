cmake_minimum_required(VERSION 3.10)

# 项目名称
project(SHX_font_converter)

# 源文件
set(SOURCES
    SHX_font.cpp
    SHX_font.h
    debug.cpp
    debug.h
    main.cpp
)

# 创建可执行文件
add_executable(SHX_font_converter ${SOURCES})

if(MSVC)
    add_definitions(/MP)
    add_definitions(-D_USE_MATH_DEFINES)
endif()
