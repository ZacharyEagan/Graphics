#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;

uniform mat4 P;
uniform mat4 MV;
uniform int roteW;

out vec3 fragNor;
out vec3 colour;

void main()
{
   float val;
   vec3 light = vec3(2.0, 2.0, 2.0);
   vec3 lightC = vec3(0.8, 0.1, 0.4);
	gl_Position = P * MV * vertPos;
	fragNor = (MV * vec4(vertNor, 0.0)).xyz;
   fragNor = normalize(fragNor);
   light = normalize(light);

   val = clamp(dot(fragNor, light), 0.0, 1.0);
   
   colour = (vec4(lightC, 1.0) * val).xyz;
//   colour = (vec4(1.0,1.0,1.0,1.0) * val).xyz;
}
