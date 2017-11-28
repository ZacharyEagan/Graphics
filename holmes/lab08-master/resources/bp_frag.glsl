#version 330 core

uniform vec3 MatAmb;
uniform vec3 MatSpec;
uniform vec3 MatDif;
uniform float shine;

uniform sampler2D vertTex;

uniform vec3 LP[10];
uniform vec3 LC[10];

in vec3 fragNor;
in vec3 eye;

out vec4 color;




void main()
{
   vec4 colour = vec4(0.f);
   vertTex;

   for (int i = 0; i < 4; i++)
   {
           vec3 len = LP[0] - gl_FragCoord.xyz;
           float spread = length(len);
           vec3 norm = normalize(fragNor);
           vec4 dif = vec4(LC[i] * MatDif, 1.0) * dot(LP[i], norm);
           dif /=  ((1.f + spread) /100.f);



           vec4 amb = vec4(MatAmb * LC[i], 1.0);

           vec3 ref = reflect(LP[i], norm);
           ref = normalize(ref);
           vec3 eyeN = normalize(eye);

           float specM = clamp(pow(dot(ref, eyeN), shine), 0.0, 1.0);
           vec4 spec = specM * vec4(LC[i] * MatSpec, 1.0);
           spec /= ((1.f + spread) /100.f);
           colour += min((spec + dif + amb/2), 1.0);
   }
   color = colour / 4;
}

