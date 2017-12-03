/*
Base code
Currently will make 2 FBOs and textures (only uses one in base code)
and writes out frame as a .png (Texture_output.png)

Winter 2017 - ZJW (Piddington texture write)
2017 integration with pitch and yaw camera lab (set up for texture mapping lab)
*/

#include <iostream>
#include <glad/glad.h>

#include "GLSL.h"
#include "Program.h"
#include "MatrixStack.h"
#include "Shape.h"
#include "Parts.hpp"
//#include "Fbo.h"

#include "WindowManager.h"
#include "GLTextureWriter.h"

// value_ptr for glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include "Obj.hpp"

#define MSPEED 0.02
#define VHEIGHT 1.78
#define CHEIGHT 0.7
#define DT 0.01
using namespace std;
using namespace glm;





class Application : public EventCallbacks
{

public:

	WindowManager * windowManager = nullptr;

	// Our shader program
	std::shared_ptr<Program> prog_color;
	std::shared_ptr<Program> prog_norm;
	std::shared_ptr<Program> prog_pos;
   std::shared_ptr<Program> prog_lamp;//need one program for every textured object;
  
	std::shared_ptr<Program> texProg;

	// Shape to be used (from obj file)
	shared_ptr<Shape> shape;
	// Shape to be used (from obj file)
	shared_ptr<Shape> shape2;
   shared_ptr<Obj> test;
   shared_ptr<Obj> gnd;
   std::vector<shared_ptr<Obj>> Lamp;
   std::vector<shared_ptr<Obj>> Bulb;
   std::vector<shared_ptr<Obj>> Rain;
   std::shared_ptr<Texture> texture;
   Parts particles;
	// Contains vertex information for OpenGL
	GLuint VertexArrayID;

	// Data necessary to give our triangle to OpenGL
	GLuint VertexBufferID;

	//geometry for texture render
	GLuint quad_VertexArrayID;
	GLuint quad_vertexbuffer;

	//reference to texture FBO
	GLuint frameBuf[4];
	GLuint texBuf[4];
	GLuint depthBuf;

	bool FirstTime = true;
	bool Moving = false;
	int gMat = 0;

	float cTheta = 0;
	float cPhi = 0; //new4
   float locX = 0;
   float locZ = 0;
   float locY = VHEIGHT;
   float velY = 0;

   
   float Mrot = 0;
   float Mh = 0.5;

   bool w_down = false; 
   bool a_down = false; 
   bool s_down = false; 
   bool d_down = false; 
   bool space_down = false; 
   bool shift_down = false; 
 
   float lTheta = 0;
	bool mouseDown = false;
   double MouseX, MouseY; //new4


   glm::mat4 V;
      int width, height;




	void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}

	   if (key == GLFW_KEY_M && action == GLFW_PRESS)
		{
			gMat = (gMat + 1) % 4;
		}

		if (key == GLFW_KEY_W)  //N1		
      {
         if (action == GLFW_PRESS ||action == 2)
            w_down = true;
         else  
            w_down = false;
		} 
		if (key == GLFW_KEY_A) //N1
	   {	
         if (action == GLFW_PRESS ||action == 2)
            a_down = true;
         else  
            a_down = false;
		}
		if (key == GLFW_KEY_S) //N1
		{
         if (action == GLFW_PRESS ||action == 2)
            s_down = true;
         else  
            s_down = false;
		}
		if (key == GLFW_KEY_D) //N1
		{
         if (action == GLFW_PRESS ||action == 2)
            d_down = true;
         else  
            d_down = false;
		}
		if (key == GLFW_KEY_SPACE) //N1
		{
         if (action == GLFW_PRESS ||action == 2)
            space_down = true;
         else  
            space_down = false;
		}
		if (key == GLFW_KEY_Z) //N1
		{
         if (action == GLFW_PRESS ||action == 2)
            shift_down = true;
         else  
            shift_down = false;
		}
		if (key == GLFW_KEY_R) //N1
		{
         if (action == GLFW_PRESS ||action == 2)
            Mrot += 0.01;
            
		}
		if (key == GLFW_KEY_U) //N1
		{
         if (action == GLFW_PRESS ||action == 2)
            Mh += 0.01;
            
		}


     // if (shift_down)
      //{
      //   locY -= MSPEED;
     // }
	}

	void scrollCallback(GLFWwindow* window, double deltaX, double deltaY)
	{
		cTheta += (float) deltaX;
	}

	void mouseCallback(GLFWwindow *window, int button, int action, int mods)
	{
		double posX, posY;

		if (action == GLFW_PRESS)
		{
			mouseDown = true;
			glfwGetCursorPos(window, &posX, &posY);
			cout << "Pos X " << posX << " Pos Y " << posY << endl;
			Moving = true;
		}

		if (action == GLFW_RELEASE)
		{
			Moving = false;
			mouseDown = false;
		}
      
	}

   void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos) //new3
   {
      //std::cout << xpos << " " << ypos << "\n";
      MouseX += xpos - MouseX; //new4
      MouseY += -ypos - MouseY; //new4
    
   }


	void resizeCallback(GLFWwindow *window, int width, int height) 
	{
		glViewport(0, 0, width, height);
      createFBO(frameBuf[0], texBuf[0]);
      createFBO(frameBuf[1], texBuf[1]);
      createFBO(frameBuf[2], texBuf[2]);
	}



   /**** geometry set up for a quad *****/
   void initQuad()
   {
      //now set up a simple quad for rendering FBO
      glGenVertexArrays(1, &quad_VertexArrayID);
      glBindVertexArray(quad_VertexArrayID);

      static const GLfloat g_quad_vertex_buffer_data[] =
      {
         -1.0f, -1.0f, 0.0f,
          1.0f, -1.0f, 0.0f,
         -1.0f,  1.0f, 0.0f,
         -1.0f,  1.0f, 0.0f,
          1.0f, -1.0f, 0.0f,
          1.0f,  1.0f, 0.0f,
      };

      glGenBuffers(1, &quad_vertexbuffer);
      glBindBuffer(GL_ARRAY_BUFFER, quad_vertexbuffer);
      glBufferData(GL_ARRAY_BUFFER, sizeof(g_quad_vertex_buffer_data), g_quad_vertex_buffer_data, GL_STATIC_DRAW);
   }
   /* Helper function to create the framebuffer object and
      associated texture to write to */
   void createFBO(GLuint& fb, GLuint& tex)
   {
      //initialize FBO
      int width, height;
      glfwGetFramebufferSize(windowManager->getHandle(), &width, &height);

      //set up framebuffer
      glBindFramebuffer(GL_FRAMEBUFFER, fb);
      //set up texture
      glBindTexture(GL_TEXTURE_2D, tex);

      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

      glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex, 0);

      if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
      {
         cout << "Error setting up frame buffer - exiting" << endl;
         exit(0);
      }
   }







	void init(const std::string& resourceDirectory)
	{
		int width, height;
		glfwGetFramebufferSize(windowManager->getHandle(), 
            &width, &height);
		GLSL::checkVersion();

		cTheta = 0;
		// Set background color.
		glClearColor(.0f, .0f, .0f, 1.0f);
		// Enable z-buffer test.
		glEnable(GL_DEPTH_TEST);
      glDepthRange(0.f,65.0);

/////////////new1

      //create two frame buffer objects to toggle between
      glGenFramebuffers(3, frameBuf);//AAAA
      glGenTextures(3, texBuf); //AAAA
      glGenRenderbuffers(1, &depthBuf);
      createFBO(frameBuf[0], texBuf[0]);
      
      //set up depth necessary as rendering a mesh that needs depth test
      glBindRenderbuffer(GL_RENDERBUFFER, depthBuf);
      glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
      glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuf);

   
      //more FBO set up
      GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
      glDrawBuffers(1, DrawBuffers);

      //create another FBO so we can swap back and forth
      createFBO(frameBuf[1], texBuf[1]);
      glBindRenderbuffer(GL_RENDERBUFFER, depthBuf);
      glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
      glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuf);

      //create another FBO so we can swap back and forth
      createFBO(frameBuf[2], texBuf[2]); //AAAA
      glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
      glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuf);
      //this one doesn't need depth
         texProg = make_shared<Program>();
      texProg->setVerbose(true);
      texProg->setShaderNames(
         resourceDirectory + "/pass_vert.glsl",
         //resourceDirectory + "/tex_fragH.glsl"); //rem 5
         resourceDirectory + "/tex_frag.glsl"); //new/rem5
         //resourceDirectory + "/tex_fragF.glsl"); //new 5
      if (! texProg->init())
      {
         std::cerr << "One or more shaders failed to compile... exiting!" << std::endl;
         exit(1);
      }
      texProg->addUniform("texBuf_color");
      texProg->addUniform("texBuf_norm");
      texProg->addUniform("texBuf_pos");
      texProg->addAttribute("vertPos");
      texProg->addUniform("dir");



//endnew1



	 }








	void initGeom(const std::string& resourceDirectory)
	{  
      //std::cout <<" init Geom\n";
      test = make_shared<Obj>();
      prog_norm = init_prog("../resources/normal_vert.glsl", "../resources/normal_frag.glsl");
      prog_pos = init_prog("../resources/pos_vert.glsl", "../resources/pos_frag.glsl");
      //test->init("../resources/sphere.obj", "../resources/world.jpg", true);
      test->init("../resources/sphere.obj");
      prog_color = test->get_prog();
      test->set_scale(glm::vec3(2.0,2.0,2.0));
      test->set_pos(glm::vec3(4.f,10.f,4.f));
      test->set_color(0);

     gnd = make_shared<Obj>();
      gnd->init("../resources/cube.obj", "../resources/stromsky.jpg", true);
//      gnd->init("../resources/cube.obj");
      gnd->set_scale(glm::vec3(50,30,50));
      gnd->set_color(1);
      gnd->set_pos(glm::vec3(0,0,0));

      gnd->set_zero();
      test->set_zero();

      std::shared_ptr<Obj> lmp, blb, rn;

      lmp = make_shared<Obj>();
      lmp->init("../resources/lamp.obj", "../resources/crate.jpg", true);
      prog_lamp = lmp->get_prog();
      for (int i = 0; i < 4; i++)
      {
         lmp = make_shared<Obj>();
         lmp->init("../resources/lamp.obj", "../resources/crate.jpg", true, prog_lamp);
//         lmp->set_prog(prog_color);
//         lmp->init("../resources/lamp.obj");
         lmp->set_scale(glm::vec3(4,2.2,4));
         lmp->set_pos(glm::vec3(0,20,i * 2.f));
         lmp->set_color(5);
         lmp->set_zero();
         //lmp->set_light(glm::vec3(0.2f,0.1f,0.006f));
         
         Lamp.push_back(lmp);

         blb = make_shared<Obj>();
         blb->init("../resources/sphere.obj", prog_color);
         blb->set_scale(glm::vec3(0.18,0.26,0.18));
         blb->set_pos(glm::vec3(0.7,2.9,i * 2.f));
         blb->set_color(4);
         blb->set_zero();
         blb->set_force(glm::vec3(0.f,0.f,0.f));
         if (i % 2)
           blb->set_light(glm::vec3(0.2f,0.1f,0.006f));
         else 
            blb->set_light(glm::vec3(0.4f,0.3f,0.06f));
         Bulb.push_back(blb);
         
      }
      particles.init(windowManager);
      particles.initGeom();
      particles.initTex();
      particles.initParticles();
      particles.initGeom();

      initQuad();
	}


   void move()
   {
      if (w_down)
      {
	      locX += cos(cTheta) * MSPEED;
         locZ += sin(cTheta) * MSPEED;
      }
      if (a_down)
      {
	      locZ -= cos(cTheta) * MSPEED;
         locX += sin(cTheta) * MSPEED;
      }
      if (s_down)
      {
	      locX -= cos(cTheta) * MSPEED;
         locZ -= sin(cTheta) * MSPEED;
      }
      if (d_down)
      {
	      locZ += cos(cTheta) * MSPEED;
         locX -= sin(cTheta) * MSPEED;
      }
      if (space_down && locY <= VHEIGHT + 0.01)
      {
        velY += MSPEED * 10;
      }
      if (locY >= VHEIGHT + 0.01)
      {
         velY -= 1.f * DT;
      }
      if (locY < VHEIGHT + 0.01  && velY < 0)
      {
         velY = 0;
      }
      locY += velY;
      
     
      if (shift_down && locY >= CHEIGHT)
      {
         locY -= MSPEED;
      }
      if (locY < VHEIGHT && !shift_down)
      {
         locY += (VHEIGHT - locY) * DT;
      }
   }

   // with the prior scene image - next lab we will process
   void ProcessImage(GLuint inTex)//, GLuint inTex2)
   {
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, inTex);
     // glActiveTexture(GL_TEXTURE1);
     // glBindTexture(GL_TEXTURE_2D, inTex2);

      // example applying of 'drawing' the FBO texture - change shaders
      texProg->bind();
      glUniform1i(texProg->getUniform("texBuf_color"), 0);
      glUniform1i(texProg->getUniform("texBuf_norm"), 1);//AAAA
      glUniform1i(texProg->getUniform("texBuf_pos"), 2);//AAAA
//      glUniform1i(texProg->getUniform("texBuf"), 2);
      glUniform2f(texProg->getUniform("dir"), -1, 0);
      glEnableVertexAttribArray(0);
      glBindBuffer(GL_ARRAY_BUFFER, quad_vertexbuffer);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);
      glDrawArrays(GL_TRIANGLES, 0, 6);
      glDisableVertexAttribArray(0);
      texProg->unbind();
   }





   // with the prior scene image - next lab we will process
   void ProcessImage(GLuint tex_color, GLuint tex_norm, GLuint tex_pos)
   {
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, tex_color);
      glActiveTexture(GL_TEXTURE1);
      glBindTexture(GL_TEXTURE_2D, tex_norm);
      glActiveTexture(GL_TEXTURE2);
      glBindTexture(GL_TEXTURE_2D, tex_pos);

      // example applying of 'drawing' the FBO texture - change shaders
      texProg->bind();
      glUniform1i(texProg->getUniform("texBuf_color"), 0);
      glUniform1i(texProg->getUniform("texBuf_norm"), 1);//AAAA
      glUniform1i(texProg->getUniform("texBuf_pos"), 2);//AAAA
//      glUniform1i(texProg->getUniform("texBuf"), 2);
      glUniform2f(texProg->getUniform("dir"), -1, 0);
      glEnableVertexAttribArray(0);
      glBindBuffer(GL_ARRAY_BUFFER, quad_vertexbuffer);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);
      glDrawArrays(GL_TRIANGLES, 0, 6);
      glDisableVertexAttribArray(0);
      texProg->unbind();
   }

   
   void draw()
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      //Use the matrix stack for Lab 6
      float aspect = width/(float)height;

      auto P = make_shared<MatrixStack>();

      glm::vec3 LP = glm::vec3(locX, locY, locZ);
      V = glm::lookAt(glm::vec3(locX,locY,locZ), 
            glm::vec3(cos(cPhi)*cos(cTheta)+locX,sin(cPhi) + locY,
            cos(cPhi)*sin(cTheta) + locZ), glm::vec3(0,1,0));   

      // Apply perspective projection.
      P->pushMatrix();
      //P->perspective(45.0f, aspect, 0.01f, 100.0f);
      P->perspective(45.0f, aspect, 0.01f, 100.0f);

      test->set_prog(prog_color);
      test->set_lights(Bulb);
      gnd->set_prog(prog_color);
      gnd->set_lights(Bulb);
      //gnd->print_lights();

      test->draw(P->topMatrix(), V, LP);

      gnd->draw(P->topMatrix(), V, LP);


      for (int i = 0; i < 4; i++)
      {
         Lamp.at(i)->set_prog(prog_lamp);
         Bulb.at(i)->set_prog(prog_color);

         Lamp.at(i)->set_lights(Bulb);
         Bulb.at(i)->set_lights(Bulb);

         Lamp.at(i)->draw(P->topMatrix(), V, LP);
         Bulb.at(i)->draw(P->topMatrix(), V, LP);
         
      }

      particles.draw(glm::mat4(1.f),P,V);
   }

   void draw(std::shared_ptr<Program> prog)
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      //Use the matrix stack for Lab 6
      float aspect = width/(float)height;

      auto P = make_shared<MatrixStack>();

      glm::vec3 LP = glm::vec3(locX, locY, locZ);
      V = glm::lookAt(glm::vec3(locX,locY,locZ), 
            glm::vec3(cos(cPhi)*cos(cTheta)+locX,sin(cPhi) + locY,
            cos(cPhi)*sin(cTheta) + locZ), glm::vec3(0,1,0));   

      // Apply perspective projection.
      P->pushMatrix();
      //P->perspective(45.0f, aspect, 0.01f, 100.0f);
      P->perspective(45.0f, aspect, 0.01f, 100.0f);


      test->set_prog(prog);
      //gnd->set_prog(prog_color);
      gnd->set_prog(prog);
      //gnd->print_lights();

      test->draw(P->topMatrix(), V, LP);

      gnd->draw(P->topMatrix(), V, LP);


      for (int i = 0; i < 4; i++)
      {
         Lamp.at(i)->set_prog(prog);
         Bulb.at(i)->set_prog(prog);

         Lamp.at(i)->draw(P->topMatrix(), V, LP);
         Bulb.at(i)->draw(P->topMatrix(), V, LP);
         
      }

//      particles.draw(glm::mat4(1.f),P,V);
   }

	void render()
	{
      glfwGetFramebufferSize(windowManager->getHandle(),
                              &width, &height);

    
      gnd->set_prog(prog_color);
      glBindFramebuffer(GL_FRAMEBUFFER, frameBuf[0]);
      glViewport(0, 0, width, height);
      draw();
      ProcessImage(texBuf[0]);

      /*for (int i = 0; i < 3; i ++)
      {
         
         //set up framebuffer
         glBindFramebuffer(GL_FRAMEBUFFER, frameBuf[(i+1)%2]);
         glViewport(0, 0, width, height);
         // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         //set up texture
         ProcessImage(texBuf[i%2]);
      }*/
         //set up framebuffer

      glBindFramebuffer(GL_FRAMEBUFFER, frameBuf[1]);
      glViewport(0, 0, width, height);
      draw(prog_norm);
      ProcessImage(texBuf[1]);

      
      gnd->set_prog(prog_pos);
      glBindFramebuffer(GL_FRAMEBUFFER, frameBuf[2]);
      glViewport(0, 0, width, height);
      draw(prog_pos);
      ProcessImage(texBuf[2]);
      //   glBindFramebuffer(GL_FRAMEBUFFER, frameBuf[0]);
      //   glViewport(0, 0, width, height);
         // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         //set up texture
      //   ProcessImage(texBuf[1]);

      // now draw the actual output 
         glFinish();
      glBindFramebuffer(GL_FRAMEBUFFER, 0);
      glViewport(0, 0, width, height);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      ProcessImage(texBuf[0], texBuf[1], texBuf[2]);

	}


   void update()
   {
      static float timeL = 0;
      float dtime = (float)glfwGetTime() - timeL;
      if(dtime > DT)
      {
         move(); 
         timeL = (float)glfwGetTime();
         particles.updateGeom();
         particles.updateParticles();
      }
      cTheta = (MouseX / width) * M_PI; //new4
      cPhi = (MouseY / height) * M_PI;
      if (cPhi > 1.0)
      {
         MouseY = (1.0 / M_PI) * height;
         cPhi = 1.0;
      }
      if (cPhi < -1.0)
      {
         MouseY = -(1.0 / M_PI) * height;
         cPhi = -1.0;

      }
      
   
      test->update(0.1);
      gnd->update(0.1);

      for (int i = 0; i < 4; i++)
      {
         Lamp.at(i)->update(0.1);
         Bulb.at(i)->update(0.1);
      }
   }
};

int main(int argc, char **argv)
{
	// Where the resources are loaded from
	std::string resourceDir = "../resources";
   float time;


	if (argc >= 2)
	{
			resourceDir = argv[1];
	}

	Application *application = new Application();

	// Your main will always include a similar set up to establish your window
	// and GL context, etc.

	WindowManager *windowManager = new WindowManager();
	windowManager->init(1280, 1280);
	windowManager->setEventCallbacks(application);
	application->windowManager = windowManager;

	// This is the code that will likely change program to program as you
	// may need to initialize or set up different data and state

	application->init(resourceDir);
	application->initGeom(resourceDir);

   time = (float)glfwGetTime();
	// Loop until the user closes the window.
	while (! glfwWindowShouldClose(windowManager->getHandle()))
	{
			// Render scene.
         do{
            application->update();
			   glfwPollEvents();
           // std::cout<< "update\n";
         }while (time > (float)glfwGetTime());
         
         glFinish();
			application->render();

         time = (float)glfwGetTime() + 0.1;
         //std::cout << (float)glfwGetTime() << '\n';



			// Swap front and back buffers.
			glfwSwapBuffers(windowManager->getHandle());
			// Poll for and process events.

	}

	// Quit program.
	windowManager->shutdown();
	return 0;
}
