#include "masterrenderer.h"

namespace mike { namespace graphics {


MasterRenderer::MasterRenderer(int width, int height)
:FBIndexes({0,1,2,2,3,0,})
,FBVertices({-1.0, 1.0,-1.0, -1.0,1.0,-1.0,1.0, 1.0,})
,FBtexture({0.0, 1.0,0.0, 0.0,1.0, 0.0,1.0, 1.0})
{

}





MasterRenderer::~MasterRenderer()
{

}






}}
