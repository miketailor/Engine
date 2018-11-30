#include "scene.h"

namespace mike { namespace graphics {


Scene::Scene(int width, int height,Shader *screenShader)
:screenShader(screenShader)
{
frameBuffer = new FrameBuffer(width,height);

}

Scene::~Scene()
{
delete frameBuffer;
}
void Scene::addObject(Renderable3D *object)
{
objects.push_back(object);
}

void Scene::draw()
{
/*
       objectShader->enable();
       objectShader->setUniformMat4("Projection",Projection);
       objectShader->setUniformMat4("View",View);
       objectShader->setUniformMat4("Model",Model);
*/

for (Renderable3D *o : objects)
{
   objectShader->setUniformMat4("Model",o->getModelMatrix());
   o->draw();
}

}



}
}
