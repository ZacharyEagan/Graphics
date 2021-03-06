#version 330 core

in vec2 texCoord;
out vec4 color;
uniform sampler2D texBuf;
uniform vec2 dir;
uniform vec2 XYMAX;

uniform float offset[5] = float[]( 0.0, 1.0, 2.0, 3.0, 4.0 );
uniform float weight[5] = float[]( 0.2270270270, 0.1945945946, 0.1216216216, 
											0.0540540541, 0.0162162162 );

void main(){

   color = vec4(texture( texBuf, texCoord ).rgb, 1)*weight[0];

   color.r = texture(texBuf, texCoord + vec2(7.0,0.0)/512.0).r; //new5
   color.g = texture(texBuf, texCoord + vec2(4.0,0.0)/512.0).g; //new5
   color.b = texture(texBuf, texCoord + vec2(1.0,0.0)/512.0).b; //new5
   color.a = 1.0;

	for (int i=1; i <5; i ++) {
			color += vec4(texture( texBuf, texCoord + vec2(offset[i], 0.0)/512.0 ).rgb, 1)*weight[i];
			color += vec4(texture( texBuf, texCoord - vec2(offset[i], 0.0)/512.0 ).rgb, 1)*weight[i];
			
         color += vec4(texture( texBuf, texCoord + vec2(0.0 ,offset[i])/512.0 ).rgb, 1)*weight[i]; //new5
			color += vec4(texture( texBuf, texCoord - vec2(0.0, offset[i])/512.0 ).rgb, 1)*weight[i]; //new5
	}
   color /= 2.55; //new5
   if (gl_FragCoord.x >= XYMAX.x - 10 || gl_FragCoord.y >= (XYMAX.y - 10) || 
       gl_FragCoord.x <= 10 || gl_FragCoord.y <= 10)
      color = vec4(0,0,0,0);
 
}
