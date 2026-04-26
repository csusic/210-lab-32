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
    //for counting lanes
    int laneCounter1 = 1;
    //for counting time
    int timeCounter = 1;
    //deque of cars
    //deque<Car> Cars(INITIAL_SIZE);
    //array to hold toll booths
    array<deque<Car>, NUM_LANES> lanes;
    
    cout << "Initial queue: " << endl;
    //two initial lanes
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << laneCounter1++ << ":";
        //push back car objects
        lanes[i].push_back(Car());
        lanes[i].push_back(Car());
        cout << endl;
        //output car objects
        for (auto& c : lanes[i]) {
            cout << "[" << c.getYear() << " " << c.getMake();
            cout << " (" << c.getTransponder() << ")]\n";
        }
    }
    cout << endl;
    
    //Car simulation 
    for (int i = 0; i < TIME_PERIODS; i++) {
        //time header
        cout << "Time: " << timeCounter++ << endl;
        //lane counter
        int laneCounter2 = 1;
        for (int i = 0; i < NUM_LANES; i++) {
            //lane header
            cout << "Lane: " << laneCounter2++ << " ";
            //random number for time probability
            int timeRandom = rand() % (MAX-MIN+1) + MIN;
            //46% probability the car at the head of the line pays and leaves
            if (timeRandom > 0 && timeRandom <= 46) {
                cout << "Paid: ";
                cout << "[" << lanes[i].front().getYear() << " " << lanes[i].front().getMake();
                cout << " (" << lanes[i].front().getTransponder() << ")]";
                lanes[i].pop_front();
            }
            //39% probability that another car joins the line
            if (timeRandom > 46 && timeRandom <= 85) {
                Car car3;
                lanes[i].push_back(car3);
                cout << "Joined: ";
                cout << "[" << lanes[i].back().getYear() << " " << lanes[i].back().getMake();
                cout << " (" << lanes[i].back().getTransponder() << ")]";
            }
            //15% probability the rear car will shift lanes
            if (timeRandom > 85 && timeRandom <= 100) {
                cout << "Switched: ";
                lanes[i].back();
            }
            cout << endl;
        }
        //print updated queue
        //queue counter
        int queueCounter = 1;
        for (int i = 0; i < NUM_LANES; i++) {
            //queue header
            cout << "Lane " << queueCounter++ <<  " Queue: " << endl;
            for (auto& c : lanes[i]) {
                cout << "\t[" << c.getYear() << " " << c.getMake();
                cout << " (" << c.getTransponder() << ")]\n";
            }
            if (lanes[i].empty()) {
                cout << "\tEmpty\n";
            }
        }
        cout << endl;
    }
    cout << "Empty";

    return 0;
}