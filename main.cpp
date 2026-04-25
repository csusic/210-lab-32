// COMSC-210 | Lab 33 | Christine Susic

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
    Cars.push_front(car1);
    Cars.push_front(car2);
    //output car objects
    car2.print();
    car1.print();
    cout << endl;
    
    int counter = 1; //for counting
    //Car simulation 
    while (!Cars.empty()) {
        //header
        cout << "Time: " << counter++ << " Operation: ";
        //random number for probability
        int random = rand() % (MAX-MIN+1) + MIN;
        //55% probability the car at the head of the line pays and leaves
        if (random > 0 && random <= 55) {
            cout << "Car paid: ";
            cout << "[" << Cars.front().getYear() << " " << Cars.front().getMake();
            cout << " (" << Cars.front().getTransponder() << ")]\n";
            Cars.pop_front();
        }
        //45% probability that another car joins the line
        if (random > 55 && random <= 100) {
            Car car3;
            Cars.push_back(car3);
            cout << "Joined lane: ";
            car3.print();
        }
        //print updated queue
        cout << "Queue: " << endl;
        for (auto& c : Cars) {
            cout << "[" << c.getYear() << " " << c.getMake();
            cout << " (" << c.getTransponder() << ")]\n";
        }
        cout << endl;
    }
    cout << "Empty";

    return 0;
}