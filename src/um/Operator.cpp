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

int um::Operator::onAction(Action act)
{
    return 0;
}

int um::Operator::onUpdate(float dt)
{
    return 1;
}
