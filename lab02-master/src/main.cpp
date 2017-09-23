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
   std::vector<int> get_point();
   std::vector<int> get_color();
private:
	int _x, _y, _z;
	int _r, _g, _b;
	
};

my_pixel::my_pixel(int x, int y, int z, int r, int g, int b) : _x(x), _y(y), _z(z), _r(r), _g(g), _b(b) 
{
}
void my_pixel::draw(shared_ptr<Image> img)
{
	img->setPixel(_x, _y, _r, _g, _b);
}
std::vector<int> my_pixel::get_point()
{
   std::vector<int> pix;
   pix.push_back(_x);
   pix.push_back(_y);
   pix.push_back(_z);
   
   return pix;
}
std::vector<int> my_pixel::get_color()
{
   std::vector<int> pix;
   pix.push_back(_r);
   pix.push_back(_g);
   pix.push_back(_b);

   return pix;
}




//////////////////////////
class my_triangle
{
public:
	my_triangle(my_pixel a, my_pixel b, my_pixel c);
	void draw(shared_ptr<Image> img);
   void draw_box(shared_ptr<Image> img);
   
private:
	my_pixel _a, _b, _c;
   int _left, _right, _top, _bottom;
};

my_triangle::my_triangle(my_pixel a, my_pixel b, my_pixel c) : _a(a), _b(b), _c(c) 
{
   vector<int> temp;
   int x[3], y[3];
   
   temp = _a.get_point();
   x[0] = temp.at(0);
   y[0] = temp.at(0);

   temp = _b.get_point();
   x[1] = temp.at(0);
   y[1] = temp.at(0);
   
   temp = _c.get_point();
   x[2] = temp.at(0);
   y[2] = temp.at(0);
   
   _right = *max_element(x, x + 3);
   _left = *min_element(x, x + 3);
   _top = *max_element(y, y + 3);
   _bottom = *min_element(y, y + 3);
}
void my_triangle::draw(shared_ptr<Image> img)
{
	_a.draw(img);
	_b.draw(img);
	_c.draw(img);
}
void my_triangle::draw_box(shared_ptr<Image> img)
{
	for (int i = _bottom; i <= _top; i++)
	{
		for (int j = _left; j <= _right; j++)
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


	// Create the image. We're using a `shared_ptr`, a C++11 feature.
	auto image = make_shared<Image>(width, height);


	//box.draw(image);
	tri.draw_box(image);
   tri.draw(image);
	

	// Write image to file
	image->writeToFile(filename);
	return 0;
}
