#version 330 core 
in vec3 fragNor;
in vec3 light;

out vec4 color;

void main()
{

	vec3 fnorm;
   float val;
   vec3 lightT = light; //vec3(2.0, 2.0, 2.0);
   vec3 lightC = vec3(0.8, 0.1, 0.4);

   fnorm = normalize(fragNor);
   lightT = normalize(light);

   val = clamp(dot(fnorm, lightT), 0.0, 1.0);

   color = (vec4(lightC, 1.0) * val );

}
