#include "camera.h"

namespace mike{
namespace graphics{

void Camera::move(glm::vec3 position, glm::vec3 rotation)
{

}

void Camera::set(glm::vec3 position, glm::vec3 lookAt, glm::vec3 headUp)
{

}
Camera::Camera(glm::vec3 position, glm::vec3 lookAt, glm::vec3 headUp)
{
    set(position,lookAt,headUp);
}

Camera::~Camera()
{

}



}
}
