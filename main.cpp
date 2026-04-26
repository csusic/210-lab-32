// COMSC-210 | Lab 33 | Christine Susic

#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <deque>
#include "Car.h"
using namespace std;

//initial size for the deque of cars
const int INITIAL_SIZE = 2;
//minimum and maximum values for random number
const int MIN = 1, MAX = 100;
//toll booth lanes
const int NUM_LANES = 4;
//number of time periods for the simulation
const int TIME_PERIODS = 20;

int main() {
    //declarations
    srand(time(0));
    //for counting
    int counter = 1;
    //deque of cars
    deque<Car> Cars(INITIAL_SIZE);
    //array to hold toll booths
    array<deque<Car>, NUM_LANES> lanes;
    
    cout << "Initial queue: " << endl;
    //two initial lanes
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane" << counter++ << ":";
        lanes[i].push_back(Car());
        lanes[i].push_back(Car());
        cout << endl;
    }
    
    //Car simulation 
    for (int i = 0; i < TIME_PERIODS; i++) {
        //header
        cout << "Time: " << counter++ << " Operation: ";
        //random number for probability
        int random = rand() % (MAX-MIN+1) + MIN;
        //46% probability the car at the head of the line pays and leaves
        if (random > 0 && random <= 46) {
            cout << "Car paid: ";
            cout << "[" << Cars.front().getYear() << " " << Cars.front().getMake();
            cout << " (" << Cars.front().getTransponder() << ")]\n";
            Cars.pop_front();
        }
        //39% probability that another car joins the line
        if (random > 46 && random <= 85) {
            Car car3;
            Cars.push_back(car3);
            cout << "Joined lane: ";
            car3.print();
        }
        //15% probability the rear car will shift lanes
        if (random > 85 && random <= 100) {
            
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