#ifndef INDEXBUFFER_H_INCLUDED
#define INDEXBUFFER_H_INCLUDED
#include <GL/glew.h>

namespace mike { namespace graphics

{

class IndexBuffer
{
private:
   unsigned int m_bufferID;
   unsigned int m_indexCount;
public:
    IndexBuffer(unsigned int *data,unsigned int count);
    ~IndexBuffer();
    void bind();
    void unbind();

};


}
}







#endif // INDEXBUFFER_H_INCLUDED
