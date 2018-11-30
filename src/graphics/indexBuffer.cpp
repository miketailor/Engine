#include "indexBuffer.h"


namespace mike { namespace graphics {



IndexBuffer::IndexBuffer(unsigned int* data, unsigned int count)
:m_indexCount(count)
{
glGenBuffers(1,&m_bufferID);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_bufferID);
glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_indexCount*sizeof(GLuint),data,GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
glDeleteBuffers(1,&m_bufferID);
}

void IndexBuffer::bind()
{
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_bufferID);

}

void IndexBuffer::unbind()
{
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

}




}}
