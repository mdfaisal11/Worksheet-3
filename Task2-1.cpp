#include <iostream>
#include <fstream>
using namespace std;

class Vehicle
{
protected:
    string regNo, color;
public:
    Vehicle(string r, string c) : regNo(r), color(c) {}
    virtual void writeToFile()
    {
        ofstream file("vehicles.txt");
        file << "Reg No: " << regNo << ", Color: " << color;
    }
};

class Car :
public Vehicle
{
    int seats;
public:
    Car(string r, string c, int s) : Vehicle(r, c), seats(s) {}
    void writeToFile() override {
        ofstream file("vehicles.txt");
        file << "Car - Reg No: " << regNo << ", Color: " << color << ", Seats: " << seats << endl;
    }
};

class Bike :
public Vehicle
{
    int engineCapacity;
public:
    Bike(string r, string c, int e) : Vehicle(r, c), engineCapacity(e) {}
    void writeToFile() override {
        ofstream file("vehicles.txt", ios::app);
        file << "Bike - Reg No: " << regNo << ", Color: " << color << ", Engine: " << engineCapacity << "cc" << endl;
    }
};

int main()
{
        int choice;
        cout << "Enter your choice:"<<endl;
        cout << "1. Add Car "<<endl;
        cout << "2. Add Bike "<<endl;
        cout << "3. Exit "<<endl;
        cout << "Choice: ";
        cin >> choice;
        string regNo, color;
        if (choice == 1)
        {
            int seats;
            cout << "Enter Reg No, Color, Seats: ";
            cin >> regNo >> color >> seats;
            Car(regNo, color, seats).writeToFile();
        }
        else if (choice == 2)
        {
            int engine;
            cout << "Enter Reg No, Color, Engine Capacity: ";
            cin >> regNo >> color >> engine;
            Bike(regNo, color, engine).writeToFile();
        }
        else
        {
            cout<<"Enter choice between 1 & 2 ."<<endl;
        }
        return 0;
}
