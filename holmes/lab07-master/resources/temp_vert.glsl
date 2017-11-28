#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;

uniform mat4 P;
uniform mat4 MV;

uniform vec3 LP; //light position
uniform vec3 LC; //light color

uniform vec3 MatAmb; //ambiant reflectance spectra
uniform vec3 MatDif; //diffuse
uniform vec3 MatSpec; //specular
uniform float shine; //shinyness coeficient




out vec3 fragNor; //normal for interpolation
out vec3 colour; //color for interpolation

void main()
{

	gl_Position = P * MV * vertPos;

   vec3 light = LP;
   vec3 lightC = LC;

   colour = lightC * MatAmb;
}
