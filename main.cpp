#include "mainwindow.h"
#include <iostream>
#include <vector>

#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Source.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Handler.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Buffer.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/FunctionalModule.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/RingSelection.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/FreeAddition.hpp"

//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Source.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Handler.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Buffer.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/FunctionalModule.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/RingSelection.hpp"
//#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/FreeAddition.hpp"


#include <QApplication>
//int load();
//std::list<StepStructure> StepList;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
