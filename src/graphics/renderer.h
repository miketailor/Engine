#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED
#include

namespace mike {    namespace graphics {
class Renderer
{
private:

public:
    Renderer();
    virtual ~Renderer;
    void draw(Renderable3D *object);
    void draw(Renderable2D *object);
    void flush();

};
}}

#endif // RENDERER_H_INCLUDED
