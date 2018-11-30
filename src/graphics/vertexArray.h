#ifndef VERTEXARRAY_H_INCLUDED
#define VERTEXARRAY_H_INCLUDED
#include <vector>
#include "GL/glew.h"
#include "buffer.h"

namespace mike{ namespace graphics{


class VertexArray {

private:
    unsigned int m_bufferID;
    unsigned int m_bufferCount;
    std::vector<Buffer*> buffers;
public:
    VertexArray();
    ~VertexArray();
    void bind() const;
    void addBuffer(Buffer *buffer, unsigned int index);
    void unbind() const;



};


}}


#endif // VERTEXARRAY_H_INCLUDED
