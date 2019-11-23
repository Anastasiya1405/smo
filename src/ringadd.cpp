#include "RingAdd.h"

RingAdd::RingAdd():
  elementPointer_(0)
{}

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
          movePointer(applications.size(), i);
          return true;
        }
      }
      return false;
    }
}
