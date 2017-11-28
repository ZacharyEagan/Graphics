#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;

uniform mat4 P;
uniform mat4 MV;

uniform mat4 V; //new1


out vec3 fragNor;
out vec3 eye;

void main()
{
   gl_Position = P * V * MV * vertPos;
   eye = (V * MV * vertPos).xyz;
   fragNor = (MV*vec4(vertNor, 0.0)).xyz;
}

