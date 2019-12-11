#include "../headers/RingAdd.h"
#include <iostream>
//#include "step.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/FunctionalModule.hpp"

//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/FunctionalModule.hpp"
//std::list<StepStructure> StepList;
RingAdd::RingAdd():
  elementPointer_(0)
{}

size_t RingAdd::getPointer(size_t p)
{
    elementPointer_ = p;
}

bool RingAdd::addApplication(std::vector<std::shared_ptr<Application>> &applications, const std::shared_ptr<Application> &applicationToAdd)
{
  bool fromPointerToEnd = RingAdd::search(applications,applicationToAdd, elementPointer_, applications.size());
  if (!fromPointerToEnd ) {
    return RingAdd::search(applications, applicationToAdd,  0, elementPointer_);
  } else {
    return true;
  }
}

void RingAdd::movePointer(const size_t &bufferSize, const size_t &pointerPosition)
{
   // std::cout<< "Шаг :" << FunctionalModule::count << '\n';
    //count++;
  std::cout << "Приход в Буфер №" << pointerPosition + 1;
  if (pointerPosition == bufferSize) {
    elementPointer_ = 0;
  } else {
    elementPointer_ = pointerPosition + 1;
  }

}

bool RingAdd::search(std::vector<std::shared_ptr<Application>> &applications,const  std::shared_ptr<Application> &applicationToAdd,
                                                   const size_t &fromIndex, const size_t &toIndex)
{
  for (size_t i = fromIndex; i < toIndex; i++)
  {
      for (auto &application : applications) {
        if (application == nullptr) {
          application = applicationToAdd;
          application->bufferNumber_ = elementPointer_;
          movePointer(applications.size(), i);
          StepList->push_back(* (new StepStructure(1, application->bufferNumber_,
                                                  applicationToAdd->getTimeOfCreation(),
                                                  count,
                                                  application->getSourceIndex(),
                                                  -1)) );

          std::cout << " От Источника №" << applicationToAdd->getSourceIndex() + 1 << " = " << applicationToAdd->getTimeOfCreation() << '\n';
          std::cout <<"beg "<< StepList->front().time_ << '\n';
          std::cout <<"beg "<< StepList->front().numSource_ +1<< '\n';
          std::cout <<"end "<< StepList->back().time_ << '\n';
          std::cout <<"end "<< StepList->back().numSource_+1 << '\n';
          std::cout << '\n';
          return true;
        }
      }
      return false;
    }
}
