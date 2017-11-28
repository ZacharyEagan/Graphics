#version 330 core 
in vec3 fragNor;
in vec3 light;
in vec3 lightCol;
in vec4 fragPos;

out vec4 color;

void main()
{

	vec3 fnorm;
   //float val;
   //vec3 lightT = light; //vec3(2.0, 2.0, 2.0);
   vec3 lightC = lightCol;

   fnorm = normalize(fragNor);
   //lightT = normalize(light);

   //val = clamp(dot(fnorm, lightT), 0.0, 1.0);
   color = (vec4(lightC, 1.0));
   
   float a = dot(fragNor, -1*fragPos.xyz);
   if (a > -0.015 && a < 0.015)
      color = vec4(0.0,0.0,0.0,1.0);

}
