#ifndef ISTATE_H_INCLUDED
#define ISTATE_H_INCLUDED

namespace mike { namespace state {
class IState
{
public:
    IState() {};
    virtual ~IState() {};

   virtual void init()=0;
   virtual void update()=0;
   virtual void draw()=0;
   virtual void close()=0;


private:



};

}}

#endif // ISTATE_H_INCLUDED
