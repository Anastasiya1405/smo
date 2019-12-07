#include "mainwindow.h"
#include <iostream>
#include <vector>

#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Source.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Handler.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Buffer.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/FunctionalModule.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/RingSelection.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/FreeAddition.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/src/RingAdd.h"

//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Source.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Handler.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Buffer.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/FunctionalModule.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/RingSelection.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/FreeAddition.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/src/RingAdd.h"

#include <QApplication>

int load(int numSources, int numBufer, int numHandler, size_t numApplication, double lambda, double alpha, double beta)
{
    std::cout << "numSources = " << numSources << '\n'
              << "numBufer = " << numBufer << '\n'
              << "numHandler = " << numHandler << '\n'
              << "numApplication = "<< numApplication << '\n'
              << "lambda = " <<lambda << '\n'
              << "alpha = "<< alpha << '\n'
              << "beta = "<< beta << '\n';
    std::cout << '\n';
    std::srand(unsigned(std::time(nullptr)));

      std::shared_ptr<TimeBehaviour> exponentialTimeGenerator = std::make_shared<ExponentialTimeBehavior>();

      double a = alpha;
      double b = beta;
      std::shared_ptr<TimeBehaviour> infiniteUniformTimeGenerator = std::make_shared<InfiniteUniformTimeBehavior>(a, b);

       double intensity = lambda;
      std::shared_ptr<TimeBehaviour> puassonTime = std::make_shared<PuassonTime>();

      std::vector<std::shared_ptr<Source>> sources;
      for (int i = 0; i <  numSources; i++)
      {
          sources.push_back(std::make_shared<Source>(intensity, puassonTime));
      }

      //intensity = 8;
      std::vector<std::shared_ptr<Handler>> handlers;
      for (int i = 0; i < numHandler; i++)
      {
          handlers.push_back(std::make_shared<Handler>(0, infiniteUniformTimeGenerator));
      };

      const size_t bufferSize = numBufer;
      std::shared_ptr<SelectionStrategy> selectionStrategy = std::make_shared<RingSelection>();
      std::shared_ptr<AdditionStrategy> additionStrategy = std::make_shared<RingAdd>();
      std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(selectionStrategy, additionStrategy, bufferSize);

      FunctionalModule functionalModule(sources, buffer, handlers);
      //functionalModule.simulate(999999);
      functionalModule.totalGeneratedAppsSimulation(numSources, numBufer, numHandler, numApplication);
      for (size_t i = 0; i < sources.size(); ++i) {
        std::cout << "Stats for " << i+ 1 << " source:\n";
        std::cout << "\t generatedAppsCount = " << functionalModule.data_.sourcesData[i].generatedAppsCount << '\n';
        std::cout << "\t refusedAppsCount = " << functionalModule.data_.sourcesData[i].refusedAppsCount << '\n';
        //std::cout << "\t acceptedAppsCount = " << functionalModule.data_.sourcesData[i].acceptedAppsCount << '\n';
        std::cout << "\t acceptedAppsCount = " << functionalModule.data_.sourcesData[i].generatedAppsCount -
                     functionalModule.data_.sourcesData[i].refusedAppsCount  << '\n';
        std::cout << "\t getProbabilityOfFailure = " << functionalModule.data_.getProbabilityOfFailure(i) << '\n';
        std::cout << "\t averageTimeInSystem = " << functionalModule.data_.getAverageTimeInSystem(i) << '\n';
        std::cout << "\t averageHandlingTime = " << functionalModule.data_.getAverageHandlingTime(i) << '\n';
        std::cout << "\t averageBufferingTime = " << functionalModule.data_.getAverageBufferingTime(i) << '\n';
        std::cout << "\t dispersion = " <<
                     functionalModule.data_.getAverageBufferingTime(i) / functionalModule.data_.getAverageTimeInSystem(i)
                  << '\n';
        std::cout << '\n';
      }

      for (size_t i = 0; i < handlers.size(); ++i) {
        std::cout << "Stats for " << i + 1 << " handler:\n";
        std::cout << "\t getEmploymentRate = " << functionalModule.data_.getEmploymentRate(i) << '\n';
      }
      return 0;
}
