#version 330 core
layout(location = 0) in vec3 vertPos;
layout(location = 1) in vec3 vertCol;

out vec3 vertex_color;

uniform mat4 P;
uniform mat4 MV;

void main()
{
	gl_Position = P * MV * vec4(vertPos, 1.0);
   vertex_color = vertCol;
}
