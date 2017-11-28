/* Lab 6 base code - transforms using matrix stack built on glm
 * CPE 471 Cal Poly Z. Wood + S. Sueda + I. Dunn
 */

#include <iostream>
#include <glad/glad.h>

#include "GLSL.h"
#include "Program.h"
#include "Shape.h"
#include "MatrixStack.h"
#include "WindowManager.h"

// value_ptr for glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

class Application : public EventCallbacks
{

public:
   
	WindowManager * windowManager = nullptr;

	// Contains vertex information for OpenGL
	GLuint VertexArrayID;

	// Data necessary to give our triangle to OpenGL
	GLuint VertexBufferID;

	float sTheta;
   int Up = 0;
   int Down = 1;
   int Wave = 0;
   
   float Shuffle = 0;
   float Elb = 0;
   float Sholva = 0;
   float Rotate = 0;
  
   int mode = 1;
   int Mat = 0;
   int sig = 2;
   float Test = 0.0;
   float Lpx = -2.0;
   float Lpy = 2.0;
   float Lpz = 2.0;

   glm::vec3 Lp = glm::vec3(-2.0,2.0,2.0);
   glm::vec3 Lc = glm::vec3(1.0,1.0,1.0);

 
	void keyCallback(GLFWwindow *window, int key, int scancode,
                   int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		if (key == GLFW_KEY_X && action == GLFW_PRESS)
		{
         Wave = ~Wave;
         if (!Wave)
         {
            Up = 0;
            Down = 0;
         }
         else 
         {
            Up = 1;
            Down = 0;
         }
		}
		if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == 2))
		{
         Shuffle += 0.01;
      }
		if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == 2))
		{
         Shuffle -= 0.01;
      }
		if (key == GLFW_KEY_C && (action == GLFW_PRESS || action == 2))
		{
         Elb += 0.1;
      } else
      {
		   if (key == GLFW_KEY_C && action == 0)
           Elb = 0;
      }
		if (key == GLFW_KEY_E && (action == GLFW_PRESS || action == 2))
		{
         Sholva += 0.1;
      } else
      {
		   if (key == GLFW_KEY_E && action == 0)
           Sholva = 0;
      }
		if (key == GLFW_KEY_R && (action == GLFW_PRESS || action == 2))
		{
          Rotate += 0.01;
      } else
      {
      }
		if (key == GLFW_KEY_P && (action == GLFW_PRESS))
		{
          sig++;
          mode ++;
          mode %= 4;

          
      } else
      {
      }
		if (key == GLFW_KEY_M && (action == GLFW_PRESS))
		{
          Test+=0.1;
          Mat++;
          Mat %= 3;
          sig+=2;
      } else
      {
      }
		if (key == GLFW_KEY_Q && (action == GLFW_PRESS || action == 2))
		{
          Lpx -= 0.01;
//std::cout << "Light at: (" << Lpx << "," << Lpy << "," << Lpz << ")\n";
      } else
      {
      }
		if (key == GLFW_KEY_E && (action == GLFW_PRESS || action == 2))
		{
          Lpx += 0.01;
//std::cout << "Light at: (" << Lpx << "," << Lpy << "," << Lpz << ")\n";
      } else
      {
      }
	}

	void mouseCallback(GLFWwindow *window, int button, int action, 
                        int mods)
	{
		double posX, posY;

		if (action == GLFW_PRESS)
		{
			 glfwGetCursorPos(window, &posX, &posY);
			 cout << "Pos X " << posX <<  " Pos Y " << posY << endl;
		}
	}

	void resizeCallback(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	shared_ptr<Program> init(const std::string& resourceDirectory,
                            const std::string& shader)
	{
		GLSL::checkVersion();

		sTheta = 0;

		// Set background color.
		glClearColor(.12f, .34f, .56f, 1.0f);
		// Enable z-buffer test.
		glEnable(GL_DEPTH_TEST);


		// Initialize the GLSL program.
		shared_ptr<Program> prog = make_shared<Program>();
		prog->setVerbose(true);
		prog->setShaderNames(resourceDirectory + shader + "_vert.glsl",
                            resourceDirectory + shader + "_frag.glsl");
		prog->init();
		prog->addUniform("P");
		prog->addUniform("MV");

      prog->addUniform("LP");
      prog->addUniform("LC");

		prog->addAttribute("vertPos");
		prog->addAttribute("vertNor");


      prog->addUniform("MatAmb");
      prog->addUniform("MatDif");
      prog->addUniform("MatSpec");
      prog->addUniform("shine");

      return prog;
	}
	shared_ptr<Program> init_noMat(const std::string& resourceDirectory,
                            const std::string& shader)
	{
		GLSL::checkVersion();

		sTheta = 0;

		// Set background color.
		glClearColor(.12f, .34f, .56f, 1.0f);
		// Enable z-buffer test.
		glEnable(GL_DEPTH_TEST);


		// Initialize the GLSL program.
		shared_ptr<Program> prog = make_shared<Program>();
		prog->setVerbose(true);
		prog->setShaderNames(resourceDirectory + shader + "_vert.glsl",
                            resourceDirectory + shader + "_frag.glsl");
		prog->init();
		prog->addUniform("P");
		prog->addUniform("MV");

		prog->addAttribute("vertPos");
		prog->addAttribute("vertNor");

      return prog;
	}
   
   //materials settings function stolen from project description
  void SetMaterial(shared_ptr<Program> prog, int i) {
     switch (i) {
     case 0: // shiny blue plastic
       std::cout << "shiny blue\n";
       glUniform3f(prog->getUniform("MatAmb"), 0.02, 0.04, 0.2);
       glUniform3f(prog->getUniform("MatDif"), 0.0, 0.16, 0.9);
       glUniform3f(prog->getUniform("MatSpec"), 0.14, 0.2, 0.8);
       glUniform1f(prog->getUniform("shine"), 120.0);
       break;
     case 1: // flat grey
       std::cout << "flat grey\n";
       glUniform3f(prog->getUniform("MatAmb"), 0.13, 0.13, 0.14);
       glUniform3f(prog->getUniform("MatDif"), 0.3, 0.3, 0.4);
       glUniform3f(prog->getUniform("MatSpec"), 0.3, 0.3, 0.4);
       glUniform1f(prog->getUniform("shine"), 4.0);
       break;
     case 2: // brass
       std::cout << "brass\n";
       glUniform3f(prog->getUniform("MatAmb"), 0.3294, 0.2235, 0.02745);
       glUniform3f(prog->getUniform("MatDif"), 0.7804, 0.5686, 0.11373);
       glUniform3f(prog->getUniform("MatSpec"), 0.9922, 0.941176, 0.80784);
       glUniform1f(prog->getUniform("shine"), 27.9);
       break;
   }
   } 



	shared_ptr<Shape> initGeom(const std::string& resourceDirectory)
	{
		// Initialize mesh.
		shared_ptr<Shape> shape = make_shared<Shape>();
		shape->loadMesh(resourceDirectory + "/bunny.obj");
		//shape->loadMesh(resourceDirectory + "/sphere.obj");
		//shape->loadMesh(resourceDirectory + "/cube.obj");
		shape->resize();
		shape->init();

      return shape;
	}
/*
   void updateShader(const std::string& resourceDirectory, 
                     shared_ptr<Program> prog)
   {
      switch (mode)
      {
         case 0: prog->setShaderNames(resourceDirectory + 
                  "/simple" + "_vert.glsl", resourceDirectory + 
                  "/simple" + "_frag.glsl");
                  std::cout << "simple_frag\n";
                  break;

         case 1: prog->setShaderNames(resourceDirectory + 
                  "/rotF" + "_vert.glsl", resourceDirectory + 
                  "/rotF" + "_frag.glsl");
                  std::cout << "rotF_frag (fixed light)\n";
                  break;

         case 2: prog->setShaderNames(resourceDirectory + 
                  "/phongF" + "_vert.glsl", resourceDirectory + 
                  "/phongF" + "_frag.glsl");
                  std::cout << "phongF_frag (fixed light)\n";
                  break;
      } 
      prog->init();
      sig = 0;
   }*/
	
   void render(const std::string& resourceDirectory, 
               shared_ptr<Program> prog, shared_ptr<Shape> shape, 
               float offset, float rotate, int lfollow)
	{
		// Get current frame buffer size.
		int width, height;
		glfwGetFramebufferSize(windowManager->getHandle(), 
                              &width, &height);
		glViewport(0, 0, width, height);


		//Use the matrix stack for Lab 6
		float aspect = width/(float)height;

		// Create the matrix stacks - please leave these alone for now
		auto P = make_shared<MatrixStack>();
		auto MV = make_shared<MatrixStack>();
		// Apply perspective projection.
		P->pushMatrix();
		P->perspective(45.0f, aspect, 0.01f, 100.0f);


		// Draw a stack of cubes with indiviudal transforms
		prog->bind();
//		prog->setShaderNames(resourceDirectory + shader + "_vert.glsl", resourceDirectory + shader +"_frag.glsl");
      if (sig)
      {
         if (sig >= 2)
            SetMaterial(prog, Mat);
         sig = 0;
      }

		glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));

		// draw bottom cube
		MV->pushMatrix();
			MV->loadIdentity();
			// draw the bottom cube with these 'global transforms'
		   MV->translate(vec3(Shuffle + offset, 0, -5));
			MV->rotate(0.5 + Rotate + rotate, vec3(0, 1, 0));
			MV->scale(vec3(1, 1, 1));
			glUniformMatrix4fv(prog->getUniform("MV"), 1, GL_FALSE, 
                            value_ptr(MV->topMatrix()));
			glUniform3f(prog->getUniform("LC"), 1.0, 1.0,1.0);
			glUniform3f(prog->getUniform("LP"), Lpx,Lpy,Lpz);
			//glUniform1i(prog->getUniform("roteW"), lfollow);
			shape->draw(prog);
		MV->popMatrix();
		prog->unbind();


		// Pop matrix stacks.
		P->popMatrix();
	}
};

int main(int argc, char *argv[])
{
	// Where the resources are loaded from
	std::string resourceDir = "../resources";
	std::string shader1 = "/simple";
	std::string shader2 = "/gouraud";
	std::string shader3 = "/bp";
	std::string shader4 = "/sil";
   shared_ptr<Program> prog1, prog2, prog3, prog4, prog;// prog2;
   shared_ptr<Shape> shape1;// shape2;
	if (argc >= 2)
	{
		resourceDir = argv[1];
	}

	Application *application = new Application();

	// Your main will always include a similar set up to establish your window
	// and GL context, etc.

	WindowManager *windowManager = new WindowManager();
	windowManager->init(640, 480);
	windowManager->setEventCallbacks(application);
	application->windowManager = windowManager;

	// This is the code that will likely change program to program as you
	// may need to initialize or set up different data and state

	prog1 = application->init_noMat(resourceDir, shader1);
   prog1->setVerbose(false);
	prog2 = application->init(resourceDir, shader2);
	prog3 = application->init(resourceDir, shader3);
	prog4 = application->init_noMat(resourceDir, shader4);
   prog4->setVerbose(false);
	shape1 = application->initGeom(resourceDir);

	// Loop until the user closes the window.
	while (! glfwWindowShouldClose(windowManager->getHandle()))
	{
		// Clear framebuffer.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      //if (application->sig)
     // {
     //    application->updateShader(resourceDir, prog1);
     // }
      switch(application->mode)
      {
         case 0:
		      application->render(resourceDir, prog1, shape1, 2, 0, 2);
		      application->render(resourceDir, prog1, shape1, -2, 0.6, 2);
            break;
         case 1:
		      application->render(resourceDir, prog2, shape1, 2, 0, 2);
		      application->render(resourceDir, prog2, shape1, -2, 0.6, 2);
            break;
         case 2:
		      application->render(resourceDir, prog3, shape1, 2, 0, 2);
		      application->render(resourceDir, prog3, shape1, -2, 0.6, 2);
            break;
         case 3:
		      application->render(resourceDir, prog4, shape1, 2, 0, 2);
		      application->render(resourceDir, prog4, shape1, -2, 0.6, 2);
            break;
         default: std::cout << "ERR\n"; break;
      }
         
		// Render scene.


		// Swap front and back buffers.
		glfwSwapBuffers(windowManager->getHandle());
		// Poll for and process events.
		glfwPollEvents();
	}

	// Quit program.
	windowManager->shutdown();
	return 0;
}
