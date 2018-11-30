#include "texture.h"

#include "../../3rdparty/stb_image/stb_image.h"
#include <iostream>

namespace mike { namespace graphics{


Texture::Texture(char* file)
:m_file(file)
{
glGenTextures(1, &m_ID);
bind();
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
int nrChannels;
unsigned char *data = stbi_load(m_file, &m_width, &m_height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    m_valid=true;
    std::cout << "loaded texture" << std::endl;
}
else
{
    std::cout << "Failed to load texture" << std::endl;
    m_valid=false;
}
stbi_image_free(data);
}


Texture::Texture(int width, int height)
:m_width(width)
,m_height(height)
{
glGenTextures(1, &m_ID);
bind();
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

}





Texture::~Texture()
{
glDeleteTextures(1,&m_ID);
}

void Texture::bind()
{
glBindTexture(GL_TEXTURE_2D, m_ID);

}

void Texture::unbind()
{
glBindTexture(GL_TEXTURE_2D, 0);

}

}
}
