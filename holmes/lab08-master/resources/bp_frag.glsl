#version 330 core

uniform sampler2D Texture0;

uniform vec3 MatAmb;
uniform vec3 MatSpec;
uniform vec3 MatDif;
uniform float shine;
uniform float alpha;
uniform int nLights;


uniform vec3 LP[20];
uniform vec3 LC[20];
uniform vec3 VP;

uniform  mat4 MV;
uniform mat4 P;
uniform mat4 V;

in vec3 fragNor;
in vec4 pos;
in vec3 eye;

in vec2 vTexCoord;

out vec4 color;




void main()
{

   vec4 texColor0 = texture(Texture0, (vTexCoord*2));

   vec4 colour = vec4(0.f);
  // colour += texColor0;
   vec3 lght;

   vec3 norm = normalize(fragNor);
   vec3 eyeN = normalize(VP - pos.xyz);

   for (int i = 0; i < nLights; i++)
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
            

           vec3 lenE = (VP - pos.xyz);
           lenE *= vec3(0.1f,0.1f,0.1f);
           float dstE = length(lenE);
           dstE *= dstE;
           dstE = 1 / dstE;
           dstE = min (1.f, dstE);
       

           vec4 amb = vec4(MatAmb * LC[i], 1.0);


           colour += dstE * ((dif * dst) +  0.001 * (amb * dst) + (spec * dst))/2.001;
           
   }
   colour = colour / nLights;
   colour.a = 1.f;
   color = min(colour, vec4(1.0));


}

