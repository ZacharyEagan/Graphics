#version 330 core
uniform sampler2D Texture0;

in vec2 vTexCoord;
in float dCo;
out vec4 Outcolor;

void main() {
  vec4 texColor0 = texture(Texture0, vTexCoord);
 
//   if (texColor0.r > 0.2)
//      texColor0.r = 1.0;
//   if (texColor0.g < 0.2)
//      texColor0.g = 1.0;
//   if (texColor0.b < 0.2)
//      texColor0.b = 1.0;

  	Outcolor = dCo*texColor0;
  
	//DEBUG:Outcolor = vec4(vTexCoord.s, vTexCoord.t, 0, 1);
}

