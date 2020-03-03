#include "PreOps.h"
PreOps::PreOps():
    configFile_("../src/yolov3.cfg"), 
    weightFile_("../src/yolov3.weights"), 
    target_("cpu"),
    labelFile_("../src/coco.names"),
    inputFile_("../highway.mp4"){};
PreOps::~PreOps(){};

Net PreOps::networkLoader()
{
    Net net = readNetFromDarknet(configFile_, weightFile_);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    if(target_ == "cpu"){net.setPreferableTarget(DNN_TARGET_CPU);}
    else{net.setPreferableTarget(DNN_TARGET_CPU);}

    return net;
}

vector<string> PreOps::getLabels()
{
    vector<string> classes;
    ifstream ifs(labelFile_.c_str());
    string line;
    while (getline(ifs, line)) classes.push_back(line);
    return classes;
}

VideoCapture PreOps::readVideo()
{
    VideoCapture cap;

    try {
    // Open the video file
        ifstream ifile(inputFile_);
        if (!ifile) throw("error");
        cap.open(inputFile_);
    }
    catch(...) {
        cout << "Could not open the video stream" << endl;
    }
    return cap;
}
