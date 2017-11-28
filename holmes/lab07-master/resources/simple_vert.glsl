#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;
uniform mat4 P;
uniform mat4 MV;

uniform vec3 LP;
uniform vec3 LC;

out vec3 fragNor;
out vec3 colour;


void main()
{
   
	gl_Position = P * MV * vertPos;
	fragNor = (MV * vec4(vertNor, 0.0)).xyz;
   colour = (MV * vec4(vertNor, 0.0)).xyz;
   //colour = (MV * vec4(LC, 0.0)).xyz;
}
