#ifndef TEXTUREATLAS_H_INCLUDED
#define TEXTUREATLAS_H_INCLUDED

#include "texture.h"
#include "../maths/glm_include.h"

namespace mike { namespace graphics
{

 class TextureAtlas {

 private:
 Texture *m_texture;
 int m_textureSize;
 float m_textureWidth;
 float m_textureHeight;


 public:
 TextureAtlas(char *file, int textureSize);
 ~TextureAtlas();
 glm::vec4 getCoordinates(int x, int y);
 inline void bind() { m_texture->bind();};
 inline void unbind() { m_texture->unbind();};
 };


}
}

#endif // TEXTUREATLAS_H_INCLUDED
