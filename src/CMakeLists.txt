cmake_minimum_required(VERSION 3.16)
project(Rotating_Cube)

file(GLOB SRCS ".\/source_files\/*.cpp")

#find SDL2
find_package(SDL2 REQUIRED)

add_executable(rotating_cube main.cpp ${SRCS})
target_include_directories(
  rotating_cube
  PRIVATE
  "./header_files"
)

#link SDL2
target_include_directories(
  rotating_cube
  PRIVATE ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(
  rotating_cube
  PRIVATE ${SDL2_LIBRARIES}
)
