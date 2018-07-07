#include <stdlib.h>

int main(int argc, char *argv[]){
	system("raspistill -t 1 -e jpg -o sample.jpg -ex antishake  -awb fluorescent -mm average -w 720 -h 480");
	exit(1);
}
