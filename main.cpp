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
    cout << endl;
    
    int counter = 1; //for counting
    for (int i = 0; i < Cars.size(); i++) {
        cout << "Time: " << counter++ << " Operation: ";
        //random number
        int random = rand() % (MAX-MIN+1) + MIN;
        //55% probability the car at the head of the line pays and leaves
        if (random <= 55) {
            cout << "Car paid: " << endl;
            Cars.pop_front();
        }
        //45% probability that another car joins the line
        if (random >= 55) {
            Car car3;
            Cars.push_back(car3);
            cout << "Joined lane: ";
            car3.print();
        }
        cout << "Queue: " << endl;
        for (auto& c : Cars) {
            cout << "[" << c.getYear() << " " << c.getMake();
            cout << " (" << c.getTransponder() << ")]\n";
        }
        cout << endl;
    }

    return 0;
}