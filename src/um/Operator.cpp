#include <um/Operator.h>
#include <iostream>
using namespace std;

um::Operator::Operator()
{
    //ctor
}

um::Operator::~Operator()
{
    //dtor
}

void um::Operator::onAction(Action act)
{

}

int um::Operator::onUpdate(float dt)
{
    return 1;
}
