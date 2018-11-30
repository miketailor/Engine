#include "statemanager.h"

//TODO: this should probably be a Singleton

namespace mike { namespace state {

StateManager::StateManager()
{

}

StateManager::~StateManager()
{

}

void StateManager::pushState(std::unique_ptr<IState>state)
{
    state->init();
    states.push(std::move(state));
}


void StateManager::popState()
{
    states.top()->close();
    states.pop();
}


void StateManager::update()
{
    states.top()->update();
}

void StateManager::draw()
{
    states.top()->draw();

}



}
}
