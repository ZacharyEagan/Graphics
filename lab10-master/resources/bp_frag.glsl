#version 330 core

uniform vec3 MatAmb;
uniform vec3 MatSpec;
uniform vec3 MatDif;
uniform float shine;

uniform vec3 LP;
uniform vec3 LC;

in vec3 fragNor;
in vec3 eye;

out vec4 color;

void main()
{
   vec3 len = LP - gl_FragCoord.xyz;
   float spread = length(len);
   vec3 norm = normalize(fragNor);
   vec4 dif = vec4(LC * MatDif, 1.0) * dot(LP, norm);
   dif *= (1 / spread);

   vec4 amb = vec4(MatAmb * LC, 1.0);
   //amb *= (1 / spread);

   vec3 ref = reflect(LP, norm);
   ref = normalize(ref);
   vec3 eyeN = normalize(eye);

   float specM = clamp(pow(dot(ref, eyeN), shine), 0.0, 1.0);
   vec4 spec = specM * vec4(LC * MatSpec, 1.0);
   spec *= (1 / spread);
   color = min((spec + dif + amb) / 2, 1.0);
}

