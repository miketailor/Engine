#ifndef RENDERABLE2D_H_INCLUDED
#define RENDERABLE2D_H_INCLUDED

#include "../../maths/glm_include.h"
class Renderable2D
{
private:
    float m_positionX;
    float m_positionY;
    float m_positionZ;
    float m_sizex;
    float m_sizey;
    TextureAtlas *m_texture;
    int m_textureX;
    int m_textureY;

public:
    Renderable2D(float x, float y, float z, float sX, float sY, TextureAtlas *texture, int tX, int tY)
    :m_positionX(x),m_positionY(y),m_positionZ(z),m_sizex(sX),m_sizey(mY),m_texture(texture),m_textureX(tX),m_textureY(tY)
    { };
    ~Renderable2D();



};

#endif // RENDERABLE2D_H_INCLUDED
