#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;

uniform mat4 P;
uniform mat4 MV;

uniform mat4 V; //new1
//uniform vec3 VP;

out vec3 fragNor;
out vec3 eye;
out vec4 pos;


void main()
{
   vec4 position = P * V * MV * vertPos;
   gl_Position = position;
   pos = MV * vertPos;
   eye = vec3(V[3][0],V[3][1],V[3][2]);
   //eye = normalize(-pos).xyz;
   fragNor = (MV*vec4(vertNor, 0.0)).xyz;
}

