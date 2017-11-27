#include <iostream>
#include <glad/glad.h>

#include <vector>
#include "GLSL.h"
#include <cmath>

#include "Obj.hpp"
class Circle : public Obj
{
public:
   Circle(float rad, int res, float r = 0.0, float g = 0.05, float b = 0.2);
   std::vector<GLfloat> get_Vec();
   std::vector<GLfloat> get_Col();
   std::vector<GLint> get_Ind();
};
