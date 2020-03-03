#pragma once

#include "PreOps.h"
class DetectCar
{
public:
    DetectCar();
    ~DetectCar();

    // Get the names of the output layers
    vector<String> getOutputsNames(const Net& net);
    // Draw the predicted bounding box
    void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame);
    // Remove the bounding boxes with low confidence using non-maxima suppression
    void postprocess(Mat& frame, const vector<Mat>& outs);

private:
    const float confThreshold_;; // Confidence threshold
    const float nmsThreshold_;  // Non-maximum suppression threshold
    vector<string> classes_;
};
