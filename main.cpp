#include "mainwindow.h"
#include <iostream>
#include <vector>

#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Source.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Handler.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/Buffer.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/FunctionalModule.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/RingSelection.hpp"
#include "/Users/anastasiia/Desktop/Polytech/SMO/headers/FreeAddition.hpp"

#include <QApplication>
int load();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
      //return 0;
    //return load();
}
