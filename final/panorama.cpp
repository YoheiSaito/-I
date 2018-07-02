//http://goya813.hatenablog.com/entry/2014/11/30/180002
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <vector>

int main(int argc, char* argv[])
{
	using cv::imread;
	using cv::Mat;
	using std::vector;
	using cv::imshow;
	using cv::waitKey;
	using cv::Size;
	using cv::Vec3b;

	Mat src[2];
	Mat gray[2];
	Mat result;
	if(argc != 3){
		fprintf(stderr,"usage: %s image1, image2", argv[0]);
		exit(1);
	}
	src[0] = imread(argv[1]);
	src[1] = imread(argv[2]);
	cv::cvtColor(src[0], gray[0], CV_BGR2GRAY);
	cv::cvtColor(src[1], gray[1], CV_BGR2GRAY);

	cv::SiftFeatureDetector detector(1000);
	cv::SiftDescriptorExtractor extrator;

	vector<cv::KeyPoint> keypoints[2];
	Mat descriptors[2];
	for (int i = 0; i < 2; i++){
		detector.detect(gray[i], keypoints[i]);
		extrator.compute(gray[i], keypoints[i], descriptors[i]);
	}

	vector<cv::DMatch> matches;
	cv::BruteForceMatcher< cv::L2<float> > matcher;
	matcher.match(descriptors[0], descriptors[1], matches);

	vector<cv::Vec2f> points1(matches.size());
	vector<cv::Vec2f> points2(matches.size());

	for( size_t i = 0 ; i < matches.size() ; ++i )
	{
		points1[i][0] = keypoints[0][matches[i].queryIdx].pt.x;
		points1[i][1] = keypoints[0][matches[i].queryIdx].pt.y;

		points2[i][0] = keypoints[1][matches[i].trainIdx].pt.x;
		points2[i][1] = keypoints[1][matches[i].trainIdx].pt.y;
	}


	Mat homo = cv::findHomography(points1, points2, CV_RANSAC);
	cv::warpPerspective(src[0], result, homo, Size(static_cast<int>(src[0].cols * 1.5), static_cast<int>(src[0].rows * 1.1)));
	waitKey();
	for (int y = 0; y < src[0].rows; y++){
		for (int x = 0; x < src[0].cols; x++){
			result.at<Vec3b>(y, x) = src[1].at<Vec3b>(y, x);
		}
	}

	imshow("result img", result);
	waitKey(0);

	return (0);
}
