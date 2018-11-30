#include "vertexArray.h"


namespace mike { namespace graphics {

VertexArray::VertexArray()
{
glGenVertexArrays(1,&m_bufferID);
}

VertexArray::~VertexArray()
{
    for (auto buffer:buffers)
    {
       //delete buffer;
    }
}

void VertexArray::bind() const
{
glBindVertexArray(m_bufferID);
}

void VertexArray::addBuffer(Buffer* buffer, unsigned int index)
{
    bind();
buffer->bind();
glVertexAttribPointer(index,buffer->getComponentCount(),GL_FLOAT,GL_FALSE,0,0);
glEnableVertexAttribArray(index);
buffer->unbind();
unbind();
buffers.push_back(buffer);
}

void VertexArray::unbind() const
{
glBindVertexArray(0);
}



}
}
