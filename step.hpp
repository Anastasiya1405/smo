#ifndef STEP_HPP
#define STEP_HPP

#include <iostream>
#include <memory>
#include <list>


struct StepStructure
{

    int objectType;
    int num;
    double time;
    int stepNumber;
    int numSource;
    int numApp;
};

class Step
{
public:
    Step();
    static std::list<std::shared_ptr <StepStructure>> StepList;

};

#endif // STEP_HPP
