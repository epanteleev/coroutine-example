cmake_minimum_required(VERSION 3.17)
project(fiber_scope)

set(CMAKE_CXX_STANDARD 20)
enable_language(C CXX ASM_MASM)

if(UNIX)
    set(ASM_FILES asm/linux/context.S)
elseif(WIN32)
    if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
        set(ASM_FILES asm/win/context_x64.asm)
    else()
        set(ASM_FILES asm/win/context_x86.asm)
    endif()
endif()

set_property(SOURCE ${ASM_FILES} PROPERTY LANGUAGE ASM_MASM)

add_executable(fiber_scope main.cpp ${ASM_FILES} asm/context.h)