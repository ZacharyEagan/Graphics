#version 330 core
uniform vec2 uWindowSize;
out vec3 color;

in vec3 vertex_color;
//uniform vec2 uWindowSize;
uniform float uTime; 

void main()
{
   
   gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
   vec4 white = vec4(1.0, 1.0, 1.0 , 1.0);

   vec2 cent = uWindowSize / 2.0;
   cent.y = cent.y * (sin(uTime / 2) / 2) + cent.y;
   cent.x = cent.x * (cos(uTime / 2) / 2) + cent.x;

   if (length(gl_FragCoord.xy - cent) > 20) 
   {
      if (gl_FragCoord.y < (uWindowSize.y / 2))
      {
         gl_FragColor.r = sin(uTime / 2) * (gl_FragCoord.x / uWindowSize.x);
         gl_FragColor.b = sin(uTime / 3) * (gl_FragCoord.y / uWindowSize.y);
         gl_FragColor.g = sin(uTime / 7) * (gl_FragCoord.x/uWindowSize.x  + gl_FragCoord.y / uWindowSize.y);
      }  
      else
      {
         gl_FragColor.b = 1.0;
      }
      gl_FragColor.rgb += white.rgb * (length((gl_FragCoord.xy - cent) / (uWindowSize / 2)) );
      if(gl_FragColor.r > 1.0)
         gl_FragColor.r = 1.0;
      if(gl_FragColor.g > 1.0)
         gl_FragColor.g = 1.0;
      if(gl_FragColor.b > 1.0)
         gl_FragColor.b = 1.0;
   }
   else
   {
      gl_FragColor = white;
   }
}
