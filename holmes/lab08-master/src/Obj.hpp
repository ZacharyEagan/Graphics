

#include <iostream>
#include <glad/glad.h>

#include "GLSL.h"
#include "Program.h"
#include "Shape.h"
#include "MatrixStack.h"
#include "GLTextureWriter.h"

// value_ptr for glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Obj
{
private:
   std::shared_ptr<Program> prog = std::make_shared<Program>();
   std::shared_ptr<Shape> shape = std::make_shared<Shape>();
  
   std::shared_ptr<MatrixStack> MV = std::make_shared<MatrixStack>();
   int color = 0;
   
   glm::vec3 lower = glm::vec3(-10.f,0.f,-10.f);
   glm::vec3 upper = glm::vec3(10.f,10.f,10.f);
   glm::vec3 force = glm::vec3(0.f,-9.8,0.f);          
   glm::vec3 vel = glm::vec3(0.f,0.f,0.f);
   glm::vec3 pos = glm::vec3(0.f,9.f,0.f);
   glm::vec3 Lpos = glm::vec3(0.f,9.f,0.f);
   glm::vec3 zero = glm::vec3(0.f,0.f,0.f);
   glm::vec3 scl = glm::vec3(1.f,1.f,1.f);
   glm::mat4 p;
   glm::mat4 v;
   double alpha;
  
   glm::vec3 light = glm::vec3(0);
   double mass = 1.f;
   int ars = 4;
   GLfloat bulbC[12] = {0};
   GLfloat bulbP[12] = {0};
     
public:
   void init(std::string model);
   void set_lower(glm::vec3 bound);
   void set_upper(glm::vec3 bound);
   void set_color(int col);
   void set_scale(glm::vec3 scale);
   void set_force(glm::vec3 f);
   void set_mass(double ms); 
   void set_pos(glm::vec3 ps);
   void set_light(glm::vec3 lght);
   void set_lights(std::vector<std::shared_ptr<Obj>> lights);
   void print_lights();   
    
   void set_zero();
   void set_mat(int i);
   void bind();
   void unbind();

    glm::vec3 get_pos();
    glm::vec3 get_light();
    glm::vec3 get_light_pos();

   void update(double dt);
   void draw(glm::mat4 P, glm::mat4 V, glm::vec3 LP);
};
