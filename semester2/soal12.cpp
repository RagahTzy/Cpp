#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    string reversed = string(input.rbegin(), input.rend());
    if (input == reversed) {
        cout << "YA" << endl;
    } else {
        cout << "TIDAK" << endl;
    }

    return 0;
}
