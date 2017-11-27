#include "Circle.hpp"

Circle::Circle(float rad, int res, float r, float g, float b) 
{
   _vec.push_back(0.0);
   _vec.push_back(0.0);
   _vec.push_back(0.0);

   _col.push_back(1);
   _col.push_back(1);
   _col.push_back(1);

   for (int i = 0; i < res; i++)
   {
      _vec.push_back(rad * cos (((M_PI * 2) / res) * i)); //x
      _vec.push_back(rad * sin (((M_PI * 2) / res) * i)); //y
      _vec.push_back(0.9);  //z or whatevs

      _col.push_back(r); //r
      _col.push_back(g); //g
      _col.push_back(b); //b
   }

   for (int i = 1; i < res; i++)
   {
      _ind.push_back(0);
      _ind.push_back(i);
      _ind.push_back(i + 1);
   }
   _ind.push_back(0);
   _ind.push_back(res);
   _ind.push_back(1);

}

std::vector<GLfloat> Circle::get_Vec()
{
   return _vec;
}

std::vector<GLfloat> Circle::get_Col()
{
   return _col;
}

std::vector<GLint> Circle::get_Ind()
{
   return _ind;
}
