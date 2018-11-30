#ifndef MASTERRENDERER_H_INCLUDED
#define MASTERRENDERER_H_INCLUDED

namespace mike { namespace graphics {

class MasterRenderer {

private:

    unsigned int FBIndexes[6];
    float FBVertices[8];
    float FBtexture[8];

public:
    MasterRenderer(int width, int height);
    ~MasterRenderer();



};


}

}

#endif // MASTERRENDERER_H_INCLUDED
