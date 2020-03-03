# Car-Tracking

<img src="data/detected_cars.gif"/>

This is the capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213)

Goal of this project is to detect and draw boundries around cars. YOLOv3 algorithm is used on coco dataset to find cars on given video input. In addition, there is inference time for each frame to observe the performance of the algorithm and confidence value is written on top of rectangle boundry. Due to standardization criteria and, this algorithm compiled on CPU.

## Dependencies for Running on Ubuntu 16.04 OS
* cmake >= 3.11.2
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux)
  * Linux: make is installed by default on most Linux distros
* OpenCV >= 4.1
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./car_tracking`.

