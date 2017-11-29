#include "Parts.hpp"

using namespace std;
using namespace glm;



 void Parts::init(WindowManager  * wm)
   {
      std::cout << "init s\n";
      windowManager = wm;
      int width, height;
      glfwGetFramebufferSize(windowManager->getHandle(), &width, &height);
      GLSL::checkVersion();


      // Enable z-buffer test.
      CHECKED_GL_CALL(glEnable(GL_DEPTH_TEST));
      CHECKED_GL_CALL(glEnable(GL_BLEND));
      CHECKED_GL_CALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
      CHECKED_GL_CALL(glPointSize(14.0f));

      // Initialize the GLSL program.

      prog = make_shared<Program>();
      prog->setVerbose(true);
      prog->setShaderNames(
         "../resources/lab10_vert.glsl",
         "../resources/lab10_frag.glsl");
      if (! prog->init())
      {
         std::cerr << "One or more shaders failed to compile... exiting!" << std::endl;
         exit(1);
      }
      prog->addUniform("P");
      prog->addUniform("MV");
      prog->addUniform("alphaTexture");
      prog->addAttribute("vertPos");
      std::cout << "init e\n";
   }




  // Code to load in the three textures
   void Parts::initTex()
   {
      std::cout << "init tex s\n";
      texture = make_shared<Texture>();
      texture->setFilename("../resources/alpha.bmp");
      texture->init();
      texture->setUnit(0);
      texture->setWrapModes(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
      std::cout << "init tex s\n";
   }

   void Parts::initParticles()
   {
      std::cout << "init particles s\n";
      int n = numP;
      t = 0.f; 
      for (int i = 0; i < n; ++ i)
      {
         auto particle = make_shared<Particle>();
         particles.push_back(particle);
         particle->load();
      }
      for (int i = 100; i--;)
      {
         updateParticles();
         updateGeom();
      }
      std::cout << "init particles s\n";
   }


  void Parts::initGeom()
   {
      std::cout << "init Geom s\n";
      // generate the VAO
      CHECKED_GL_CALL(glGenVertexArrays(1, &VertexArrayID));
      CHECKED_GL_CALL(glBindVertexArray(VertexArrayID));

      // generate vertex buffer to hand off to OGL - using instancing
      CHECKED_GL_CALL(glGenBuffers(1, &pointsbuffer));
      // set the current state to focus on our vertex buffer
      CHECKED_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, pointsbuffer));
      // actually memcopy the data - only do this once
      CHECKED_GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(points), NULL, GL_STREAM_DRAW));

      CHECKED_GL_CALL(glGenBuffers(1, &colorbuffer));
      // set the current state to focus on our vertex buffer
      CHECKED_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, colorbuffer));
      // actually memcopy the data - only do this once
      CHECKED_GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(pointColors), NULL, GL_STREAM_DRAW));
      std::cout << "init Geom s\n";
   }




   // Note you could add scale later for each particle - not implemented
   void Parts::updateGeom()
   {
      //std::cout << "update geom particles s\n";
      glm::vec3 pos;
      glm::vec4 col;

      // go through all the particles and update the CPU buffer
      for (int i = 0; i < numP; i++)
      {
         //std::cout << "a\n" << particles.size() << "\n";
         pos = particles[i]->getPosition();
        // std::cout<<"aa\n";
         col = particles[i]->getColor();
        // std::cout<<"aa\n";

         points[i * 3 + 0] = pos.x;
         points[i * 3 + 1] = pos.y;
         points[i * 3 + 2] = pos.z;
         pointColors[i * 4 + 0] = col.r + col.a / 10.f;
         pointColors[i * 4 + 1] = col.g + col.g / 10.f;
         pointColors[i * 4 + 2] = col.b + col.b / 10.f;
         pointColors[i * 4 + 3] = col.a;
        // std::cout << "b\n";
      }
        // std::cout << "c\n";

      // update the GPU data
      CHECKED_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, pointsbuffer)); 
      CHECKED_GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(points), NULL, GL_STREAM_DRAW));
      CHECKED_GL_CALL(glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * numP * 3, points));

      CHECKED_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, colorbuffer));
      CHECKED_GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(pointColors), NULL, GL_STREAM_DRAW));
      CHECKED_GL_CALL(glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * numP * 4, pointColors));

      CHECKED_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
     // std::cout << "update geom particles s\n";
   }




 /* note for first update all particles should be "reborn"
    * which will initialize their positions */
   void Parts::updateParticles()
   {
      //std::cout << "update particles s\n";
      // update the particles
      for (auto particle : particles)
      {
         particle->update(t, h, g, keyToggles);
      } 
      t += h;

      // Sort the particles by Z
      auto temp = make_shared<MatrixStack>();
      temp->rotate(camRot, vec3(0, 1, 0));

      ParticleSorter sorter;
      sorter.C = temp->topMatrix();
      std::sort(particles.begin(), particles.end(), sorter);
      //std::cout << "update particles s\n";
   }
   void Parts::draw(std::shared_ptr<MatrixStack> MV, std::shared_ptr<MatrixStack> P, glm::mat4 V)
   {
      MV->pushMatrix();
      MV->translate(vec3(0.0,20.f,0.f));
      P->pushMatrix();
      P->multMatrix(V); 

      prog->bind();
      updateParticles();
      updateGeom();

      texture->bind(prog->getUniform("alphaTexture"));
      CHECKED_GL_CALL(glUniformMatrix4fv(prog->getUniform("P"), 1, GL_FALSE, value_ptr(P->topMatrix())));
      CHECKED_GL_CALL(glUniformMatrix4fv(prog->getUniform("MV"), 1, GL_FALSE, value_ptr(MV->topMatrix())));

      CHECKED_GL_CALL(glEnableVertexAttribArray(0));
      CHECKED_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, pointsbuffer));
      CHECKED_GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0));

      CHECKED_GL_CALL(glEnableVertexAttribArray(1));
      CHECKED_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, colorbuffer));
      CHECKED_GL_CALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*) 0));

      CHECKED_GL_CALL(glVertexAttribDivisor(0, 1));
      CHECKED_GL_CALL(glVertexAttribDivisor(1, 1));
      // Draw the points !
      CHECKED_GL_CALL(glDrawArraysInstanced(GL_POINTS, 0, 1, numP));

      CHECKED_GL_CALL(glVertexAttribDivisor(0, 0));
      CHECKED_GL_CALL(glVertexAttribDivisor(1, 0));
      CHECKED_GL_CALL(glDisableVertexAttribArray(0));
      CHECKED_GL_CALL(glDisableVertexAttribArray(1));
      prog->unbind();

      // Pop matrix stacks.
      MV->popMatrix();

      P->popMatrix();
   }
