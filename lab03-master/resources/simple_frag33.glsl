#version 330 core
uniform vec2 uWindowSize;
out vec3 color;


void main()
{
	color = vec3(0.0, 0.0, 0.0);
   color.r = gl_FragCoord.x / uWindowSize.x;
   
}
