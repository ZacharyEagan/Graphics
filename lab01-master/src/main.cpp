#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Image.h"

// This allows you to skip the `std::` in front of C++ standard library
// functions. You can also say `using std::cout` to be more selective.
// You should never do this in a header file.
using namespace std;





class my_pixel
{
public:
	my_pixel(int x = 0, int y = 0, int z = 0, int r = 255, int g = 255, int b = 255);
	void draw(shared_ptr<Image> img);
private:
	int _x, _y, _z;
	int _r, _g, _b;
	
};

my_pixel::my_pixel(int x, int y, int z, int r, int g, int b) : _x(x), _y(y), _z(z), _r(r), _g(g), _b(b) {}
void my_pixel::draw(shared_ptr<Image> img)
{
	img->setPixel(_x, _y, _r, _g, _b);
}


//////////////////////////
class my_triangle
{
public:
	my_triangle(my_pixel a, my_pixel b, my_pixel c);
	void draw(shared_ptr<Image> img);
private:
	my_pixel _a, _b, _c;
};

my_triangle::my_triangle(my_pixel a, my_pixel b, my_pixel c) : _a(a), _b(b), _c(c) {}
void my_triangle::draw(shared_ptr<Image> img)
{
	_a.draw(img);
	_b.draw(img);
	_c.draw(img);
}



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
	
	my_pixel a(x1, y2);
	my_pixel b(x2, y2);
	my_pixel c(x3, y3);

	my_triangle tri(a, b, c);

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

	tri.draw(image);
	

	// Write image to file
	image->writeToFile(filename);
	return 0;
}
