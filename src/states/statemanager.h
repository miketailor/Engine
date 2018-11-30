#ifndef STATEMANAGER_H_INCLUDED
#define STATEMANAGER_H_INCLUDED
#include "istate.h"
#include <memory>
#include <stack>

namespace mike { namespace state{

class StateManager {
private:
std::stack<std::unique_ptr<IState>> states;

public:
    StateManager();
    ~StateManager();
    void pushState(std::unique_ptr<IState> state);
    void popState();
    void update();
    void draw();

};



}}


#endif // STATEMANAGER_H_INCLUDED
