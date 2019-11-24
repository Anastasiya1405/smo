
#include <stdexcept>
#include <iostream>
#include "../headers/TimeBehaviour.hpp"

double ExponentialTimeBehavior::generateTime(const double &intensity) {
  if (intensity < 0) {
    throw std::invalid_argument("Intensity should be > 0");
  }
  const double randomValue = ((double) std::rand() / (RAND_MAX));
  return 1 - std::exp(-(randomValue / intensity));
}

double PuassonTime::generateTime(const double &intensity)
{
    if (intensity < 0) {
      throw std::invalid_argument("Intensity should be > 0");
    }
    const double randomValue = ((double) std::rand() / (RAND_MAX));
    //std:: cout  << "P  " <<  ((-1.0/ intensity) * std::log(randomValue)) << '\n';
    return ((-1.0/ intensity) * std::log(randomValue));
}
double InfiniteUniformTimeBehavior::generateTime(const double &intensity) {
  if (intensity < 0) {
    throw std::invalid_argument("Intensity should be > 0");
  }
  double randomValue = ((double) std::rand() / (RAND_MAX));
 // std:: cout  <<  a_ + randomValue * (b_ - a_) << '\n';
  return a_ + randomValue * (b_ - a_);
}

InfiniteUniformTimeBehavior::InfiniteUniformTimeBehavior(const double &a, const double &b):
  a_(a),
  b_(b)
{
  if (b < a){
    throw std::invalid_argument("b should be more than a");
  }
}
