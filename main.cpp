#include "src/application.h"

int main( int argc, char** args )
{
using namespace mike;

Application app;

app.init();
app.run();
app.close();

}
