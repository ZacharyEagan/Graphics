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
   prog->addUniform("VP");
   prog->addUniform("nLights");
   prog->addUniform("MatAmb");
   prog->addUniform("MatDif");
   prog->addUniform("MatSpec");
   prog->addUniform("shine");
   prog->addUniform("alpha");
   prog->addUniform("LC");
   prog->addUniform("LP");
   prog->addUniform("Texture0");
   prog->addAttribute("vertPos");
   prog->addAttribute("vertNor");
   prog->addAttribute("vertTex");



   shape = std::make_shared<Shape>();
   shape->loadMesh(model);
   shape->measure();
   shape->resize();
   shape->init();
}

void Obj::init(std::string model, std::string tex, bool wrap)
{
    prog->setVerbose(true);
    prog->setShaderNames(
        "../resources/bpt_vert.glsl",
        "../resources/bpt_frag.glsl");
    if (! prog->init())
    {
      std::cerr << "One or more shaders failed to compile... exiting!" << std::endl;
      exit(1);
   }
   prog->addUniform("P");
   prog->addUniform("V");           //new1
   prog->addUniform("MV");
   prog->addUniform("VP");
   prog->addUniform("nLights");
   prog->addUniform("MatAmb");
   prog->addUniform("MatDif");
   prog->addUniform("MatSpec");
   prog->addUniform("shine");
   prog->addUniform("alpha");
   prog->addUniform("Texture0");
   prog->addUniform("LC");
   prog->addUniform("LP");
   prog->addAttribute("vertPos");
   prog->addAttribute("vertNor");
   prog->addAttribute("vertTex");


   texture = std::make_shared<Texture>();
   texture->setFilename(tex);
   texture->init();
   texture->setUnit(0.002);
   if (wrap)
      texture->setWrapModes(GL_REPEAT, GL_REPEAT);
   else
      texture->setWrapModes(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
   Tex = true;

   shape = std::make_shared<Shape>();
   shape->loadMesh(model);
   shape->measure();
   shape->resize();
   shape->init();
}
//void Obj::set_lower(gl::vec3 bound)
//void set_upper(gl::vec3 bound);
void Obj::set_color(int col)
{
   color = col;
}

void Obj::set_force(glm::vec3 f)
{
   force = f;
}
//void set_mass(double ms); 
//void Obj::set_pos(glm::vec3 ps)
//{
//   pos = ps;
//}

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
   Lpos = pos;
   Lpos.y += zero.y/4;
  
//   std::cout << pos.z << "\n";
}
void Obj::draw(glm::mat4 P, glm::mat4 V, glm::vec3 VP)
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
      
      glUniform1i(prog->getUniform("nLights"), ars);
      glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(p));
      glUniformMatrix4fv(prog->getUniform("MV"), 1, GL_FALSE,
                            value_ptr(MV->topMatrix()));
      glUniformMatrix4fv(prog->getUniform("V"), 1, GL_FALSE,
                            value_ptr(v));
      glUniform3fv(prog->getUniform("VP"), 1, value_ptr(VP));

      GLfloat lc[12] = {1.f,1.f,1.f, 1.f,1.f,1.f, 
                             1.f,1.f,1.f, 1.f,1.f,1.f} ;
      glUniform3fv(prog->getUniform("LC"), ars, &(bulbC.front()));
//      glUniform3fv(prog->getUniform("LC"), 4, lc);
    //  glUniform3f(prog->getUniform("LC"),
     //                            1.f,
      //                           1.f,
       //                          1.f);
      GLfloat lp[12] = {2.f,2.f,2.f, 2.f,2.f,2.f, 
                             2.f,2.f,2.f, 2.f,2.f,2.f} ;
      glUniform3fv(prog->getUniform("LP"), ars, &(bulbP.front()));
//      glUniform3fv(prog->getUniform("LP"), 4, lp);
      //glUniform3f(prog->getUniform("LP"), 1.f , 1.f , 1.f );

		set_mat(color);
      if (Tex)
      {
         texture->bind(prog->getUniform("Texture0"));
         glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
         glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
         glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
      }

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

void Obj::set_mat(int sel)
{
	sel %= 8;
switch (sel)
      {
      case 0: //shiny blue plastic
         glUniform3f(prog->getUniform("MatAmb"), 0.02f, 0.04f, 0.2f);
         glUniform3f(prog->getUniform("MatDif"), 0.0f, 0.16f, 0.9f);
         glUniform3f(prog->getUniform("MatSpec"), 0.14, 0.2, 0.8);
         glUniform1f(prog->getUniform("shine"), 120.0);
         glUniform1f(prog->getUniform("alpha"), -0.001);
         break;
      case 1: // flat grey
         glUniform3f(prog->getUniform("MatAmb"), 0.13f, 0.13f, 0.14f);
         glUniform3f(prog->getUniform("MatDif"), 0.3f, 0.3f, 0.4f);
         glUniform3f(prog->getUniform("MatSpec"), 0.3, 0.3, 0.4);
         glUniform1f(prog->getUniform("shine"), 4.0);
         glUniform1f(prog->getUniform("alpha"), 0.001);
         break;
      case 2: //brass
         glUniform3f(prog->getUniform("MatAmb"), 0.3294f, 0.2235f, 0.02745f);
         glUniform3f(prog->getUniform("MatDif"), 0.7804f, 0.5686f, 0.11373f);
         glUniform3f(prog->getUniform("MatSpec"), 0.9922, 0.941176, 0.80784);
         glUniform1f(prog->getUniform("shine"), 27.9);
         glUniform1f(prog->getUniform("alpha"), 0.001);
         break;
       case 3: //copper
         glUniform3f(prog->getUniform("MatAmb"), 0.1913f, 0.0735f, 0.0225f);
         glUniform3f(prog->getUniform("MatDif"), 0.7038f, 0.27048f, 0.0828f);
         glUniform3f(prog->getUniform("MatSpec"), 0.9922, 0.41176, 0.40784);
         glUniform1f(prog->getUniform("shine"), 20.9);
         glUniform1f(prog->getUniform("alpha"), 0.001);
         break;
       case 4: //gold
glUniform3f(prog->getUniform("MatAmb"), 0.7294f, 0.7235f, 0.02745f);
         glUniform3f(prog->getUniform("MatDif"), 0.7804f, 0.7686f, 0.11373f);
         glUniform3f(prog->getUniform("MatSpec"), 0.9922, 0.91176, 0.80784);
         glUniform1f(prog->getUniform("shine"), 16.9);
         glUniform1f(prog->getUniform("alpha"), -2.01);
         break;
       case 5: //steel
         glUniform3f(prog->getUniform("MatAmb"), 0.02713f, 0.0235f, 0.0225f);
         glUniform3f(prog->getUniform("MatDif"), 0.2038f, 0.127048f, 0.1228f);
         glUniform3f(prog->getUniform("MatSpec"), 0.1622, 0.11176, 0.10784);
         glUniform1f(prog->getUniform("shine"), 30.9);
         glUniform1f(prog->getUniform("alpha"), 0.001);
         break;
       case 6: //emerald
         glUniform3f(prog->getUniform("MatAmb"), 0.0215f, 0.1745f, 0.0215f);
         glUniform3f(prog->getUniform("MatDif"), 0.0568f, 0.61425f, 0.07568f);
         glUniform3f(prog->getUniform("MatSpec"), 0.0922, 0.91176, 0.00784);
         glUniform1f(prog->getUniform("shine"), 5.9);
         glUniform1f(prog->getUniform("alpha"), -0.2);
         break;
       case 7: //shiny white for test
glUniform3f(prog->getUniform("MatAmb"), 0.0f, 0.0f, 0.0f);
         glUniform3f(prog->getUniform("MatDif"), 0.0f, 0.0f, 0.0f);
         glUniform3f(prog->getUniform("MatSpec"), 0.9, 0.9, 0.9);
         glUniform1f(prog->getUniform("shine"), 30.9);
         glUniform1f(prog->getUniform("alpha"), 0.001);
         break;
      }
}


glm::vec3 Obj::get_vel()
{
   return vel;
}

glm::vec3 Obj::get_pos()
{
   return glm::vec3(MV->topMatrix() * glm::vec4(pos, 0.f));
}
glm::vec3 Obj::get_light_pos()
{
   return glm::vec3(MV->topMatrix() * glm::vec4(Lpos, 0.f));
}
glm::vec3 Obj::get_light()
{
   return light;
}
void Obj::set_light(glm::vec3 lght)
{
   light = lght;
}
void Obj::set_lights(std::vector<std::shared_ptr<Obj>> lights)
{

   double min = 0;
   double cur = 0;
   int count = 0;
   glm::vec3 lp,lc;
   bulbC.resize(ars * 3);
   bulbP.resize(ars * 3);
   bulbC.clear();
   bulbP.clear();
   
   std::vector<float> temp;

   for (int i = lights.size(); i--;)
   {
      cur = (1 / glm::length(lights.at(i)->get_light_pos() - pos)); 
      cur *= glm::length(lights.at(i)->get_light());
      if (count < ars)
      {
         temp.push_back(cur);
         lc = lights.at(i)->get_light();
         lp = lights.at(i)->get_light_pos();

         bulbC[count * 3] = lc.r;
         bulbC[count * 3 + 1] = lc.g;
         bulbC[count * 3 + 2] = lc.b;
   
         bulbP[count * 3] = lp.r;
         bulbP[count * 3 + 1] = lp.g;
         bulbP[count * 3 + 2] = lp.b;

         count++;
      }
      else
      {
         for (int j = 0; j < ars; j++)
         {
            if (temp.at(j) < cur)
            {
               temp.at(j) = cur;
               lc = lights.at(i)->get_light();
               lp = lights.at(i)->get_light_pos();

               bulbC[count * 3] = lc.r;
               bulbC[count * 3 + 1] = lc.g;
               bulbC[count * 3 + 2] = lc.b;
         
               bulbP[count * 3] = lp.r;
               bulbP[count * 3 + 1] = lp.g;
               bulbP[count * 3 + 2] = lp.b;
               break;        
            }
         }
      }


   }
   

}

void Obj::print_lights()
{
   for (int i = ars; i--; )
   {
      std::cout << "Pos of" << i << ": " << bulbP[i * 3] << " ";
      std::cout << bulbP[i * 3 + 1] << " ";
      std::cout << bulbP[i * 3 + 2] << "\n";

      std::cout << "Color of" << i << ": " <<  bulbC[i * 3] << " ";
      std::cout << bulbC[i * 3 + 1] << " ";
      std::cout << bulbC[i * 3 + 2] << "\n";
      
   }
}


void Obj::bind()
{
   prog->bind();
}   
void Obj::unbind()
{
   prog->unbind();
}  
