#ifndef RENDERABLE3D_H_INCLUDED
#define RENDERABLE3D_H_INCLUDED

#include "../vertexArray.h"
#include "../textureAtlas.h"
#include "../indexBuffer.h"
#include "../../maths/glm_include.h"
#include <iostream>


namespace mike { namespace graphics {
class Renderable3D
{
protected:

VertexArray *m_vao;
IndexBuffer *m_ibo;
TextureAtlas *m_texture;
glm::vec3 m_position;
glm::quat m_orientation;
glm::vec3 m_scale;

glm::mat4 Model;
public:
    Renderable3D(glm::vec3 position, glm::quat orientation, glm::vec3 scale, TextureAtlas* texture)
    :m_position(position),m_orientation(orientation),m_scale(scale),m_texture(texture){};

    ~Renderable3D() {};

    void bind() {
    m_vao->bind();
    m_ibo->bind();
    m_texture->bind();
    };


    void unbind() {m_vao->unbind();m_ibo->unbind();m_texture->unbind();};
    virtual void draw()=0;
    inline glm::vec3 getposition() {return m_position;};
    glm::mat4 getModelMatrix()
    {
        Model = glm::mat4(1.0f);
        Model = glm::translate(Model,m_position);
     //   Model = glm::rotate(Model,m_orientation);
        Model = glm::scale(Model,m_scale);
        return Model;

    }
};
}
}

#endif // RENDERABLE3D_H_INCLUDED
