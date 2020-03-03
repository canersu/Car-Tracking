#include "DetectCar.h"

// Initialize the parameters
int inpWidth = 416;  // Width of network's input image
int inpHeight = 416; // Height of network's input image

int main(int argc, char** argv)
{
    DetectCar d;
    PreOps p;
    // Load the network
    Net net = p.networkLoader();
    vector<string >classes = p.getLabels();
    
    Mat frame, blob;
    VideoCapture cap = p.readVideo();
    
    // Create a window
    static const string kWinName = "Deep learning object detection in OpenCV";
    namedWindow(kWinName, WINDOW_NORMAL);

    // Process frames.
    while (waitKey(1) < 0)
    {
        // get frame from the video
        cap >> frame;

        // Stop the program if reached end of video
        if (frame.empty()) {
            cout << "Done processing !!!" << endl;
            waitKey(3000);
            break;
        }
        // Create a 4D blob from a frame.
        blobFromImage(frame, blob, 1/255.0, Size(inpWidth, inpHeight), Scalar(0,0,0), true, false);
        
        //Sets the input to the network
        net.setInput(blob);
        
        // Runs the forward pass to get output of the output layers
        vector<Mat> outs;
        net.forward(outs, d.getOutputsNames(net));
        
        // Remove the bounding boxes with low confidence
        d.postprocess(frame, outs);
        
        // Put efficiency information. The function getPerfProfile returns the overall time for inference(t) and the timings for each of the layers(in layersTimes)
        vector<double> layersTimes;
        double freq = getTickFrequency() / 1000;
        double t = net.getPerfProfile(layersTimes) / freq;
        string label = format("Inference time for a frame : %.2f ms", t);
        cout << label << endl;
        putText(frame, label, Point(0, 15), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255));
        
        imshow(kWinName, frame);
        
    }
    
    cap.release();
    return 0;
}
