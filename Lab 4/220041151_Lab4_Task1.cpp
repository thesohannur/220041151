#include <iostream>
using namespace std;

class Calculator
{
private:
    int result;

    int getResult() const { return result; }

    void setResult(int value) { result = value; }


public:
    Calculator()
    {
        result = 0;
    }

    Calculator(int value)
    {
        result = value;
    }

   
    void add(int value)
    {
        result += value;
    }

    void subtract(int value)
    {
        result -= value;
    }

    void multiply(int value)
    {
        result *= value;
    }

    int divideBy(int value)
    {
        if (value == 0)
        {
            cout << "Invalid arithmetic operation." << endl;
            return result;
        }
        result /= value;
        return result % value;
    }

    void clear()
    {
        result = 0;
    }

    void display() const
    {
        cout << "Calculator display: " << result << endl;
    }

    ~Calculator()
    {
        cout << "Destructor of the Calculator object is called." << endl;
    }
};

int main()
{
    Calculator calc;
    calc.add(10);
    calc.display();
    calc.add(7);
    calc.display();
    calc.multiply(31);
    calc.display();
    calc.subtract(42);
    calc.display();
    calc.divideBy(7);
    calc.display();
    calc.divideBy(0);
    calc.display();
    calc.add(3);
    calc.display();
    calc.clear();
    calc.display();
    return 0;
}