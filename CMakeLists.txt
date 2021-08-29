cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME avrlang)

project(${PROJECT_NAME})

#add_subdirectory(libs/antlr)
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/third_party/antlr-runtime-4.9.2.jar)
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
include( ${PROJECT_SOURCE_DIR}/libs/antlr/cmake/ExternalAntlr4Cpp.cmake )
#set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.7-complete.jar)
include_directories(${antlr4cpp_include_dirs_antlrcpptest})


set(LIBS antlr4_static)
file(GLOB SOURCES src/*.cpp src/generated/*.cpp)

file(GLOB SOURCES "src/*.cpp" "src/generated/*.cpp" "libs/antlr/runtime/src/support/*.cpp")

include_directories( include/ src/generated libs/antlr/runtime/src )


add_executable(${PROJECT_NAME} ${SOURCES} ${antlr4cpp_src_files_antlrcpptest})
target_link_libraries(${PROJECT_NAME} ${LIBS})
#add_dependencies(${PROJECT_NAME}  antlr4cpp antlr4cpp_generation_antlrcpptest)