// COMSC-210 | Lab 32 | Christine Susic

#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL_SIZE = 2;

int main() {
    //declarations
    srand(time(0));
    //deque of cars
    deque<Car> Cars(INITIAL_SIZE);
    
    //two car objects
    Car car1;
    Car car2;
    //push back car objects
    Cars.push_back(car1);
    Cars.push_back(car2);
    //output car objects
    car1.print();
    car2.print();
    car3.print();
    
    //55% probability the car at the head of the line pays and leaves
    Cars.pop_front();

    //45% probability that another car joins the line
    //if 
    //Cars.push_back();

  

    return 0;
}