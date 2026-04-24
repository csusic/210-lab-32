// COMSC-210 | Lab 32 | Christine Susic

#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include "Car.h"
using namespace std;

//initial size for the deque of cars
const int INITIAL_SIZE = 2;
//minimum and maximum values for random number
const int MIN = 1, MAX = 100;

int main() {
    //declarations
    srand(time(0));
    //deque of cars
    deque<Car> Cars(INITIAL_SIZE);
    
    cout << "Initial queue: " << endl;
    //two car objects
    Car car1;
    Car car2;
    //push back car objects
    Cars.push_back(car1);
    Cars.push_back(car2);
    //output car objects
    car1.print();
    car2.print();
    
    for (int i = 0; i < 6; i++) {
        //random number
        int random = rand() % (MAX-MIN+1) + MIN;
        //55% probability the car at the head of the line pays and leaves
        if (random <= 55) {
            Cars.pop_front();
        }
        //45% probability that another car joins the line
        if (random >= 55) {
            Car car3;
            Cars.push_back(car3);
            car3.print();
        }
    }

    return 0;
}