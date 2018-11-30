#version 330 core


layout (location = 0) out vec4 outColour;
in  vec2 tex_uv;

uniform sampler2D texSampler;

void main()
{


        vec4 color = texture(texSampler, tex_uv);
        outColour = color ;



}
