cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME avrlang)
project(${PROJECT_NAME})

#execute_process(
#        COMMAND
#        antlr4 -Dlanguage=Cpp -o ${PROJECT_SOURCE_DIR}/src/generated/ ${PROJECT_SOURCE_DIR}/src/grammar/Avrlang.g4)
#execute_process(
#        COMMAND
#        llvm-config-12 --cxxflags
#        OUTPUT_VARIABLE LLVMCFLAGS
#)
#execute_process(
#        COMMAND
#        llvm-config-12 --ldflags --system-libs --libs
#        OUTPUT_VARIABLE LLVMLDFLAGS
#)

#set(CFLAGS ${LLVMCFLAGS})
set(CFLAGS -I/usr/lib/llvm-12/include -std=c++14 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS)
#set(LDFLAGS ${LLVMLDFLAGS})
set(LDFLAGS -L/usr/lib/llvm-12/lib)

add_compile_options( ${CFLAGS} )
add_link_options( ${LDFLAGS} )

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#add_subdirectory(libs/antlr)
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/third_party/antlr-runtime-4.9.2.jar)
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
include( ${PROJECT_SOURCE_DIR}/libs/antlr/cmake/ExternalAntlr4Cpp.cmake )
#set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.7-complete.jar)
include_directories(${antlr4cpp_include_dirs_antlrcpptest})

set(LIBS antlr4_static LLVM-12)
file(GLOB SOURCES src/*.cpp src/generated/*.cpp)

file(GLOB SOURCES "src/*.cpp" "src/generated/*.cpp" "libs/antlr/runtime/src/support/*.cpp")

include_directories( include/ src/generated libs/antlr/runtime/src )


add_executable(${PROJECT_NAME} ${SOURCES} ${antlr4cpp_src_files_antlrcpptest} src/ASTBuilder.cpp include/ASTBuilder.hpp src/ParserErrorListener.cpp include/ParserErrorListener.h src/context.cpp include/context.h include/ASTUtil.h src/ASTUtil.cpp)
target_link_libraries(${PROJECT_NAME} ${LIBS})
#add_dependencies(${PROJECT_NAME}  antlr4cpp antlr4cpp_generation_antlrcpptest)