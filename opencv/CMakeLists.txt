cmake_minimum_required(VERSION 3.0)

project(opencv-test)

# Find the OpenCV package
find_package(OpenCV REQUIRED)

# Add the executable
add_executable(polygon polygon.cpp)

# Link against the OpenCV library
target_link_libraries(polygon ${OpenCV_LIBS})
