#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(const vector<int>& numbers, int n) {

    int expectedSum = n * (n + 1) / 2;

    int actualSum = 0;
    for (int number : numbers) {
        actualSum += number;
    }


    return expectedSum - actualSum;
}

int main() {
    int n;
    cout << "Enter the upper limit: ";
    cin >> n;

    vector<int> numbers;
    cout << "Enter " << (n - 1) << " numbers in the interval (1 to " << n << "):\n";

    for (int i = 0; i < n - 1; ) {
        int number;
        cin >> number;


        if (number < 1 || number > n) {
            cout << "The number " << number << " doesn't belong to the interval. Please enter only numbers between 1 and " << n << ".\n";
        }
        else {
            numbers.push_back(number);
            i++;
        }
    }

    int missingNumber = findMissingNumber(numbers, n);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}