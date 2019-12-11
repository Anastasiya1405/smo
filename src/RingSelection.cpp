
#include "../headers/RingSelection.hpp"
#include <iostream>
#include "../headers/FunctionalModule.hpp"
#include "step.hpp"
// std::list<StepStructure> StepList;
RingSelection::RingSelection():
  elPointer_(0)
{}

std::shared_ptr<Application>
RingSelection::removeApplication(std::vector<std::shared_ptr<Application>> &applications)
{
  std::shared_ptr<Application> fromPointerToEnd = RingSelection::search(applications, elPointer_, applications.size());
  if (fromPointerToEnd == nullptr) {
    return RingSelection::search(applications, 0, elPointer_);
  } else {
    return fromPointerToEnd;
  }
}

void RingSelection::movePointer(const size_t &bufferSize, const size_t &pointerPosition)
{
    //std::cout<< "Шаг :" << FunctionalModule::count << '\n';
    //count++;
  std::cout << "Уход из Буфера №" << elPointer_ + 1;
  if (pointerPosition == bufferSize) {
    elPointer_ = 0;
  } else {
    elPointer_ = pointerPosition + 1;
  }
}

std::shared_ptr<Application> RingSelection::search(std::vector<std::shared_ptr<Application>> &applications,
                                                   const size_t &fromIndex, const size_t &toIndex) {
  for (size_t i = fromIndex; i < toIndex; i++)
  {
    if (applications[i] != nullptr) {
      const std::shared_ptr<Application> applicationToRemove = applications[i];
      applications[i] = nullptr;
      movePointer(applications.size(), i);
      StepList->push_back(* (new StepStructure(1, applicationToRemove->bufferNumber_,
                                              applicationToRemove->getTimeOfCreation(),
                                              count,
                                              applicationToRemove->getSourceIndex(),
                                              -1)) );
     std::cout << " От Источника №" << applicationToRemove->getSourceIndex() + 1 << " = " << applicationToRemove->getTimeOfCreation() << '\n';
     // std::cout << " От Источника №" << applicationToRemove->getSourceIndex() + 1 << " = " << data_.timeNow << '\n';

     std::cout <<"beg "<< StepList->front().time_ << '\n';
     std::cout <<"beg "<< StepList->front().numSource_ +1<< '\n';
     std::cout <<"end "<< StepList->back().time_ << '\n';
     std::cout <<"end "<< StepList->back().numSource_+1 << '\n';
      return applicationToRemove;
    }
  }
  return nullptr;
}
