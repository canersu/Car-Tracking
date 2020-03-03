cmake_minimum_required(VERSION 3.11.3)
project( car_tracking )
find_package( OpenCV 4.1 REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

file(GLOB project_SRCS src/*.cpp) #src/*.h

#add_executable( car_tracking main.cpp PreOps.cpp DetectCar.cpp)
add_executable(car_tracking ${project_SRCS})
target_link_libraries( car_tracking ${OpenCV_LIBS} )
