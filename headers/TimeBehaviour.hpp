

#ifndef SMO_TIMEBEHAVIOUR_HPP
#define SMO_TIMEBEHAVIOUR_HPP

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

class TimeBehaviour {
public:
  virtual double generateTime(const double &intensity) = 0;
};

class ExponentialTimeBehavior: public TimeBehaviour {
public:
  double generateTime(const double &intensity) override;
};


class InfiniteUniformTimeBehavior: public TimeBehaviour {
public:
  InfiniteUniformTimeBehavior(const double& a, const double& b);
  double generateTime(const double &intensity) override;

private:
  double a_;
  double b_;
};

class PuassonTime: public TimeBehaviour {
public:

   double generateTime(const double &intensity) override;

};

#endif //SMO_TIMEBEHAVIOUR_HPP
