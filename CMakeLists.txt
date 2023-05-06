cmake_minimum_required(VERSION 3.15)

project(main)

# Add source to this project's executable.
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# list of files for which we add a copy rule
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${SOURCES})

# raylib
find_package(raylib CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# tmx
find_package(tmx CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE tmx)

#copy resources files to bin_dir path
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
    ${CMAKE_SOURCE_DIR}/resources/ ${CMAKE_BINARY_DIR}/resources
)