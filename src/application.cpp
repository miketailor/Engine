#include "application.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "graphics/shader.h"
#include "graphics/texture.h"
#include "graphics/textureAtlas.h"
#include "graphics/frameBuffer.h"
#include "graphics/vertexArray.h"
#include "graphics/buffer.h"
#include "graphics/indexBuffer.h"
#include "graphics/scene/cube.h"
#include "graphics/scene/scene.h"
#include "states/statemanager.h"


namespace mike {

Application::Application()
{

}

Application::~Application()
{

}

void Application::init()
{
window = new graphics::Window("TEST",1600,900);
stateManager = new state::StateManager();


}

void Application::run()
{
 unsigned int FBIndexes[] =
 {
    0,1,2,
    2,3,0,
 };

float FBVertices[] =
{
-1.0, 1.0,
-1.0, -1.0,
1.0,-1.0,
1.0, 1.0,

};

float FBtexture[] =
{
    0.0, 1.0,
    0.0, 0.0,
    1.0, 0.0,
    1.0, 1.0,
};



graphics::Shader shader("data/shaders/basic.vert","data/shaders/basic.frag");
graphics::Shader screenShader("data/shaders/framebuffer.vert","data/shaders/framebuffer.frag");

graphics::FrameBuffer framebuffer(1600,900);


graphics::TextureAtlas texture((char *)"data/textures/atlas.png",1024);
//glm::vec4 texCoords = texture.getCoordinates(1,1);


graphics::Cube cube(glm::vec3(0.0,0.0,0.0), glm::vec3(0.5,0.0,0.0), glm::vec3(1.0,1.0,1.0), &texture);
graphics::Cube cube1(glm::vec3(2.0,1.0,0.0), glm::vec3(0.0,0.5,0.0), glm::vec3(1.0,1.0,1.0), &texture);
graphics::Cube cube2(glm::vec3(0.0,-1.0,0.0), glm::vec3(0.0,0.0,0.5), glm::vec3(0.5,0.5,0.5), &texture);


graphics::VertexArray FBvao;
FBvao.bind();
graphics::Buffer *FBvbo= new graphics::Buffer(FBVertices,1*4,2);
graphics::Buffer *FBcbo = new graphics::Buffer(FBtexture,1*4,2);

FBvao.addBuffer(FBvbo,0);
FBvao.addBuffer(FBcbo,1);
graphics::IndexBuffer FBibo(FBIndexes,3*2*1);





glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float) 1600 / (float)900, 0.1f, 100.0f);

glm::mat4 View = glm::lookAt(
    glm::vec3(4,3,1), // Camera is at
    glm::vec3(0,0,0), // and looks at
    glm::vec3(0,1,0)  // Head is
    );



glm::mat4 Model = glm::mat4(1.0f);
glm::mat4 mvp;


graphics::Scene *scene= new graphics::Scene(1600,900,&shader);

scene->addObject(&cube);
scene->addObject(&cube1);
scene->addObject(&cube2);

 double lastTime = glfwGetTime();
 int nbFrames = 0;

while (!window->isClosed())
{

//FPS counter
double currentTime = glfwGetTime();
     nbFrames++;
     if ( currentTime - lastTime >= 1.0 ){ // If last prinf() was more than 1 sec ago
         // printf and reset timer
         printf("%f ms/frame\n", 1000.0/double(nbFrames));
         nbFrames = 0;
         lastTime += 1.0;
     }
//end FPS counter




    if (window->isKeyPressed(GLFW_KEY_W))
        View = glm::translate(View,glm::vec3(0.1,0,0));
    if (window->isKeyPressed(GLFW_KEY_S))
        View = glm::translate(View,glm::vec3(-0.1,0,0));
    if (window->isKeyPressed(GLFW_KEY_A))
        View = glm::translate(View,glm::vec3(0,0,0.1));
    if (window->isKeyPressed(GLFW_KEY_D))
        View = glm::translate(View,glm::vec3(0,0,-0.1));
    if (window->isKeyPressed(GLFW_KEY_Q))
        break;




    window->centerMousePosition();
       shader.enable();
       mvp = Projection * View * Model;
       shader.setUniformMat4("Projection",Projection);
       shader.setUniformMat4("View",View);
       shader.setUniformMat4("Model",Model);



    glEnable(GL_DEPTH_TEST);
    framebuffer.bind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);





    shader.setUniformMat4("Model",cube.getModelMatrix());
    cube.draw();
    shader.setUniformMat4("Model",cube1.getModelMatrix());
    cube1.draw();
    shader.setUniformMat4("Model",cube2.getModelMatrix());
    cube2.draw();




    framebuffer.unbind();
    glDisable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    screenShader.enable();
    FBvao.bind();
    FBibo.bind();
    framebuffer.bindTexture();

    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,(const void*)(0*sizeof(GLuint)));


 window->update();


}

}

void Application::close()
{

}




}
