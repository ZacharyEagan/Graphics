#version  330 core
layout(location = 0) in vec3 vertPos;
layout(location = 1) in vec3 vertNor;

uniform mat4 P;
uniform mat4 MV;
uniform mat4 V; //new1


out vec2 texCoord;

void main()
{
//  gl_Position = P * V * MV * vec4(vertPos, 1);

   gl_Position = vec4(vertPos, 1);
	texCoord = (vertPos.xy+vec2(1, 1))/2.0;
}
