#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;
uniform mat4 P;
uniform mat4 MV;
out vec3 fragNor;

void main()
{
	gl_Position = P * MV * vertPos;
   fragNor = (MV * vec4(vertNor, 1.0)).xyz;
   if (fragNor.xyz == vec3(0,0,0))
      fragNor.xyz = vec3(1.0,1.0,1.0);
   fragNor.a *= 1 / vertPos;
   
}
