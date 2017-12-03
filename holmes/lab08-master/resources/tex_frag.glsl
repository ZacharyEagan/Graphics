#version 330 core

in vec2 texCoord;
out vec4 color;
uniform sampler2D texBuf_color;
uniform sampler2D texBuf_norm;
uniform sampler2D texBuf_pos;

/* just pass through the texture color we will add to this next lab */
void main(){
  
   vec3 pos = texture (texBuf_pos, texCoord).xyz;
   vec3 norm = normalize(texture (texBuf_norm, texCoord).xyz);
   vec4 col = vec4(texture (texBuf_color, texCoord).rgb, 1);
   //col = vec4(0.f);

   vec3 cur, cur2;   
   float t = 0.0f;
   int cont = 1;
   
   while ((cur = pos + norm * t).x < 1.f && cur.x > 0.f && 
           cur.y < 1.f && cur.y > 0.f)
   {
      cur2 = texture(texBuf_pos, cur.xy).xyz;
      if (cur.z + 0.1 > cur2.z && cur.z - 0.1 < cur2.z)
         col.rgb += texture(texBuf_color, cur.xy).rgb * 0.001;    
      t += 0.001f;
   } 

   color = min (vec4(1.f), col);
}
