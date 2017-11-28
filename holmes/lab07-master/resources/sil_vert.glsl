#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;

uniform mat4 P;
uniform mat4 MV;

uniform vec3 TEST;
uniform vec3 LP;

out vec3 fragNor;
out vec4 fragPos;
out vec3 light;
out vec3 lightCol;

void main()
{
   vec3 lightT =  LP;//   
   light = lightT;

   fragPos = MV * vertPos;
   gl_Position = P * fragPos;
   fragNor = (MV*vec4(vertNor, 0.0)).xyz;   
   //float comp = dot( gl_Position.xyz, fragNor);
   //if (comp <= 0.015 && comp >= -0.015)
   //   lightCol = vec3(0.0,0.0,0.0);
   //else
      lightCol = vec3(1.0,1.0,1.0);
}
