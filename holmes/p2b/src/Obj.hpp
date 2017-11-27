#ifndef OBJ_DEF
#define OBJ_DEF

#include <iostream>
#include <glad/glad.h>

#include <string>
#include <vector>
#include "GLSL.h"
#include <cmath>

class Obj
{
public:
   Obj();
   Obj(float rad, int res);
   std::vector<GLfloat> get_Vec();
   std::vector<GLfloat> get_Col();
   std::vector<GLint> get_Ind();
   std::string get_Vert();
   
   void set_Vert(std::string vert);  
 
   GLuint _vaID;
   GLuint _vbID;
   GLuint _vcID;
   GLuint _ibID;

protected:
   float _rad;
   int _res;

   std::vector<GLfloat> _vec;
   std::vector<GLfloat> _col;
   std::vector<GLint> _ind;
   std::string _vert;
};

#endif
