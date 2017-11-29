#include <iostream>
#include <algorithm>
#include <glad/glad.h>

#include "GLSL.h"
#include "Program.h"
#include "MatrixStack.h"
#include "Shape.h"
#include "Texture.h"
#include "Particle.h"
#include "WindowManager.h"

 // value_ptr for glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
 
class Parts
{
private:
std::shared_ptr<Program> prog;
std::shared_ptr<Texture> texture;
std::vector<std::shared_ptr<Particle>> particles;
WindowManager * windowManager = nullptr;
   bool keyToggles[256] = { false };

   GLfloat points[2400];
   GLfloat pointColors[3200];

   GLuint pointsbuffer;
   GLuint colorbuffer;

float t = 0.0;
float h = 0.01;
double camRot = 0.0;
glm::vec3 g = glm::vec3(0.0,-0.01f,0.0);
int numP = 600;


   // Contains vertex information for OpenGL
   GLuint VertexArrayID;


public:
   void init(WindowManager * wm);
   void initTex();
   void initParticles();
   void initGeom();
   void updateGeom();
   void updateParticles();
   void draw(std::shared_ptr<MatrixStack> MV, std::shared_ptr<MatrixStack> P, glm::mat4 V);

};
