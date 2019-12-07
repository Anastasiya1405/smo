#ifndef RINGADD_H
#define RINGADD_H

#include "../headers/AdditionStrategy.hpp"

class RingAdd: public AdditionStrategy {
public:
  explicit RingAdd();
  bool addApplication(std::vector<std::shared_ptr<Application>> &applications, const std::shared_ptr<Application> &applicationToAdd);

public:
  size_t elementPointer_;

  bool search(std::vector<std::shared_ptr<Application>> &applications, const std::shared_ptr<Application> &applicationToAdd,
                                      const size_t &fromIndex, const size_t &toIndex);
  void movePointer(const size_t &bufferSize, const size_t &pointerPosition);
};

#endif // RINGADD_H
