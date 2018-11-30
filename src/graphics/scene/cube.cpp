#include "cube.h"
#include <iostream>



namespace mike { namespace graphics {

Cube::Cube(glm::vec3 position, glm::vec3 orientation, glm::vec3 scale, TextureAtlas* texture)
:Renderable3D(position,orientation,scale,texture)
{
    float CubeVertices[] =
 {
//front
     0.0 , 0.0 , 1.0,
     1.0 , 0.0 , 1.0,
     1.0, 1.0 , 1.0,
     0.0 ,  1.0 , 1.0,
//back
     0.0 , 0.0 , 0.0,
     1.0 , 0.0 , 0.0,
     1.0, 1.0 , 0.0,
     0.0 ,  1.0 , 0.0,
//left
     0.0, 0.0, 0.0,
     0.0, 0.0, 1.0,
     0.0, 1.0, 1.0,
     0.0, 1.0, 0.0,
//right
     1.0, 0.0, 1.0,
     1.0, 0.0, 0.0,
     1.0, 1.0, 0.0,
     1.0, 1.0, 1.0,
//top
     0, 1, 1,
     1, 1, 1,
     1, 1, 0,
     0, 1, 0,
//bottom
     0, 0, 0,
     1, 0, 0,
     1, 0, 1,
     0, 0, 1
 };
float CubeTexcoord[] =
 {
      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,

      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,

      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,

      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,

      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,

      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,
 };
unsigned int CubeIndexes[] =
{
  //front
  0,1,2,
  2,3,0,

  4,5,6,
  6,7,4,

  8,9,10,
  10,11,8,

  12,13,14,
  14,15,12,

  16,17,18,
  18,19,16,

  20,21,22,
  22,23,20
};

m_vao = new VertexArray();
m_vao->bind();
Buffer *vbo= new Buffer(CubeVertices,6*4,3);
Buffer *cbo = new Buffer(CubeTexcoord,6*4,2);
m_vao->addBuffer(vbo,0);
m_vao->addBuffer(cbo,1);
m_vao->unbind();
delete vbo;
delete cbo;
m_ibo =new IndexBuffer(CubeIndexes,3*2*6);

}

Cube::~Cube()
{
    delete m_vao;
    delete m_ibo;
    delete m_texture;
    std::cout<<"cube destroyed"<<std::endl;
}


void Cube::draw()
{
    bind();

    glDrawElements(GL_TRIANGLES,32,GL_UNSIGNED_INT,(const void*)(0*sizeof(GLuint)));
    unbind();

}



}}
