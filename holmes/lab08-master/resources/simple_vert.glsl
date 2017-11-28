#version  330 core
layout(location = 0) in vec4 vertPos;
layout(location = 1) in vec3 vertNor;
uniform mat4 P;
uniform mat4 MV;
uniform mat4 V; //new1
out vec3 fragNor;
out vec3 WPos;

void main()
{
	//gl_Position = P * MV * vertPos; //rem1
	gl_Position = P * V * MV * vertPos; //new1
	fragNor = (MV * vec4(vertNor, 0.0)).xyz;
	WPos = vec3(MV*vertPos);
}
