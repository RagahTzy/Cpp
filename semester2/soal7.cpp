#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int* maxPtr = &arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > *maxPtr) { // Compare the value at arr[i] with the value pointed by maxPtr
            maxPtr = &arr[i];  // Update maxPtr to point to the address of arr[i]
        }
    }

    cout << *maxPtr << endl;
    return 0;
}