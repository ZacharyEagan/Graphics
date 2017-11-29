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
	std::shared_ptr<Program> prog;
	std::shared_ptr<Program> texProg;

	// Shape to be used (from obj file)
	shared_ptr<Shape> shape;
	// Shape to be used (from obj file)
	shared_ptr<Shape> shape2;
   shared_ptr<Obj> test;
   shared_ptr<Obj> gnd;
   std::vector<shared_ptr<Obj>> Lamp;
   std::vector<shared_ptr<Obj>> Bulb;
	// Contains vertex information for OpenGL
	GLuint VertexArrayID;

	// Data necessary to give our triangle to OpenGL
	GLuint VertexBufferID;

	//geometry for texture render
	GLuint quad_VertexArrayID;
	GLuint quad_vertexbuffer;

	//reference to texture FBO
	GLuint frameBuf[2];
	GLuint texBuf[2];
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
      MouseY += ypos - MouseY; //new4
    
   }


	void resizeCallback(GLFWwindow *window, int width, int height) 
	{
		glViewport(0, 0, width, height);
	}

	void init(const std::string& resourceDirectory)
	{
		int width, height;
		glfwGetFramebufferSize(windowManager->getHandle(), 
            &width, &height);
		GLSL::checkVersion();

		cTheta = 0;
		// Set background color.
		glClearColor(.12f, .34f, .56f, 1.0f);
		// Enable z-buffer test.
		glEnable(GL_DEPTH_TEST);
      glDepthRange(0.f,65.0);

	 }

	void initGeom(const std::string& resourceDirectory)
	{  
      //std::cout <<" init Geom\n";
      test = make_shared<Obj>();
      test->init("../resources/sphere.obj");
      test->set_scale(glm::vec3(2.0,2.0,2.0));
      test->set_pos(glm::vec3(4.f,10.f,4.f));
      test->set_color(0);
      gnd = make_shared<Obj>();
      gnd->init("../resources/cube.obj");
      gnd->set_scale(glm::vec3(50,30,50));
      gnd->set_color(1);
      gnd->set_pos(glm::vec3(0,0,0));

      gnd->set_zero();
      test->set_zero();

      std::shared_ptr<Obj> lmp, blb;
      for (int i = 0; i < 4; i++)
      {
         lmp = make_shared<Obj>();
         lmp->init("../resources/lamp.obj");
         lmp->set_scale(glm::vec3(4,2.2,4));
         lmp->set_pos(glm::vec3(0,20,i * 2.f));
         lmp->set_color(5);
         lmp->set_zero();
         Lamp.push_back(lmp);

         blb = make_shared<Obj>();
         blb->init("../resources/sphere.obj");
         blb->set_scale(glm::vec3(0.18,0.26,0.18));
         blb->set_pos(glm::vec3(0.7,2.9,i * 2.f));
         blb->set_color(4);
         blb->set_zero();
         blb->set_force(glm::vec3(0.f,0.f,0.f));
         blb->set_light(glm::vec3(0.2f,0.1f,0.006f));
         Bulb.push_back(blb);
         
      }

      for (int i = 0; i < 4; i++)
      {

      }
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

	void render()
	{
      int width, height;
      glfwGetFramebufferSize(windowManager->getHandle(),
                              &width, &height);
      glViewport(0, 0, width, height);


      //Use the matrix stack for Lab 6
      float aspect = width/(float)height;

      // Create the matrix stacks - please leave these alone for now
      auto P = make_shared<MatrixStack>();
      auto MV = make_shared<MatrixStack>();
      glm::mat4 V;


      move(); 

      cTheta = (MouseX / width) * M_PI; //new4
      cPhi = (MouseY / height) * M_PI;
      if (cPhi > 1.39)
         MouseY = (1.39 / M_PI) * height;
      if (cPhi < -1.39)
         MouseY = -(1.39 / M_PI) * height;

      if (cPhi > (M_PI * (3.0/4.0)))
         cPhi = (M_PI * (3.0/4.0));
      if (cPhi < -(M_PI * (3.0/4.0)))
         cPhi = -(M_PI * (3.0/4.0));

      glm::vec3 LP = glm::vec3(locX, locY, locZ);
      V = glm::lookAt(glm::vec3(locX,locY,locZ), 
            glm::vec3(cos(cPhi)*cos(cTheta)+locX,sin(cPhi) + locY,
            cos(cPhi)*sin(cTheta) + locZ), glm::vec3(0,1,0));   
      std::cout << "V: ";
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            std::cout << V[i][j] << " ";
         }
         std::cout << "\n";
      } 
      std::cout << "\n\n";
      // Clear framebuffer.
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


      // Apply perspective projection.
      P->pushMatrix();
      P->perspective(45.0f, aspect, 0.01f, 100.0f);
      test->set_lights(Bulb);
      gnd->set_lights(Bulb);
      gnd->print_lights();
      test->update(0.1);
      test->draw(P->topMatrix(), V, LP);
      gnd->update(0.1);
      gnd->draw(P->topMatrix(), V, LP);

     

      for (int i = 0; i < 4; i++)
      {
         Lamp.at(i)->set_lights(Bulb);
         Bulb.at(i)->set_lights(Bulb);

         Lamp.at(i)->update(0.1);

         Lamp.at(i)->draw(P->topMatrix(), V, LP);

         Bulb.at(i)->update(0.1);
         Bulb.at(i)->draw(P->topMatrix(), V, LP);
         
      }
	}


   void updatePos()
   {
      
   }


};

int main(int argc, char **argv)
{
	// Where the resources are loaded from
	std::string resourceDir = "../resources";

	if (argc >= 2)
	{
			resourceDir = argv[1];
	}

	Application *application = new Application();

	// Your main will always include a similar set up to establish your window
	// and GL context, etc.

	WindowManager *windowManager = new WindowManager();
	windowManager->init(512, 512);
	windowManager->setEventCallbacks(application);
	application->windowManager = windowManager;

	// This is the code that will likely change program to program as you
	// may need to initialize or set up different data and state

	application->init(resourceDir);
	application->initGeom(resourceDir);

	// Loop until the user closes the window.
	while (! glfwWindowShouldClose(windowManager->getHandle()))
	{
			// Render scene.
			application->render();

			// Swap front and back buffers.
			glfwSwapBuffers(windowManager->getHandle());
			// Poll for and process events.
			glfwPollEvents();
	}

	// Quit program.
	windowManager->shutdown();
	return 0;
}
