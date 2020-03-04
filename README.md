# Car-Tracking

<img src="data/detected_cars.gif"/>

This is the capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). (Rubrics can be found in data/ directory.)

Goal of this project is to detect and draw boundries around cars. YOLOv3 algorithm is used on coco dataset to find cars on given video input. In addition, there is inference time for each frame to observe the performance of the algorithm and confidence value is written on top of rectangle boundry. Due to standardization criteria and, this algorithm compiled on CPU.

PreOps class is responsible for reading input video, weights and config file and getting them to ready to process in main function. PreOps contains getLabels, readVideo and networkLoader. getLabels reads lines from file and stores the labels in a string vector. readVideo creates a VideoCapture object from video file. Lastly networkLoader reads the weight and config file and sets the pretrained neural network w.r.t weights and netwotk model in config file.

DetectCar class is responsible to perform operations on a processed video frame. These operations are seperated into methods which names are getOutputsNames, drawPred and postprocess. Output of the neural network's labels are loaded via getOutputsNames method. drawPred draws a box around detected cars and postprocess method find each object detected via dataset and stores them in a vector with coordinates if the confidence of each one is above the threshold. Last step of postprocess method is to remove all other categories except car.

In main.cpp, a loop starts with the first frame of video till the last frame. First, frame is getting ready to processed by adjusting size, resolution, scaling etc parameters, then last layer of neaural network is established to make the connection between the possible outputs and the model in config file. Then postprocess method states only cars and above the confidence threshold values. To measure performance, inference time of each frame is printed both on frame and the console.(Inference time varies with hardware architecture, in this project all operations performed on Intel® Core™ i7-6700K CPU @ 4.00GHz × 8)

## Dependencies for Running on Ubuntu 16.04 OS
* cmake >= 3.11.2
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux)
  * Linux: make is installed by default on most Linux distros
* OpenCV >= 4.1
  * The OpenCV 4.1.2 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Get the yolov3.weights bu running: `cd src && sh getweights.sh`
4. Compile: `cmake .. && make`
5. Run it: `./car_tracking`.

