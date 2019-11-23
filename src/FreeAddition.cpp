
#include "../headers/FreeAddition.hpp"

bool FreeAddition::addApplication(std::vector<std::shared_ptr<Application>> &applications,
                                  const std::shared_ptr<Application> &applicationToAdd)
{
  for (auto &application : applications) {
    if (application == nullptr) {
      application = applicationToAdd;
      return true;
    }
  }
  return false;
}
