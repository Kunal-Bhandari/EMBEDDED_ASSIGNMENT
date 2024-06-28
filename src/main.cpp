#include <opencv2/opencv.hpp>
#include <iostream>

// Built a utility function for displaying the resultant images one by one each separated by a user key press
void resizeAndShow(const cv::Mat &img,const cv::Size &newSize,int interpolation,const std::string &windowName){

    cv::Mat newImg;// Destination matrix to store resized image
    cv::resize(img, newImg, newSize, interpolation);
    cv::imshow(windowName, newImg);
    cv::waitKey(0);
}

//Utility function for measurement of execution time
void measurePerformance(const cv::Mat &img, const cv::Size &newSize, int interpolation, const std::string &interpolationName)
{

    cv::TickMeter tm;
    // we use the tickmeter class in open cv calculate ticks that will later on help us to find the execution time 
    //  for 1000 iterations
    cv::Mat newImg;

    tm.start();
    for (int i = 0; i < 1000;i++)
        cv::resize(img, newImg, newSize, interpolation);

    tm.stop();

    std::cout << " Time taken for 1000 iterations using " << interpolationName << " : " << tm.getTimeMilli() << "ms \n";
}


void nearest_neighbour(const cv::Mat &image,const double scaleFactor){

    //finding the new dimensions
    int new_height = static_cast<int>(image.rows * scaleFactor);
    int new_width = static_cast<int>(image.cols * scaleFactor);

    //creating the size object for initializing the newImage matrix
    cv::Size dimension(new_width, new_height);

    cv::Mat newImage(dimension, image.type(), 0.0);//initializing image matrix with zeros

    //Performing nearest neighbour interpolation
    for (int i = 0; i < dimension.height;i++){
        for (int j = 0; j < dimension.width; j++){
            
            //for each i,j in new image we will copy pixel values from the original image's nearest neigbour
            int row = static_cast<int>(std::floor(i / scaleFactor));
            int col = static_cast<int>(std::floor(j / scaleFactor));

            row = std::min(row, image.rows - 1);//keeping them in bounds of the original image
            col = std::min(col, image.cols - 1);

            newImage.at<cv::Vec3b>(i, j) = image.at<cv::Vec3b>(row, col);//pixel assignment to new matrix
        }
        
    }

    cv::imshow("Custom_nearest", newImage);
    // cv::waitKey(0);
}

void bilinear(const cv::Mat &image,const double scaleFactor){

    /************************************************************************************* OUT OF BOUNDS ERROR ON EXECUTION *********************************************************************************/

    
        // Get dimensions of the original image
    // int oldHeight = image.rows;
    // int oldWidth = image.cols;
    

    // // Calculate new dimensions
    // int newHeight = static_cast<int>(oldHeight * scaleFactor);
    // int newWidth = static_cast<int>(oldWidth * scaleFactor);

    // // Create an empty image with the desired dimensions
    // cv::Mat newImage(newHeight, newWidth, image.type(), 0.0);

    // // Perform bilinear interpolation
    // for (int i = 0; i < newHeight; ++i) {
    //     for (int j = 0; j < newWidth; ++j) {
    //         // Map the coordinates back to the original image
    //         double y = i / scaleFactor;
    //         double x = j / scaleFactor;

    //         // Calculate the coordinates for the surrounding pixels
    //         int yFloor = static_cast<int>(std::floor(y));
    //         int yCeil = std::min(oldHeight - 1, static_cast<int>(std::ceil(y)));
    //         int xFloor = static_cast<int>(std::floor(x));
    //         int xCeil = std::min(oldWidth - 1, static_cast<int>(std::ceil(x)));

    //         cv::Vec3b q;//Using a Vec3b object for 3 channel (BGR image)
            
    //         //Handling cases where the points might superimpose 
    //         if (xCeil == xFloor && yCeil == yFloor) {
    //             q = image.at<cv::Vec3b>(yFloor, xFloor);
    //         } else if (xCeil == xFloor) {
    //             cv::Vec3b q1 = image.at<cv::Vec3b>(yFloor, xFloor);
    //             cv::Vec3b q2 = image.at<cv::Vec3b>(yCeil, xFloor);
    //             q = q1 * (yCeil - y) + q2 * (y - yFloor);
    //         } else if (yCeil == yFloor) {
    //             cv::Vec3b q1 = image.at<cv::Vec3b>(yFloor, xFloor);
    //             cv::Vec3b q2 = image.at<cv::Vec3b>(yFloor, xCeil);
    //             q = q1 * (xCeil - x) + q2 * (x - xFloor);
    //         } else {
    //             //All points are distinct
    //             cv::Vec3b v1 = image.at<cv::Vec3b>(yFloor, xFloor);
    //             cv::Vec3b v2 = image.at<cv::Vec3b>(yCeil, xFloor);
    //             cv::Vec3b v3 = image.at<cv::Vec3b>(yFloor, xCeil);
    //             cv::Vec3b v4 = image.at<cv::Vec3b>(yCeil, xCeil);

    //             cv::Vec3b q1 = v1 * (xCeil - x) + v2 * (x - xFloor);
    //             cv::Vec3b q2 = v3 * (xCeil - x) + v4 * (x - xFloor);
    //             q = q1 * (yCeil - y) + q2 * (y - yFloor);
    //         }

    //         newImage.at<cv::Vec3b>(i, j) = q;
    //     }
    // }
    // cv::imshow("Custom_Bilinear", newImage);

}

void bicubic(){
    //TODO : Implement bicubic interpolation
}



int main(){
    std::string imgPath = "test.bmp";
    cv::Mat image = cv::imread(imgPath);
    
    //Getting the original size of the image
    int originalWidth = image.cols;
    int originalHeight = image.rows;

    //New dimensions
    int newHeight = originalHeight / 2;
    int newWidth = originalWidth / 2;
    //Notice that we pass width first then height to create a Size class object to be used in resize function
    cv::Size newSize(newWidth, newHeight);

    cv::imshow("Original Image", image);
    cv::waitKey(0);

    resizeAndShow(image, newSize, cv::INTER_NEAREST, "NEAREST NEIGHBOUR INTERPOLATION");
    resizeAndShow(image, newSize, cv::INTER_LINEAR, "LINEAR INTERPOLATION");
    resizeAndShow(image, newSize, cv::INTER_CUBIC, "BICUBIC INTERPOLATION");
    cv::waitKey(1);

    //Calling the measure Performance function
    measurePerformance(image, newSize, cv::INTER_NEAREST, "INTER_NEAREST");
    measurePerformance(image, newSize, cv::INTER_LINEAR, "INTER_LINEAR");
    measurePerformance(image, newSize, cv::INTER_CUBIC, "INTER_CUBIC");

    cv::TickMeter tm;
    tm.start();
    nearest_neighbour(image, 0.5);
    tm.stop();
    std::cout << "Time taken to execute custom nearest neigbour interpolation is " << tm.getTimeMilli() << " ms\n";
    
    // tm.start();
    // bilinear(image, 0.5);
    // tm.stop();
    // std::cout << "Time taken to execute custom bilinear interpolation is " << tm.getTimeMilli() << " ms\n";

    // tm.start();
    // bicubic(image, 0.5);
    // tm.stop();
    // std::cout << "Time taken to execute custom bicubic interpolation is " << tm.getTimeMilli() << " ms\n";
    cv::waitKey(0);
}

