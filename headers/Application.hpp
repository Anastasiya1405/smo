
#ifndef SMO_APPLICATION_HPP
#define SMO_APPLICATION_HPP

#include <memory>

class Application {
public:
  Application(const size_t &sourceNumber, const double &timeOfCreation);

  size_t getSourceIndex() const noexcept;
  size_t getBufferIndex() const noexcept;
  double getTimeOfCreation() const noexcept;

  size_t bufferNumber_;

private:
  size_t sourceNumber_;
  //size_t bufferNumber_;
  double timeOfCreation_;
};


#endif //SMO_APPLICATION_HPP
