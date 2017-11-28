#include "Obj.hpp"

void Obj::init(std::string model)
{
    prog->setVerbose(true);
    prog->setShaderNames(
        "../resources/bp_vert.glsl",
        "../resources/bp_frag.glsl");
    if (! prog->init())
    {
      std::cerr << "One or more shaders failed to compile... exiting!" << std::endl;
      exit(1);
   }
   prog->addUniform("P");
   prog->addUniform("V");           //new1
   prog->addUniform("MV");
   prog->addUniform("MatAmb");
   prog->addUniform("MatDif");
   prog->addUniform("MatSpec");
   prog->addUniform("shine");
   prog->addUniform("LC");
   prog->addUniform("LP");
   prog->addAttribute("vertPos");
   prog->addAttribute("vertNor");
   prog->addAttribute("vertTex");


   shape = std::make_shared<Shape>();
   shape->loadMesh(model);
   shape->measure();
   shape->resize();
   shape->init();
}

//void Obj::set_lower(gl::vec3 bound)
//void set_upper(gl::vec3 bound);
//void set_colort(int col);
//void set_force(gl::vec3 f);
//void set_mass(double ms); 
//void set_pos(gl::vec3 ps);

void Obj::update(double dt)
{
   vel.x += (force.x / mass) * dt;
   vel.y += (force.y / mass) * dt;
   vel.z += (force.z / mass) * dt;
   pos.x += vel.x * dt;
   pos.y += vel.y * dt;
   pos.z += vel.z * dt;
   
   if (pos.x > upper.x)
   {
      pos.x = upper.x;
      vel.x = 0;
   }
   if (pos.y > upper.y)
   {
      pos.y = upper.y;
      vel.y = 0;
   }
   if (pos.z > upper.z)
   {
      pos.z = upper.z;
      vel.z = 0;
   }

   if (pos.x < lower.x)
   {
      pos.x = lower.x;
      vel.x = 0;
   }
   if (pos.y < lower.y)
   {
      pos.y = lower.y;
      vel.y = 0;
   }
   if (pos.z < lower.z)
   {
      pos.z = lower.z;
      vel.z = 0;
   }
//   std::cout << pos.z << "\n";
}
void Obj::draw(glm::mat4 P, glm::mat4 V)
{
   p = P;
   v = V;
  // v = glm::mat4(0.f);
  // v = glm::mat4(0.f);
   prog->bind();
   MV->pushMatrix();
      MV->loadIdentity();
      MV->translate(pos);
      MV->scale(scl);
      MV->pushMatrix();
      MV->translate(zero);

      glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(p));
      glUniformMatrix4fv(prog->getUniform("MV"), 1, GL_FALSE,
                            value_ptr(MV->topMatrix()));
      glUniformMatrix4fv(prog->getUniform("V"), 1, GL_FALSE,
                            value_ptr(v));

      glUniform3f(prog->getUniform("MatAmb"), 0.13f, 0.13f, 0.14f);
      glUniform3f(prog->getUniform("MatDif"), 0.3f, 0.3f, 0.4f);
      glUniform3f(prog->getUniform("MatSpec"), 0.3, 0.3, 0.4);
      glUniform1f(prog->getUniform("shine"), 4.0);
      glUniform3f(prog->getUniform("LC"), 1.0, 1.0,1.0);
      glUniform3f(prog->getUniform("LP"), 1.0,1.0,1.0);

      shape->draw(prog);
   MV->popMatrix();
   MV->popMatrix();
   prog->unbind();
}
void Obj::set_scale(glm::vec3 scale)
{
   scl = scale;
}
void Obj::set_pos(glm::vec3 ps)
{
   pos = ps;
}
void Obj::set_zero()
{
   shape->measure();
   zero.y = -1.f * shape->min.y;
   //std::cout << shape->min.y << " " << shape->max.y << "\n";
}
void Obj::bind()
{
   prog->bind();
}   
void Obj::unbind()
{
   prog->unbind();
}  
