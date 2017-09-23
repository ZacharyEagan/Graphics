#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>


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

class my_triBox
{
public:
	my_triBox(int maxX, int minX, int maxY, int minY);
	void draw(shared_ptr<Image> img);
private:
	int _t, _b, _r, _l;
};

my_triBox::my_triBox(int maxX, int minX, int maxY, int minY) : _t(maxY), _b(minY), _r(maxX), _l(minX) {}
void my_triBox::draw(shared_ptr<Image> img)
{
	for (int i = _b; i <= _t; i++)
	{
		for (int j = _l; j <= _r; j++)
		{
			img->setPixel(j, i, i % 255, j % 255, (i + j) % 255);
		}
	}
}

int main(int argc, char **argv)
{

	if(argc < 19) {
		cout << "Usage: Lab1 <out_image_name>.png width height : num = " << argc << endl;
		return 0;
	}
	// Output filename
	string filename(argv[1]);
	// Width of image
	int width = atoi(argv[2]);
	// Height of image
	int height = atoi(argv[3]);
	

	int x[3];
	int y[3];

	// Vertex 1 x-coord (e.g., 100)
	x[0] = atoi(argv[4]);
	// Vertex 1 y-coord (e.g., 100)
	y[0] = atoi(argv[5]);
	my_pixel a(x[0], y[0], atoi(argv[6]), atoi(argv[7]), atoi(argv[8]));
	
	x[1] = atoi(argv[9]);
	y[1] = atoi(argv[10]);
	my_pixel b(x[1], y[1], atoi(argv[11]), atoi(argv[12]), atoi(argv[13]));
	

	x[2] = atoi(argv[14]);
	y[2] = atoi(argv[15]);
	my_pixel c(x[2], y[2], atoi(argv[16]), atoi(argv[17]), atoi(argv[18]));
   	
	

	

	
	/*
	my_pixel a(1, 1);
	my_pixel b(50, 50);
	my_pixel c(1, 50);
	*/
	my_triangle tri(a, b, c);
	my_triBox box(*max_element(x, x + 3), *min_element(x, x + 3), *max_element(y, y + 3), *min_element(y, y + 3));


	// Create the image. We're using a `shared_ptr`, a C++11 feature.
	auto image = make_shared<Image>(width, height);


	//box.draw(image);
	tri.draw(image);
	

	// Write image to file
	image->writeToFile(filename);
	return 0;
}
