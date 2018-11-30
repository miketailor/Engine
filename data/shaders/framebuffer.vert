#version 330 core

layout (location =0) in vec3 position;
layout (location =1) in vec2 texture;

out vec2 tex_uv;


void main()
{
  tex_uv = texture;
  gl_Position =vec4(position.x,position.y,0,1);

}
