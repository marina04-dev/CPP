#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

enum class LightColor { RED, YELLOW, GREEN };

mutex coutMutex;

class TrafficLight {
    public:
        TrafficLight(const string& dir) : direction(dir), color(LightColor::RED) {}
        void setColor(LightColor newColor);
        void display();
        string getDirection() const;
    private:
        string direction;
        LightColor color;
};

class IntersectionManager {
    public:
        IntersectionManager();
        ~IntersectionManager();
        void start();
        void cycleNS();
        void cycleEW();
    private:
        vector<TrafficLight*> northSouth;
        vector<TrafficLight*> eastWest;
        void setAll(vector<TrafficLight*>& lights, LightColor color) {
            for (auto* light : lights) {
                light->setColor(color);
            }
        }
};


int main() {
    IntersectionManager manager;
    manager.start();
    return 0;
}


void TrafficLight::setColor(LightColor newColor) {
    color = newColor;
    display();
}

void TrafficLight::display() {
    lock_guard<mutex> lock(coutMutex);
    cout<<direction<<": ";
    switch (color) {
        case LightColor::GREEN: 
            cout<<"GREEN"; 
            break;
        case LightColor::YELLOW: 
            cout<<"YELLOW"; 
            break;
        case LightColor::RED: 
            cout<<"RED"; 
            break;
    }
    cout<<endl;
}

string TrafficLight::getDirection() const {
    return direction;
}



IntersectionManager::IntersectionManager() {
    northSouth.push_back(new TrafficLight("North"));
    northSouth.push_back(new TrafficLight("South"));
    eastWest.push_back(new TrafficLight("East"));
    eastWest.push_back(new TrafficLight("West"));
}

void IntersectionManager::start() {
    thread nsThread(&IntersectionManager::cycleNS, this);
    thread ewThread(&IntersectionManager::cycleEW, this);

    nsThread.join();
    ewThread.join();
}



void IntersectionManager::cycleNS() {
    while (true) {
        setAll(northSouth, LightColor::GREEN);
        setAll(eastWest, LightColor::RED);
        this_thread::sleep_for(seconds(5));

        setAll(northSouth, LightColor::YELLOW);
        this_thread::sleep_for(seconds(2));

        setAll(northSouth, LightColor::RED);
    }
}

void IntersectionManager::cycleEW() {
    // Offset to alternate with North-South
    this_thread::sleep_for(seconds(7));

    while (true) {
        setAll(eastWest, LightColor::GREEN);
        setAll(northSouth, LightColor::RED);
        this_thread::sleep_for(seconds(5));

        setAll(eastWest, LightColor::YELLOW);
        this_thread::sleep_for(seconds(2));

        setAll(eastWest, LightColor::RED);
    }
}


IntersectionManager::~IntersectionManager() {
    for (auto* light : northSouth) delete light;
    for (auto* light : eastWest) delete light;
}