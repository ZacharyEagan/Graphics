#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;
uniform mat4 P;
uniform mat4 MV;
uniform mat4 V;
out vec3 fragPos;

void main()
{
	gl_Position = P * V * MV * vertPos;
	fragPos = (V * MV * vertPos).xyz;
}
