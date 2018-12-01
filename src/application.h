#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "graphics/window.h"


namespace mike {
class Application
{
private:
    graphics::Window* window;

public:
    Application();
    ~Application();
    void init();
    void run();
    void close();




};
}
#endif // APPLICATION_H_INCLUDED
