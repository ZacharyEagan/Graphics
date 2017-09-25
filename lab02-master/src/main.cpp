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
   void draw_fill(shared_ptr<Image> img);

   double get_area();
   double get_area_b(int x, int y);
   double get_area_c(int x, int y);
   double get_area_a(int x, int y);
   bool is_in(int x, int y);
   
private:
	my_pixel _a, _b, _c;
   int _left, _right, _top, _bottom;
};

my_triangle::my_triangle(my_pixel a, my_pixel b, my_pixel c) : _a(a), _b(b), _c(c) 
{
   vector<int> temp, aa, bb, cc;
   int x[3], y[3];


   temp = _a.get_point();
   x[0] = temp.at(0);
   y[0] = temp.at(1);

   temp = _b.get_point();
   x[1] = temp.at(0);
   y[1] = temp.at(1);
   
   temp = _c.get_point();
   x[2] = temp.at(0);
   y[2] = temp.at(1);
   
   _right = *max_element(x, x + 3);
   _left = *min_element(x, x + 3);
   _top = *max_element(y, y + 3);
   _bottom = *min_element(y, y + 3);
   cout << "right:" << _right << " left:" << _left << " top:" << _top << " bot:" << _bottom << " \n";
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
			img->setPixel(j, i, 255, 255, 255);
		}
	}
}
void my_triangle::draw_fill(shared_ptr<Image> img)
{
   vector<int> ca,cb,cc;
   double area = get_area();
   double a, b, c;
   int re,gr,bl;
   
   ca = _a.get_color();
   cb = _b.get_color();
   cc = _c.get_color();

	for (int i = _bottom; i <= _top; i++)
	{
		for (int j = _left; j <= _right; j++)
		{
         if (is_in(j,i)) 
         {
            b = get_area_b(j, i) / area;
            c = get_area_c(j, i) / area;
            a = 1 - b - c;            

            re = ca.at(0) * a + cb.at(0) * b + cc.at(0) * c;
            gr = ca.at(1) * a + cb.at(1) * b + cc.at(1) * c;
            bl = ca.at(2) * a + cb.at(2) * b + cc.at(2) * c;

            img->setPixel(j, i, re , gr, bl);
         }
		}
	}
}

double my_triangle::get_area()
{
   vector<int> a = _a.get_point();
   vector<int> c = _c.get_point();
   vector<int> b = _b.get_point();

   int acx, abx, acy, aby;

   double temp1;

   acx = c.at(0) - a.at(0);
   acy = c.at(1) - c.at(1);
   abx = b.at(0) - a.at(0);
   aby = b.at(1) - a.at(1);

   //temp1 = (acx * aby) - (abx * acy);
   temp1 = (abx * acy) - (acx * aby);

   return temp1 / 2.0;
}
/*
double my_triangle::get_area()
{
   vector<int> a = _a.get_point();
   vector<int> b = _b.get_point();
   vector<int> c = _c.get_point();

   double temp1;
   double temp2;

   temp1 = (c.at(0) - a.at(0)) * (b.at(1) - a.at(1));
   temp2 = (c.at(1) - a.at(1)) * (b.at(0) - a.at(0));

   return (temp1 + temp2) / 2.0;
}
*/

double my_triangle::get_area_b(int x, int y)
{
   vector<int> a = _a.get_point();
   vector<int> c = _c.get_point();

   int acx, apx, acy, apy;

   double temp1;

   acx = c.at(0) - a.at(0);
   acy = c.at(1) - c.at(1);
   apx = x - a.at(0);
   apy = y - a.at(1);

   //temp1 = (acx * apy) - (apx * acy);
   temp1 = (apx * acy) - (acx * apy);

   return temp1 / 2.0;
}

double my_triangle::get_area_c(int x, int y)
{
   vector<int> a = _a.get_point();
   vector<int> b = _b.get_point();
   
   int abx, apx, aby, apy;

   double temp1;
   abx = b.at(0) - a.at(0);
   aby = b.at(1) - a.at(1);
   apx = x - a.at(0);
   apy = y - a.at(1);

   //temp1 =  (apx * aby) - (apy * abx); 
   temp1 =   (apy * abx) - (apx * aby); 

   return temp1 / 2.0;
}

/*
double my_triangle::get_area_b(int x, int y)
{
   vector<int> a = _a.get_point();
   vector<int> c = _c.get_point();

   double temp1;
   double temp2;

   temp1 = (c.at(0) - a.at(0)) * (y - a.at(1));
   temp2 = (c.at(1) - a.at(1)) * (x - a.at(0));
   

   return (temp1 + temp2) / 2.0;
}

double my_triangle::get_area_c(int x, int y)
{
   vector<int> a = _a.get_point();
   vector<int> b = _b.get_point();

   double temp1;
   double temp2;

   temp1 = (x- a.at(0)) * (b.at(1) - a.at(1));
   temp2 = (y - a.at(1)) * (b.at(0) - a.at(0));

   return (temp1 + temp2) / 2.0;
}

double my_triangle::get_area_a(int x, int y)
{
   vector<int> c = _c.get_point();
   vector<int> b = _b.get_point();

   double temp1;
   double temp2;

   temp1 = 0.50 * (b.at(1) - c.at(1));
   temp1 *= (x - b.at(0));
   temp2 = 0.50 * (c.at(0) - b.at(0));
   temp2 *= (y - c.at(1));
   return temp1 + temp2;
}
*/
bool my_triangle::is_in(int x, int y)
{
   bool answer = false;
   double a,b,c, area;
   
   area = get_area();

   b = get_area_b(x,y) / area;
   c = get_area_c(x,y) / area;
   a = 1 - b - c;


   if (a > 0 && b > 0 && c > 0)
      answer = true;
   //if (a == 0 || b == 0 || c == 0)
   //   answer = true;

   return answer; 
}

/*
int my_triangle::is_inside(int x, int y)
{
   
}
*/

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

	my_pixel a(atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]));
	my_pixel b(atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), atoi(argv[12]), atoi(argv[13]));
	my_pixel c(atoi(argv[14]), atoi(argv[15]), atoi(argv[16]), atoi(argv[17]), atoi(argv[18]));
	
	my_triangle tri(a, b, c);

	// Create the image. We're using a `shared_ptr`, a C++11 feature.
	auto image = make_shared<Image>(width, height);

	//box.draw(image);
	tri.draw_box(image);
   tri.draw_fill(image);
   tri.draw(image);
   cout << "Area = " << tri.get_area() << "\n";
   cout << "trying halfway (100, 100)= " << tri.is_in(100 , 100) << " \n";

	// Write image to file
	image->writeToFile(filename);
	return 0;
}
