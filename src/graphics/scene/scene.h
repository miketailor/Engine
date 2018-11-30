#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "../frameBuffer.h"
#include "renderable3D.h"
#include <vector>
#include "../shader.h"

namespace mike { namespace graphics {


class Scene
{

private:
    std::vector<Renderable3D *> objects;
    FrameBuffer *frameBuffer;
    Shader *screenShader;
    Shader *objectShader;
public:
    Scene(int width, int height,Shader *sceneShader);
    ~Scene();

  //  void addObject(Renderable3D object);
    void draw();
    void addObject(Renderable3D *object);
    inline void setObjectShader(Shader *shader) {objectShader=shader;};

};



}
}

#endif // SCENE_H_INCLUDED
