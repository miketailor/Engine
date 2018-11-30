#version 330 core

layout (location =0) in vec3 position;
layout (location =1) in vec2 texture;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;


out vec2 tex_uv;


void main()
{
tex_uv = texture;
  gl_Position =Projection*View*Model*vec4(position.x,position.y,position.z,1);

}
