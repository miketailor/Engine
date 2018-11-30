#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED
#include <GL/glew.h>

namespace mike { namespace graphics
{
    class Texture {

private:
    unsigned int m_ID;
    char *m_file;
    bool m_valid;
    int m_width;
    int m_height;
public:
    Texture(char *file);
    Texture(int width, int height);
    ~Texture();
    void bind();
    void unbind();
    inline bool isValid() const {return m_valid;};
    inline unsigned int getID() const {return m_ID;};
    inline int getWidth() {return m_width;};
    inline int getHeight() {return m_height;};

    };
}

}

#endif // TEXTURE_H_INCLUDED
