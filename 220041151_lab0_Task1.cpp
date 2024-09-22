#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    char next;
    cout << "Enter first fraction: ";
    cin >> a >> next >> b;
    cout << "Enter second fraction: ";
    cin >> c >> next >> d;
    cout << (a * b + c * d) << "/" << (a * d) << endl;
    return 0;
}