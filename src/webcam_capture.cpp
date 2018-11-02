
//opencv
#include "opencv2/opencv.hpp"

//eigen
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

//std
#include <iostream>
#include <cstdlib>



//main
int main(int argc, char *argv[])
{
    cv::VideoCapture camera; //OpenCV video capture object
    cv::Mat image; //OpenCV image object
    cv::Mat gray_image;
	  int cam_id; //camera id . Associated to device number in /dev/videoX
	  cv::Scalar_<unsigned char> px_value; //pixel value (4-element vector)
	  int user_key; //user pressed key to quit

	//check user args
	switch(argc)
	{
		case 1: //no argument provided, so try /dev/video0
			cam_id = 0;
			break;
		case 2: //an argument is provided. Get it and set cam_id
			cam_id = atoi(argv[1]);
			break;
		default:
			std::cout << "Invalid number of arguments. Call program as: webcam_capture [video_device_id]. " << std::endl;
			std::cout << "EXIT program." << std::endl;
			break;
	}

	//advertising to the user
	std::cout << "Opening video device " << cam_id << std::endl;

    //open the video stream and make sure it's opened
    if( !camera.open(cam_id) )
	{
        std::cout << "Error opening the camera. May be invalid device id. EXIT program." << std::endl;
        return -1;
    }

    //capture loop. Out of user press a key
    while(1)
	{
		//Read image and check it. Blocking call up to a new image arrives from camera.
        if(!camera.read(image))
		{
            std::cout << "No frame" << std::endl;
            cv::waitKey();
        }
        //change color pixels

        //to change the color of an image to gray
        //cv::cvtColor( image, gray_image, CV_BGR2GRAY );


        //access to a pixel
        Eigen::Vector3d px_value = image.at<Eigen::Vector3d>(image.cols/2,image.rows/2);
        unsigned char px_value_blue = px_value(0);
        unsigned char px_value_green = px_value(1);
        unsigned char px_value_red = px_value(2);
        //change pixel
        px_value(0)=0;
        px_value(1)=0;
        px_value(2)=0;

        //put the pixel into image
        //image.at<Eigen::Vector3d>(image.cols/2,image.rows/2) = px_value; //this did not change the central pixel
        //change the central pixel and its 8 neighbors
        for (int i=239; i < 242; i++ )
        {
          for (int j=1239; j < 1242; j++ )
          {
              image.at<Eigen::Vector3d>(i,j) = px_value;
          }
        }

        //show image in a window
        cv::imshow("Output Window", image);
        //cv::imshow("Output Window", gray_image);

		//Waits 30 millisecond to check if 'q' key has been pressed. If so, breaks the loop. Otherwise continues.
    	if( (unsigned char)(cv::waitKey(30) & 0xff) == 'q' ) break;
    }
}
