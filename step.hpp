#ifndef STEP_HPP
#define STEP_HPP

#include <iostream>
#include <memory>
#include <list>
#include <algorithm>


struct StepStructure
{
    StepStructure(int objectType, size_t num, double time, int stepNumber, size_t numSource,  size_t numApp)
    {
        objectType_ = objectType;
        num_ = num;
        time_ = time;
        stepNumber_ = stepNumber;
        numSource_ = numSource;
        numApp_ = numApp;
    }

public:
    int objectType_;
    size_t num_;
    double time_;
    int stepNumber_;
    size_t numSource_;
    size_t numApp_;
};
//static std::shared_ptr<std::list<StepStructure>> StepList;
//std::vector<std::shared_ptr<StepStructure>> SList;
//std::list<StepStructure> StepLis;
extern std::list<StepStructure> *StepList ;

#endif // STEP_HPP
