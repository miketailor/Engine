#ifndef FRAMEBUFFER_H_INCLUDED
#define FRAMEBUFFER_H_INCLUDED
#include "texture.h"


namespace mike { namespace graphics {

class FrameBuffer {
private:
    unsigned int m_ID;
    Texture *m_texture;
    unsigned int m_rbo;

public:
    FrameBuffer(int width, int height);
    ~FrameBuffer();
    void bind();
    void unbind();
    void bindTexture(){m_texture->bind();};


};


}
}

#endif // FRAMEBUFFER_H_INCLUDED
