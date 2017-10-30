#include "Obj.hpp"

Obj::Obj()
{
}

Obj::Obj(float rad, int res) : _rad(rad), _res(res)
{
/*
   _vec.push_back(0.0);
   _vec.push_back(0.0);
   _vec.push_back(0.0);

   _col.push_back(0.0);
   _col.push_back(0.0);
   _col.push_back(0.0);

   for (int i = 0; i < res; i++)
   {
      _vec.push_back(rad * cos (((M_PI * 2) / res) * i)); //x
      _vec.push_back(rad * sin (((M_PI * 2) / res) * i)); //y
      _vec.push_back(0.9);  //z or whatevs

      _col.push_back(0.0); //r
      _col.push_back(0.0); //g
      _col.push_back(0.0); //b
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
*/
}

std::vector<GLfloat> Obj::get_Vec()
{
   return _vec;
}

std::vector<GLfloat> Obj::get_Col()
{
   return _col;
}

std::vector<GLint> Obj::get_Ind()
{
   return _ind;
}

std::string Obj::get_Vert()
{
   return _vert;
}

void Obj::set_Vert(std::string vert)
{
   _vert = vert;
}

