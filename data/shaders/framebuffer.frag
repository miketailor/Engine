#version 330 core


layout (location = 0) out vec4 outColour;
in  vec2 tex_uv;

uniform sampler2D screenSampler;
//const float offset = 1.0 / 500.0;

void main()
{
/*    vec2 offsets[9] = vec2[](
        vec2(-offset,  offset), // top-left
        vec2( 0.0f,    offset), // top-center
        vec2( offset,  offset), // top-right
        vec2(-offset,  0.0f),   // center-left
        vec2( 0.0f,    0.0f),   // center-center
        vec2( offset,  0.0f),   // center-right
        vec2(-offset, -offset), // bottom-left
        vec2( 0.0f,   -offset), // bottom-center
        vec2( offset, -offset)  // bottom-right
    );
*/
/*
float kernel[9] = float[](
1.0, 1.0, 1.0,
1.0, 1.0, 1.0,
1.0, 1.0, 1.0
);

    vec3 sampleTex[9];
    for(int i = 0; i < 9; i++)
    {
        sampleTex[i] = vec3(texture(screenSampler, tex_uv.st + offsets[i]));
    }
    vec3 col = vec3(0.0);
    for(int i = 0; i < 9; i++)
        col += sampleTex[i] * kernel[i];
*/
vec3 col = texture(screenSampler,tex_uv).rgb;
    outColour  = vec4(col, 1.0);
}
