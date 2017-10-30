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

	// Our shader program
	//std::shared_ptr<Program> prog;

	// Shape to be used (from obj file)
//	shared_ptr<Shape> shape;

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
  
   int mode = 0;
   int sig = 0;
 
	void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
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
          mode %= 3;

          
      } else
      {
      }
	}

	void mouseCallback(GLFWwindow *window, int button, int action, int mods)
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

	shared_ptr<Program> init(const std::string& resourceDirectory, const std::string& shader)
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
		prog->setShaderNames(resourceDirectory + shader + "_vert.glsl", resourceDirectory + shader + "_frag.glsl");
		prog->init();
		prog->addUniform("P");
		prog->addUniform("MV");
		prog->addUniform("roteW");
		prog->addAttribute("vertPos");
		prog->addAttribute("vertNor");

      return prog;
	}

	shared_ptr<Shape> initGeom(const std::string& resourceDirectory)
	{
		// Initialize mesh.
		shared_ptr<Shape> shape = make_shared<Shape>();
		shape->loadMesh(resourceDirectory + "/sphere.obj");
		shape->resize();
		shape->init();

      return shape;
	}

   void updateShader(const std::string& resourceDirectory, shared_ptr<Program> prog)
   { 
      switch (mode)
      {
         case 0: prog->setShaderNames(resourceDirectory + "/simple" + "_vert.glsl", resourceDirectory + "/simple" + "_frag.glsl");
                  break;

         case 1:prog->setShaderNames(resourceDirectory + "/rot" + "_vert.glsl", resourceDirectory + "/rot" + "_frag.glsl");
                  break;

         case 2:prog->setShaderNames(resourceDirectory + "/phong" + "_vert.glsl", resourceDirectory + "/phong" + "_frag.glsl");
                  break;


      } 
		    		    prog->init();
   }
	
   void render(const std::string& resourceDirectory, shared_ptr<Program> prog, shared_ptr<Shape> shape, float offset, int lfollow)
	{
		// Get current frame buffer size.
		int width, height;
		glfwGetFramebufferSize(windowManager->getHandle(), &width, &height);
		glViewport(0, 0, width, height);


		//Use the matrix stack for Lab 6
		float aspect = width/(float)height;

		// Create the matrix stacks - please leave these alone for now
		auto P = make_shared<MatrixStack>();
		auto MV = make_shared<MatrixStack>();
		// Apply perspective projection.
		P->pushMatrix();
		P->perspective(45.0f, aspect, 0.01f, 100.0f);

      if (sig)
      {
         updateShader(resourceDirectory, prog);
      }

		// Draw a stack of cubes with indiviudal transforms
		prog->bind();
//		prog->setShaderNames(resourceDirectory + shader + "_vert.glsl", resourceDirectory + shader +"_frag.glsl");
		glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));

		// draw bottom cube
		MV->pushMatrix();
			MV->loadIdentity();
			// draw the bottom cube with these 'global transforms'
		   MV->translate(vec3(Shuffle + offset, 0, -5));
			MV->rotate(0.5 + Rotate, vec3(0, 1, 0));
			MV->scale(vec3(1, 1, 1));
			glUniformMatrix4fv(prog->getUniform("MV"), 1, GL_FALSE, value_ptr(MV->topMatrix()));
			glUniform1i(prog->getUniform("roteW"), lfollow);
			shape->draw(prog);
		MV->popMatrix();
		prog->unbind();

//		prog->bind();
//		prog->setShaderNames(resourceDirectory + "/simple_vert.glsl", resourceDirectory + "/rot_frag.glsl");
//		glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix()));
//		MV->pushMatrix();
//			MV->loadIdentity();
//			MV->translate(vec3(Shuffle + 2, 0, -5));
//			MV->rotate(0.5 + Rotate, vec3(0, 1, 0));
//			MV->scale(vec3(1, 1, 1));
//			glUniformMatrix4fv(prog->getUniform("MV"), 1, GL_FALSE, value_ptr(MV->topMatrix()));
//			shape->draw(prog);

//		MV->popMatrix();


//		prog->unbind();

		// Pop matrix stacks.
		P->popMatrix();

		// update shoulder angle - animate
      if (Wave)
      {
		   if (Up)
   	   {
			   sTheta += 0.01;
		   }
		   if (Down)
		   {
			   sTheta -= 0.01;
		   }
         if (sTheta > 1.0 || sTheta < -0.6)
         {
            if (Up)
            {
               Up = 0;
               Down = 1;
            } else {
               Up = 1;
               Down = 0;
            }
         }
      }
	}
};

int main(int argc, char *argv[])
{
	// Where the resources are loaded from
	std::string resourceDir = "../resources";
	std::string shader1 = "/simple";
	std::string shader2 = "/rot";
   shared_ptr<Program> prog1, prog2;
   shared_ptr<Shape> shape1, shape2;
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

	prog1 = application->init(resourceDir, shader1);
	prog2 = application->init(resourceDir, shader2);
	shape1 = application->initGeom(resourceDir);
	shape2 = application->initGeom(resourceDir);

	// Loop until the user closes the window.
	while (! glfwWindowShouldClose(windowManager->getHandle()))
	{
		// Clear framebuffer.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render scene.
		application->render(resourceDir, prog1, shape1, 2, 0);
		application->render(resourceDir, prog2, shape2, -2, 1);

		// Swap front and back buffers.
		glfwSwapBuffers(windowManager->getHandle());
		// Poll for and process events.
		glfwPollEvents();
	}

	// Quit program.
	windowManager->shutdown();
	return 0;
}
