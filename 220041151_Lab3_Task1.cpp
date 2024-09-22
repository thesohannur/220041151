#include <iostream>
using namespace std;

class Counter {
private:
    int count;          // Tracks the current count
    int incrementStep;  // Stores the increment step value

public:
    // Constructor to initialize the count to 0
    Counter() {
        count = 0;
        incrementStep = 1;  // Default increment step
    }

    // Function to set the increment step
    void setIncrementStep(int step) {
        incrementStep = step;
    }

    // Function to return the current count value
    int getCount() const {
        return count;
    }

    // Function to increment the count by the increment step
    void increment() {
        count += incrementStep;
    }

    // Function to reset the count to 0
    void resetCount() {
        count = 0;
    }
};

int main() {
    Counter c;

    // Set the increment step
    c.setIncrementStep(5);

    // Increment the count
    c.increment();
    cout << "Current count: " << c.getCount() << endl; 

    // Increment again
    c.increment();
    cout << "Current count: " << c.getCount() << endl; 

    // Reset the count
    c.resetCount();
    cout << "Count after reset: " << c.getCount() << endl; 

    return 0;
}
