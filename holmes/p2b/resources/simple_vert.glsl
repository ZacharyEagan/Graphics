#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;
uniform mat4 P;
uniform mat4 MV;
out vec3 fragNor;
out vec4 pos;

void main()
{
	gl_Position = P * MV * vertPos;
   fragNor = (MV * vec4(vertNor, 0.0)).xyz;
   if (fragNor.xyz == vec3(0,0,0))
      fragNor.xyz = vec3(1.0,1.0,1.0) * (vertPos.z/100);
   pos = gl_Position;   
}
