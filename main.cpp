// COMSC-210 | Lab 33 | Christine Susic

#include <algorithm> 
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <deque>
#include "Car.h"
using namespace std;

//initial size for the deque of cars
const int INITIAL_SIZE = 2;
//probabilities for simulation: 46%, 39%, 15%
const int PROB1 = 0, PROB2 = 46, PROB3 = 85, PROB4 = 100;
//minimum and maximum values for random numbers
const int MIN = 1, MAX = 100, MIN1 = 0, MAX1 = 3;
//toll booth lanes
const int NUM_LANES = 4;
//number of time periods for the simulation
const int TIME_PERIODS = 20;

int main() {
    //declarations
    srand(time(0));
    //for counting initial lanes
    int laneCounter1 = 1;
    //for counting time periods
    int timeCounter = 1;
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
    
    //Car simulation for twenty time periods
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
            if (timeRandom > PROB1 && timeRandom <= PROB2) {
                //header
                cout << "Paid: ";
                //output
                cout << "[" << lanes[i].front().getYear() << " ";
                cout << lanes[i].front().getMake();
                cout << " (" << lanes[i].front().getTransponder() << ")]";
                //pop front car object
                lanes[i].pop_front();
            }
            //39% probability that another car joins the line
            if (timeRandom > PROB2 && timeRandom <= PROB3) {
                //car object
                Car car3;
                //push back car object into lanes
                lanes[i].push_back(car3);
                //joined header
                cout << "Joined: ";
                //output
                cout << "[" << lanes[i].back().getYear() << " ";
                cout << lanes[i].back().getMake();
                cout << " (" << lanes[i].back().getTransponder() << ")]";
            }
            //15% probability the rear car will shift lanes
            if (timeRandom > PROB3 && timeRandom <= PROB4) {
                //random number 0-3 for lane swap
                int swapRandom = rand() % (MAX1-MIN1+1) + MIN1;
                //switched header
                cout << "Switched: ";
                //output
                cout << "[" << lanes[i].back().getYear() << " ";
                cout << lanes[i].back().getMake();
                cout << " (" << lanes[i].back().getTransponder() << ")]";
                //lane swap
                lanes[i].swap(lanes[swapRandom]);
            }
            //if lanes are empty
            if (lanes[i].empty()) {
                //random number for lane probability
                int random = rand() % (MAX-MIN+1) + MIN;
                //100% chance of car joining the deque
                if (random > PROB1 && random <= PROB4) {
                    //car object
                    Car car;
                    //push back car object into lanes
                    lanes[i].push_back(car);
                    //new car joined header
                    cout << "\nNew Car Joined: ";
                    //output
                    cout << "[" << lanes[i].back().getYear() << " ";
                    cout << lanes[i].back().getMake();
                    cout << " (" << lanes[i].back().getTransponder() << ")]";
                }
            }
            cout << endl;
        }
        //print updated queue
        //queue counter
        int queueCounter = 1;
        for (int i = 0; i < NUM_LANES; i++) {
            //queue header
            cout << "Lane " << queueCounter++ <<  " Queue: " << endl;
            //output
            for (auto& c : lanes[i]) {
                cout << "\t[" << c.getYear() << " " << c.getMake();
                cout << " (" << c.getTransponder() << ")]\n";
            }
            //if lanes are empty
            if (lanes[i].empty()) {
                //output empty
                cout << "\tEmpty\n";
            }
        }
        cout << endl;
    }
    //the lanes are empty
    cout << "Empty";

    return 0;
}