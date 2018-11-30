#include "textureAtlas.h"

namespace mike { namespace graphics {
TextureAtlas::TextureAtlas(char* file, int textureSize)
:m_textureSize(textureSize)
{
m_texture = new Texture(file);

m_textureWidth = (float)m_textureSize / (float)m_texture->getWidth();
m_textureHeight = (float)m_textureSize / (float)m_texture->getHeight();

}


TextureAtlas::~TextureAtlas()
{
    delete m_texture;
}

glm::vec4 TextureAtlas::getCoordinates(int x, int y)
{
float minX, minY, maxX, maxY;
minX=(float)x*m_textureWidth;
minY=(float)y*m_textureHeight;
maxX= (float)(x+1)*m_textureWidth;
maxY= (float)(y+1)*m_textureHeight;

return {minX,minY,maxX, maxY};

}



}
}
