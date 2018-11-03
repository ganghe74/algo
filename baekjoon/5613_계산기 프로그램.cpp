#include <iostream>
#include <string>
using namespace std;

int main() {
    int number, temp;
    string op;
    cin >> number;
    cin >> op;
    
    while (op != "=") {
        cin >> temp;
        if (op == "+") {
            number = number + temp;
        }
        else if (op == "-") {
            number = number - temp;
        }
        else if (op == "*") {
            number = number * temp;
        }
        else if (op == "/") {
            number = number / temp;
        }
        cin >> op;
    }

    cout << number;
}