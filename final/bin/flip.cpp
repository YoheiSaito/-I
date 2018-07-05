#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

int main(int argc, char* argv[])
{
	using cv::imread;
	using cv::Mat;
	using std::vector;
	using cv::imshow;
	using cv::Size;
	using cv::Vec3b;

	Mat src,tmp;
	if(argc == 2){
		src = imread(argv[1]);
		cv::flip(src, tmp, -1);
		cv::imwrite(argv[1], tmp);
	}else if(argc == 3){
		src = imread(argv[1]);
		cv::flip(src, tmp, -1);
		cv::imwrite(argv[2], tmp);
	}else{
		fprintf(stderr, "Usage : %s  inImgName outImgName(Optional)\n", argv[0]);
	}
	return (0);
}
