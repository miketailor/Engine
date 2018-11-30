#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
#include <GL/glew.h>

namespace mike {namespace graphics{

class Buffer
{
private:
    GLuint bufferID;
    GLuint componentCount;
public:
    Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
    ~Buffer();
    void bind() const;
    void unbind() const;
    GLuint getComponentCount() const {return componentCount;};
    inline unsigned int getID() const {return bufferID;};
};




}}

#endif // BUFFER_H_INCLUDED
