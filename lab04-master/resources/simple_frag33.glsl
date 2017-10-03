#version 330 core
uniform vec2 uWindowSize;
out vec3 color;

in vec3 vertex_color;

void main()
{
	color = vertex_color;
   //color.r = gl_FragCoord.x / uWindowSize.x;
 //  color.g = vertex_color.y;
//   color.r = gl_FragCoord.y;
  // color.r = vertex_color.x;
}
