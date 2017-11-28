#version 330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;

uniform mat4 P;
uniform mat4 MV;

uniform vec3 MatAmb;
uniform vec3 MatSpec;
uniform vec3 MatDif;
uniform float shine;

uniform vec3 LP;
uniform vec3 LC;


out vec4 colour;

void main()
{
   gl_Position = P * MV * vertPos;
   vec3 eye = (MV * vertPos).xyz;
   vec3 fragNor = (MV*vec4(vertNor, 0.0)).xyz;

   vec3 norm = normalize(fragNor);
   vec4 dif = vec4(LC * MatDif, 1.0) * dot(LP, norm);

   vec4 amb = vec4(MatAmb * LC, 1.0);

   vec3 ref = reflect(LP, norm);
   ref = normalize(ref);
   vec3 eyeN = normalize(eye);

   float specM = clamp(pow(dot(ref, eyeN), shine), 0.0, 1.0);
   vec4 spec = specM * vec4(LC * MatSpec, 1.0);
   colour = (8.0 * spec + dif + amb) / 10;
}

