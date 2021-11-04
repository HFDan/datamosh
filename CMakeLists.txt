CMAKE_MINIMUM_REQUIRED(VERSION 3.8 FATAL_ERROR)

project(datamosh "C")

add_executable(datamosh "src/datamosh/datamosh.c" "src/datamosh/utility.c" "src/datamosh/jpeg.c")
target_include_directories(datamosh PRIVATE "${CMAKE_SOURCE_DIR}/include")

if(WIN32)
	add_compile_definitions(WIN32)
endif()