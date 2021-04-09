//
//  main.cpp
//  forward
//
//  Created by 리종한 on 2021/04/07.
//  Copyright © 2021 리종한. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "transformations/geometry.hpp"

int main()
{
    cv::Mat original_image, forward_result_image, backward_result_image;
    original_image = cv::imread("cat.bmp", cv::IMREAD_GRAYSCALE);

    GeometryTransformator transformator;

    double degree = -10.0;
    transformator.SetRotateMatrix(degree);

    transformator.ForwardTransformation(original_image, forward_result_image);

    transformator.BackwardTransformation(original_image, backward_result_image);

    cv::imshow("Original Image", original_image);
    cv::imshow("Forward Result Image", forward_result_image);
    cv::imshow("Backward Result Image", backward_result_image);
    cv::waitKey(0);

    cv::imwrite("cat_forward.bmp", forward_result_image);
    cv::imwrite("cat_backward.bmp", backward_result_image);

    return 0;
}

