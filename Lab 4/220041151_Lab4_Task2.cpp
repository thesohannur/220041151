#include <iostream>
using namespace std;

class Flight
{
private:
    int Flight_Number;
    string Destination;
    float Distance;
    float MaxFuelCapacity;

    double CalFuel(float dis)
    {
        if (dis <= 1000)
        {
            return 500;
        }
        else if (dis > 1000 && dis <= 2000)
        {
            return 1100;
        }
        else if (dis > 2000)
        {
            return 2200;
        }
    }

public:
    void FeedInfo()
    {
        cout << "Enter Flight Number: ";
        cin >> Flight_Number;
        cout << "Enter Destination: ";
        cin >> Destination;
        cout << "Enter Distance: ";
        cin >> Distance;
        cout << "Enter Max Fuel Capacity: ";
        cin >> MaxFuelCapacity;
    }

    void ShowInfo()
    {
        cout << "Flight Number: " << Flight_Number << endl;
        cout << "Destination: " << Destination << endl;
        cout << "Distance: " << Distance << endl;
        cout << "Max Fuel Capacity: " << MaxFuelCapacity << endl;

        double requiredFuel = CalFuel(Distance);
        if (requiredFuel <= MaxFuelCapacity)
        {
            cout << "Fuel capacity is fit for this flight distance." << endl;
        }
        else
        {
            cout << "Not sufficient Fuel Capacity for this flight." << endl;
        }
    }
};

int main()
{
    Flight flight1;
    flight1.FeedInfo();
    flight1.ShowInfo();
    return 0;
}