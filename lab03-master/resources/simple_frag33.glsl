#version 330 core
uniform vec2 uWindowSize;
out vec3 color;

in vec2 vertex_color;

void main()
{
	color = vec3(0.0, 0.0, 0.0);
   //color.r = gl_FragCoord.x / uWindowSize.x;
   color.g = vertex_color.y;
//   color.r = gl_FragCoord.y;
   color.r = vertex_color.x;
}
