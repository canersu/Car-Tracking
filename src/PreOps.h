#pragma once

#include <fstream>
#include <sstream>
#include <iostream>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>

using namespace cv;
using namespace dnn;
using namespace std;

class PreOps
{
public:
    PreOps();
    ~PreOps();

    Net networkLoader();
    vector<string> getLabels();
    vector<string> getLabels(string filename);
    VideoCapture readVideo();

private:
    const String inputFile_;
    const String configFile_;
    const String weightFile_;
    string target_;
    string labelFile_;
};
