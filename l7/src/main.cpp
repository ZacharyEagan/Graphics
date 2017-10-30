/* Lab 5 base code - transforms using local matrix functions
	to be written by students -
	CPE 471 Cal Poly Z. Wood + S. Sueda
*/
#include <iostream>
#include <glad/glad.h>

#include "GLSL.h"
#include "Program.h"
#include "Shape.h"
#include "WindowManager.h"
#include <cstdlib>
#include <time.h>
#include <sys/time.h>

// used for helper in perspective
#include "glm/glm.hpp"
#include "Sun.hpp"
#define BACKOFF -20

using namespace std;
using namespace glm;

class Matrix
{

public:

	static void printMat(float *A, const char *name = 0)
	{
		// OpenGL uses col-major ordering:
		// [ 0  4  8 12]
		// [ 1  5  9 13]
		// [ 2  6 10 14]
		// [ 3  7 11 15]
		// The (i, j)th element is A[i+4*j].

		if (name)
		{
			printf("%s=[\n", name);
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				printf("%- 5.2f ", A[i + 4*j]);
			}
			printf("\n");
		}

		if (name)
		{
			printf("];");
		}
		printf("\n");
	}

	static void createIdentityMat(float *M)
	{
		// set all values to zero
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				M[i + 4*j] = 0;
			}
		}

		// overwrite diagonal with 1s
		M[0] = M[5] = M[10] = M[15] = 1;

	}

	static void createTranslateMat(float *T, float x, float y, float z)
	{
		for (int i = 0; i < 4; ++i)
      {
         for (int j = 0; j < 4; ++j)
         {
            T[i + 4*j] = 0;
         }
      }
      T[0] = T[5] = T[10] = T[15] = 1;
      T[14] = z;
      T[13] = y;
      T[12] = x;
	}

	static void createScaleMat(float *S, float x, float y, float z)
	{
		// IMPLEMENT ME
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				S[i + 4*j] = 0;
			}
		}
		// overwrite diagonal with 1s
		S[0] = x;
      S[5] = y;
      S[10] = z;
      S[15] = 1;
	}

	static void createRotateMatX(float *R, float radians)
	{
		// IMPLEMENT ME
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				R[i + 4*j] = 0;
			}
		}
		// overwrite diagonal with 1s
		R[0] = 1;
      R[5] = cos(radians);
      R[10] = cos(radians);
      R[15] = 1;
      R[6] = sin(radians);
      R[9] = -sin(radians);
	}

	static void createRotateMatY(float *R, float radians)
	{
		// IMPLEMENT ME
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				R[i + 4*j] = 0;
			}
		}
		// overwrite diagonal with 1s
		R[0] = cos(radians);
      R[5] = 1;
      R[10] = cos(radians);
      R[15] = 1;
      R[8] = sin(radians);
      R[2] = -sin(radians);
	}

	static void createRotateMatZ(float *R, float radians)
	{
		// IMPLEMENT ME
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				R[i + 4*j] = 0;
			}
		}
		// overwrite diagonal with 1s
		R[0] = cos(radians);
      R[5] = cos(radians);
      R[10] = 1;
      R[15] = 1;
      R[1] = sin(radians);
      R[4] = -sin(radians);
      
	}

	static void multMat(float *C, const float *A, const float *B)
	{
		float c = 0;

		for (int k = 0; k < 4; ++k)
		{
			// Process kth column of C
			for (int i = 0; i < 4; ++i)
			{
				// Process ith row of C.
				// The (i,k)th element of C is the dot product
				// of the ith row of A and kth col of B.
				c = 0;

				// vector dot product
				for (int j = 0; j < 4; ++j)
				{
               c += A[i+4*j]*B[j+4*k];
					// IMPLEMENT ME
				}
            C[i+4*k] = c;
			}
		}
	}

	static void createPerspectiveMat(float *m, float fovy, float aspect, float zNear, float zFar)
	{
		// http://www-01.ibm.com/support/knowledgecenter/ssw_aix_61/com.ibm.aix.opengl/doc/openglrf/gluPerspective.htm%23b5c8872587rree
		float f = 1.0f / glm::tan(0.5f * fovy);

		m[ 0] = f / aspect;
		m[ 1] = 0.0f;
		m[ 2] = 0.0f;
		m[ 3] = 0.0f;
		m[ 4] = 0;

		m[ 5] = f;
		m[ 6] = 0.0f;
		m[ 7] = 0.0f;
		m[ 8] = 0.0f;

		m[ 9] = 0.0f;
		m[10] = (zFar + zNear) / (zNear - zFar);
		m[11] = -1.0f;
		m[12] = 0.0f;

		m[13] = 0.0f;
		m[14] = 2.0f * zFar * zNear / (zNear - zFar);
		m[15] = 0.0f;
	}

};

class Application : public EventCallbacks
{

public:

	WindowManager * windowManager = nullptr;

	// Our shader program
	//std::shared_ptr<Program> prog;

	// Shape to be used (from obj file)


	// Contains vertex information for OpenGL
	GLuint VertexArrayID;

	// Data necessary to give our triangle to OpenGL
	GLuint VertexBufferID;

   float UnivRot[16];

	void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
      float temp1[16];
      float temp2[16];
      float temp3[16];
      float temp4[16];
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
      if (key == GLFW_KEY_A && action == GLFW_PRESS)
      {
       
         Matrix::createTranslateMat(temp1, 0, 0, -BACKOFF);
         Matrix::createRotateMatY(temp2, 0.01);
         Matrix::createTranslateMat(temp4, 0, 0, BACKOFF);
         Matrix::multMat(temp3, temp2, temp1);
         Matrix::multMat(UnivRot, temp4, temp3);
         //cout << key <<"\n";
      } else
      {
         if (key == GLFW_KEY_A && action == 0)
         {
            Matrix::createIdentityMat(UnivRot);
         }
      }
      if (key == GLFW_KEY_D && action == GLFW_PRESS)
      {
         Matrix::createTranslateMat(temp1, 0, 0, -BACKOFF);
         Matrix::createRotateMatY(temp2, -0.01);
         Matrix::createTranslateMat(temp4, 0, 0, BACKOFF);
         Matrix::multMat(temp3, temp2, temp1);
         Matrix::multMat(UnivRot, temp4, temp3);
         //cout << key << "\n";
      } else
      {
         if (key == GLFW_KEY_D && action == 0)
         {
            Matrix::createIdentityMat(UnivRot);
         }
      }
      if (key == GLFW_KEY_W && action == GLFW_PRESS)
      {
         Matrix::createTranslateMat(temp1, 0, 0, -BACKOFF);
         Matrix::createRotateMatX(temp2, 0.01);
         Matrix::createTranslateMat(temp4, 0, 0, BACKOFF);
         Matrix::multMat(temp3, temp2, temp1);
         Matrix::multMat(UnivRot, temp4, temp3);
         //cout << key << "\n";
      } else
      {
         if (key == GLFW_KEY_W && action == 0)
         {
            Matrix::createIdentityMat(UnivRot);
         }
      }
      if (key == GLFW_KEY_S && action == GLFW_PRESS)
      {
         Matrix::createTranslateMat(temp1, 0, 0, -BACKOFF);
         Matrix::createRotateMatX(temp2, -0.01);
         Matrix::createTranslateMat(temp4, 0, 0, BACKOFF);
         Matrix::multMat(temp3, temp2, temp1);
         Matrix::multMat(UnivRot, temp4, temp3);
         //cout << key << "\n";
      } else
      {
         if (key == GLFW_KEY_W && action == 0)
         {
            Matrix::createIdentityMat(UnivRot);
         }
      }
	}

	void mouseCallback(GLFWwindow *window, int button, int action, int mods)
	{
		double posX, posY;

		if (action == GLFW_PRESS)
		{
			glfwGetCursorPos(window, &posX, &posY);
			//cout << "Pos X " << posX <<  " Pos Y " << posY << endl;
		}
	}

	void resizeCallback(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	std::shared_ptr<Program> init(const std::string& resourceDirectory, const std::string& shader)
	{
		GLSL::checkVersion();

	   std::shared_ptr<Program> prog;
      Matrix::createIdentityMat(UnivRot);
		// Set background color.
		glClearColor(0.12f, 0.34f, 0.56f, 1.0f);

		// Enable z-buffer test.
		glEnable(GL_DEPTH_TEST);

		// Initialize the GLSL program.
		prog = make_shared<Program>();
		prog->setVerbose(true);
		//prog->setShaderNames(resourceDirectory + "/simple_vert.glsl", resourceDirectory + "/simple_frag.glsl");
		prog->setShaderNames(resourceDirectory + "/simple_vert.glsl", resourceDirectory + shader);
		if (! prog->init())
		{
			std::cerr << "One or more shaders failed to compile... exiting!" << std::endl;
			exit(1);
		}
		prog->init();
		prog->addUniform("P");
		prog->addUniform("MV");
		prog->addAttribute("vertPos");
		prog->addAttribute("vertNor");
      
      return prog;
	}
   
   

   void setGeom(Obj *circ)
   {
      //circ = new Circle(0.90, 2000);

      //Vertex Array
      //generate the VAO
      //glGenVertexArrays(1, &VertexArrayID);
      //glBindVertexArray(VertexArrayID);
      glGenVertexArrays(1, &(circ->_vaID));
      glBindVertexArray((circ->_vaID));

      //generate vertex buffer to hand off to OGL
      //glGenBuffers(1, &VertexBufferID);
      glGenBuffers(1, &(circ->_vbID));
      //set the current state to focus on our vertex buffer
      //glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
      glBindBuffer(GL_ARRAY_BUFFER, circ->_vbID);

      std::vector<GLfloat> vec = circ->get_Vec();
      //actually memcopy the data - only do this once
      glBufferData(GL_ARRAY_BUFFER, vec.size() * sizeof (GLfloat), vec.data(), GL_DYNAMIC_DRAW);
      //we need to set up the vertex array
      glEnableVertexAttribArray(0);
      //key function to get up how many elements to pull out at a time (3)
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

//Color array
      //glGenBuffers(1, &VertexColorID);
      glGenBuffers(1, &(circ->_vcID));
      //glBindBuffer(GL_ARRAY_BUFFER, VertexColorID);
      glBindBuffer(GL_ARRAY_BUFFER, circ->_vcID);
      std::vector<GLfloat> col = circ->get_Col();
      glBufferData(GL_ARRAY_BUFFER, col.size() * sizeof(GLfloat),
                   col.data(), GL_DYNAMIC_DRAW);
      glEnableVertexAttribArray(1);
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);



      //Index Array      
      //glGenBuffers(1, &IndexBufferID);
      glGenBuffers(1, &(circ->_ibID));
      //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, circ->_ibID);
      std::vector<GLint> ind = circ->get_Ind();
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                   ind.size() * sizeof(GLint),
                   ind.data(), GL_DYNAMIC_DRAW);

      glBindVertexArray(0);

   }




	shared_ptr<Shape> initGeom(const std::string& resourceDirectory, const std::string& objName)
	{
	   shared_ptr<Shape> shape;
		// Initialize mesh.
		shape = make_shared<Shape>();
      if (objName.size() > 1)
      {
	   	shape->loadMesh(resourceDirectory + objName);
      }
      else
      {
         cout << "YAR!\n";
         shape->genCylinder();
      }
		shape->resize();
		shape->init();
      
      return shape;
	}

	void render(std::shared_ptr<Program> prog, 
               float MV[16], shared_ptr<Shape> shape)
	{

		float P[16] = {0};

		// Get current frame buffer size.
		int width, height;
		glfwGetFramebufferSize(windowManager->getHandle(), &width, &height);
		glViewport(0, 0, width, height);


		// Use the local matrices for lab 5
		float aspect = width/(float)height;
		Matrix::createPerspectiveMat(P, 70.0f, aspect, 0.1f, 100.0f);
		

		// Draw mesh using GLSL
		prog->bind();
		glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, P);
		glUniformMatrix4fv(prog->getUniform("MV"), 1, GL_FALSE, MV);
		shape->draw(prog);
		prog->unbind();
	}
};

int main(int argc, char **argv)
{
	// Where the resources are loaded from
	std::string resourceDir = "../resources/";
	std::vector<std::shared_ptr<Program>> progs;
	std::vector<std::shared_ptr<Shape>> shapes;
	std::shared_ptr<Program> prog;
	std::shared_ptr<Shape> shape;
   std::vector<float *> MVs;
   float MV1[16] = {0};
   float MV2[16] = {0};
   float MV3[16] = {0};
   float MV4[16] = {0};
   float MV5[16] = {0};

	float temp1[16] = {0};
   srand(time(NULL));

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





		// Get current frame buffer size.
		int width, height;
		glfwGetFramebufferSize(windowManager->getHandle(), &width, &height);



	// This is the code that will likely change program to program as you
	// may need to initialize or set up different data and state
   float MV[100][16];
   float scale[16];
   float trans[16];
   float rot[16];

   float gravityTrans[16];
   float tempGT[16];
   float tempID[16];
   float tempUR[16];
   float tempDEF[16];
   
   Matrix::createIdentityMat(tempID);
   Matrix::createTranslateMat(gravityTrans, rand()%2 - 1, (rand()%2 - 1) - 1, -(rand() % 20 + 1) - 8);

   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glEnable(GL_BLEND);

	prog = application->init(resourceDir, "simple_frag.glsl");
   Matrix::createScaleMat(scale, 1.8, 1.8, 1.8);
   Matrix::createTranslateMat(trans, -5, -1, BACKOFF);
   Matrix::multMat(MV1, trans, scale);
   MVs.push_back(MV1);
   progs.push_back(prog);
	shape = application->initGeom(resourceDir, "sphere.obj");
   shapes.push_back(shape);
/*
	prog = application->init(resourceDir, "simple_frag.glsl");
   Matrix::createScaleMat(scale, 1.8, 1.8, 1.8);
   Matrix::createTranslateMat(trans, 5, -1, BACKOFF);
   Matrix::multMat(MV2, trans, scale);
   MVs.push_back(MV2);
   progs.push_back(prog);
	shape = application->initGeom(resourceDir, "sphere.obj");
   shapes.push_back(shape);
*/

   timeval timL, tim;
   gettimeofday(&tim,0);
   
	// Loop until the user closes the window.
	while (! glfwWindowShouldClose(windowManager->getHandle()))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Render scene.
      for (unsigned int i = 0; i < progs.size(); i++)
      {
         Matrix::multMat(tempDEF, application->UnivRot, MVs.at(i)) ;
         Matrix::multMat(MVs.at(i), tempID, tempDEF);

		   application->render(progs.at(i), MVs.at(i), shapes.at(i));
      }

		// Swap front and back buffers.
		glfwSwapBuffers(windowManager->getHandle());
		// Poll for and process events.
		glfwPollEvents();
	}

	// Quit program.
	windowManager->shutdown();
	return 0;
}
