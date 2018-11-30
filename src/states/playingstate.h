#ifndef PLAYINGSTATE_H_INCLUDED
#define PLAYINGSTATE_H_INCLUDED

#include "istate.h"


namespace mike { namespace state {

class PlayingState : public IState{
     PlayingState() ;
    ~PlayingState() ;

    void init();
    void update();
    void draw();
    void close();

};




}   }


#endif // PLAYINGSTATE_H_INCLUDED
