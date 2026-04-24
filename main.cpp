// COMSC-210 | Lab 32 | Christine Susic

#include <iostream>
#include <iomanip>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL_SIZE = 2;

int main() {
    //deeclarations
    srand(time(0));
    deque<Car> Cars(INITIAL_SIZE);
    
    //55% probability the car at the head of the line pays and leaves
    Cars.pop_front();

    //45% probability that another car joins the line
    if 
    Cars.push_back(Car);

    Cars.print();

    return 0;
}