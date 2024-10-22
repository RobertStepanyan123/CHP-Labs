#include <iostream>
using namespace std;

class GCDCalculator {
public:
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    GCDCalculator gcdCalc;
    int num1, num2;

    cout << "Input the first number: ";
    cin >> num1;
    cout << "Input the second number: ";
    cin >> num2;

    int gcd = gcdCalc.findGCD(num1, num2);

    cout << "The GCD is: " << gcd << endl;

    return 0;
}