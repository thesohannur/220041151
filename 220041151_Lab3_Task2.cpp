#include <iostream>
#include <string>
using namespace std;

class Temperature {
private:
    float value;        
    string unit;    

    //check if the unit is valid 
    bool isValidUnit(const string& u) const {
        return (u == "Celsius" || u == "Fahrenheit" || u == "Kelvin");
    }

public:
    Temperature() {
        value = 0;
        unit = "Celsius";
    }

    void assign(float tempValue, const string& tempUnit) {
        if (!isValidUnit(tempUnit)) {
            cout << "Error: Invalid unit. Please use Celsius, Fahrenheit, or Kelvin." << endl;
            return;
        }

        // Ensure the temperature does not go below absolute zero
        if (tempUnit == "Celsius" && tempValue < -273.15) {
            cout << "Error: Temperature cannot be below absolute zero in Celsius." << endl;
            return;
        } else if (tempUnit == "Fahrenheit" && tempValue < -459.67) {
            cout << "Error: Temperature cannot be below absolute zero in Fahrenheit." << endl;
            return;
        } else if (tempUnit == "Kelvin" && tempValue < 0) {
            cout << "Error: Temperature cannot be below absolute zero in Kelvin." << endl;
            return;
        }

        value = tempValue;
        unit = tempUnit;
    }

    // Convert function to convert to the target unit and return the converted value
    float convert(const string& targetUnit) const {
        if (!isValidUnit(targetUnit)) {
            cout << "Error: Invalid target unit. Please use Celsius, Fahrenheit, or Kelvin." << endl;
            return -1;  // Return an invalid value to indicate error
        }

        float convertedValue = value;

        if (unit == "Celsius") {
            if (targetUnit == "Fahrenheit") {
                convertedValue = (value * 9 / 5) + 32;
            } else if (targetUnit == "Kelvin") {
                convertedValue = value + 273.15;
            }
        } else if (unit == "Fahrenheit") {
            if (targetUnit == "Celsius") {
                convertedValue = (value - 32) * 5 / 9;
            } else if (targetUnit == "Kelvin") {
                convertedValue = (value - 32) * 5 / 9 + 273.15;
            }
        } else if (unit == "Kelvin") {
            if (targetUnit == "Celsius") {
                convertedValue = value - 273.15;
            } else if (targetUnit == "Fahrenheit") {
                convertedValue = (value - 273.15) * 9 / 5 + 32;
            }
        }

        return convertedValue;
    }

    void print() const {
        cout << "The temperature is " << value << " " << unit << "." << endl;
    }
};

int main() {
    Temperature t;

    t.assign(100, "Celsius");
    t.print();  

    // Convert to Fahrenheit and print
    float fahrenheit = t.convert("Fahrenheit");
    if (fahrenheit != -1) {
        cout << "Converted to Fahrenheit: " << fahrenheit << " °F" << endl; 
    }

    // Convert to Kelvin and print
    float kelvin = t.convert("Kelvin");
    if (kelvin != -1) {
        cout << "Converted to Kelvin: " << kelvin << " K" << endl; 
    }

    // Try assigning an invalid temperature
    t.assign(-500, "Celsius"); 

    return 0;
}
