#include <iostream>
#include <glad/glad.h>

#include <vector>
#include "GLSL.h"
#include <cmath>
#include "Obj.hpp"
class Sun : public Obj
{
public:
   Sun(float rad = 1, int res = 200, float r = 0.8, float g = 0.5, float b = 0.1);
   std::vector<GLfloat> get_Vec();
   std::vector<GLfloat> get_Col();
   std::vector<GLint> get_Ind();
   
   //GLuint _vaID;
   //GLuint _vbID;
   //GLuint _vcID;
   //GLuint _ibID;

private:
   //float _rad;
   //int _res;

   //std::vector<GLfloat> _vec;
   //std::vector<GLfloat> _col;
   //std::vector<GLint> _ind; 
};
