#include "buffer.h"



namespace mike {namespace graphics{

Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
:componentCount(componentCount)
{
    glGenBuffers(1,&bufferID);
    bind();
    glBufferData(GL_ARRAY_BUFFER,count*componentCount*sizeof(GLfloat), data, GL_STATIC_DRAW);
    unbind();
}

Buffer::~Buffer()
{
    glDeleteBuffers(1,&bufferID);
}



void Buffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER,bufferID);
}

void Buffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}




}}
