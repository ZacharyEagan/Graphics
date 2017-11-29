#version 330 core

uniform vec3 MatAmb;
uniform vec3 MatSpec;
uniform vec3 MatDif;
uniform float shine;
uniform float alpha;
uniform float nLights;

uniform sampler2D vertTex;

uniform vec3 LP[10];
uniform vec3 LC[10];
uniform vec3 VP;

uniform  mat4 MV;
uniform mat4 P;
uniform mat4 V;

in vec3 fragNor;
in vec4 pos;
in vec3 eye;

out vec4 color;




void main()
{
   vec4 colour = vec4(0.f);
   vec3 lght;
   vertTex;

   vec3 norm = normalize(fragNor);
   vec3 eyeN = normalize(VP - pos.xyz);

   //for (int i = 0; i < nLights; i++)
   for (int i = 0; i < 10; i++)
   {
           lght = (vec4(LP[i], 0.f)).xyz; 
           vec3 len = (lght - pos.xyz);
           vec3 norLen = normalize(len);

           float df = dot(norLen,norm);
           if (df < 0.f)
               df *= alpha;
           vec4 dif = vec4(LC[i]  * MatDif, 1.0) * max(0,df);

           vec3 ref = reflect(-norLen, norm);
           ref = normalize(ref);
           float specM = max(0.f, dot(eyeN, ref));
           specM = pow(specM, shine);
           vec4 spec = specM * vec4(LC[i] * MatSpec, 1.0);



           len *= vec3(0.08f,0.02f,0.08f);
           float dst = length(len);
           dst *= dst;
           dst = 1 / dst;
            


       

           vec4 amb = vec4(MatAmb * LC[i], 1.0);


         //  spec /= dst;
           colour += (dif * dst) +  0.001 * (amb * dst) + (spec * dst)/2.001;
           
           //colour += min((spec + dif + amb/2), 1.0);
         //  colour += vec4(LC[i], 1.0) * vec4(1.0) / dst;
   }
//   colour = colour / nLights;
   colour = colour / 10;
   colour.a = 1.f;
   color = min(colour, vec4(1.0));

  //color = vec4(VP, 1.0);
//   color = vec4(norm, 1.0);
}

