// main.cpp

/*

USAGE:
clear; g++ $(pkg-config --cflags --libs opencv4) -std=c++11  main.cpp -o main; ./main

*/

// Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
//using namespace cv;

int main()
{
	cv::Mat frame;
    cv::VideoCapture cap;
    cap.open( string("../videos/bachelor1.mp4") );
    cap.set(cv::CAP_PROP_POS_FRAMES, 166);

	cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
        }
	cv::imwrite("frame_cpp.jpg", frame);

	// TODO
	// loop over n-frames
	// calculate avg HSV with cv.cvtColor(np.array(image), cv.COLOR_RGB2BGR)
	// compare curr and prev HSV values, if above threshold then save

	/* PYTHON
	#frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
	prev_mean = 0
	prev_frame = 0
	jump_cut_frames = []
	for frame_number in range(0, int(frames)):
    cap.set(1, frame_number-1)
    res, frame = cap.read()
    curr_mean = np.mean(frame, axis=(0,1,2))
    if abs(curr_mean - prev_mean) > THRESHOLD_HSV_FRAME_COMPARISON:    
        print('frame: {}, diff: {}, mean: {}'.format(frame_number, abs(curr_mean - prev_mean), curr_mean))
        cv2.imwrite('./jump_cut_images/'+str(frame_number)+'.png', frame)
        cv2.imwrite('./jump_cut_images/'+str(frame_number-1)+'.png', prev_frame)
        jump_cut_frames.append(frame_number)
    prev_mean = curr_mean
    prev_frame = frame
	print(jump_cut_frames)

	*/



}