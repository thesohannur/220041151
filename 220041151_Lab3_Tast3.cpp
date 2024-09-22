#include <iostream>
using namespace std;

class Time {
private:
    int hour;    
    int minute;  
    int second;  

    void normalizeTime() {
        if (second >= 60) {
            minute += second / 60;
            second = second % 60;
        }

        if (minute >= 60) {
            hour += minute / 60;
            minute = minute % 60;
        }

        if (hour >= 24) {
            hour = hour % 24;
        }
    }

public:
    // Default constructor to initialize time to 00:00:00
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    // Member function to return the hour value
    int hours() const {
        return hour;
    }

    // Member function to return the minute value
    int minutes() const {
        return minute;
    }

    // Member function to return the second value
    int seconds() const {
        return second;
    }

    // Function to reset the time to a given hour, minute, and second
    void reset(int h, int m, int s) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            hour = h;
            minute = m;
            second = s;
        } else {
            cout << "Invalid time values!" << endl;
        }
    }

    // Function to advance the current time by h hours, m minutes, and s seconds
    void advance(int h, int m, int s) {
        hour += h;
        minute += m;
        second += s;

        normalizeTime();  // Normalize the time so that seconds and minutes are within limits
    }

    void print() const {
        if (hour < 10) {
            cout << "0";
        }
        cout << hour << ":";

        if (minute < 10) {
            cout << "0";
        }
        cout << minute << ":";

        if (second < 10) {
            cout << "0";
        }
        cout << second << endl;
    }
};

int main() {
    Time t;

    // Set the time to 10:30:45
    t.reset(10, 30, 45);
    t.print();  

    // Advance the time by 3 hours, 40 minutes, and 30 seconds
    t.advance(3, 40, 30);
    t.print(); 

    // Advance by more than an hour/minute to check normalization
    t.advance(5, 125, 400); 
    t.print(); 

    // Advance the time over 24 hours
    t.advance(5, 0, 0);
    t.print(); 

    return 0;
}
