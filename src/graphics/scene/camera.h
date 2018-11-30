#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED


#include "../../maths/glm_include.h"

namespace mike {
namespace graphics{

class Camera {
private:
    glm::vec3 m_position;
    glm::vec3 m_orientation;
    glm::vec4 m_view;



public:
    Camera(glm::vec3 position, glm::vec3 lookAt,glm::vec3 headUp);
    ~Camera();
    void move(glm::vec3 position, glm::vec3 rotation);
    void set(glm::vec3 position,glm::vec3 lookAt,glm::vec3 headUp);


};

}

}

#endif // CAMERA_H_INCLUDED
