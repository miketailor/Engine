#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#include "renderable3D.h"

namespace mike { namespace graphics {


class Cube : public Renderable3D{



public:
 Cube(glm::vec3 position, glm::vec3 orientation, glm::vec3 scale, TextureAtlas* texture);
 ~Cube();
void draw();
};


}
}

#endif // CUBE_H_INCLUDED
