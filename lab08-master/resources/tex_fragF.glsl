#version 330 core

in vec2 texCoord;
out vec4 color;
uniform sampler2D texBuf;
uniform vec2 dir;

uniform float offset[5] = float[]( 0.0, 1.0, 2.0, 3.0, 4.0 );
uniform float weight[5] = float[]( 0.2270270270, 0.1945945946, 0.1216216216, 
											0.0540540541, 0.0162162162 );

void main(){
   //color = vec4(texture( texBuf, texCoord ).rgb, 1)*weight[0];
   color = vec4(0);
   //chroma
   float fog = (int(texCoord.x * 1000) % 4) == 1.74 ? (int(texCoord.y * 1000) % 4) == 0 ? 3.0 : 2.0 : 1.0;
  // int x =int(texCoord.x);
  // int y =int( texCoord.y);
   for (float j = 0.f; j < 1.f; j+=0.1)
   {
      for (float i = 0.0f; i < 3.142539 * 2.0; i += 0.31425)
      {  
         color.r += texture(texBuf, texCoord + vec2(14.0 * (1 - j) * cos(i), 14.0 * (1 - j) * sin(i))/512.0).r * ((1.f - j) / 5.f);
         color.g += texture(texBuf, texCoord + vec2(7.0 * (1 - j) * cos(i), 7.0 * (1 - j) * sin(i))/512.0).g * ((1.f - j) / 5.f);
         color.b += texture(texBuf, texCoord + vec2(2.0 * (1 - j) * cos(i), 2.0 * (1 - j) * sin(i))/512.0).b * ((1.f - j) / 5.f);
      } 
      color.rgb *= ((1 - j) * fog);
   }
//   color.r = texture(texBuf, texCoord + vec2(7.0,0.0)/512.0).r; //new5
//   color.g = texture(texBuf, texCoord + vec2(4.0,0.0)/512.0).g; //new5
//   color.b = texture(texBuf, texCoord + vec2(1.0,0.0)/512.0).b; //new5
   color.a = 1.0;


   //blur
	for (int i=1; i <5; i ++) {
			color += vec4(texture( texBuf, texCoord + vec2(offset[i], 0.0)/512.0 ).rgb, 1)*weight[i];
			color += vec4(texture( texBuf, texCoord - vec2(offset[i], 0.0)/512.0 ).rgb, 1)*weight[i];
			
         color += vec4(texture( texBuf, texCoord + vec2(0.0 ,offset[i])/512.0 ).rgb, 1)*weight[i]; //new5
			color += vec4(texture( texBuf, texCoord - vec2(0.0, offset[i])/512.0 ).rgb, 1)*weight[i]; //new5
	}
   color /= 2.55; //new5
 
}
