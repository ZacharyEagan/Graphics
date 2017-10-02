#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>

#include <glm/glm.hpp>

using namespace glm;

int main()
{
   if (!glwInit())
   {
      fprintf(stderr, "FAILURE\n");
      return -1;
   }

   return 0;
}
