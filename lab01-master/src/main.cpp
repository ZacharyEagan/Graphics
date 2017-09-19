#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Image.h"

// This allows you to skip the `std::` in front of C++ standard library
// functions. You can also say `using std::cout` to be more selective.
// You should never do this in a header file.
using namespace std;

int main(int argc, char **argv)
{
	if(argc < 4) {
		cout << "Usage: Lab1 <out_image_name>.png width height" << endl;
		return 0;
	}
	// Output filename
	string filename(argv[1]);
	// Width of image
	int width = atoi(argv[2]);
	// Height of image
	int height = atoi(argv[3]);
	
	// Vertex 1 x-coord (e.g., 100)
	int x1 = atoi(argv[4]);
	// Vertex 1 y-coord (e.g., 100)
	int y1 = atoi(argv[5]);

	// rest of the coordinates for the triangle
	int x2 = atoi(argv[6]);
	int y2 = atoi(argv[7]);
	int x3 = atoi(argv[8]);
	int y3 = atoi(argv[9]);
	

	// Create the image. We're using a `shared_ptr`, a C++11 feature.
	auto image = make_shared<Image>(width, height);
	// Draw a rectangle
	for(int y = 10; y < 20; ++y) {
		for(int x = 20; x < 40; ++x) {
			unsigned char r = 255;
			unsigned char g = 0;
			unsigned char b = 0;
			image->setPixel(x, y, r, g, b);
		}
	}
	// Write image to file
	image->writeToFile(filename);
	return 0;
}
