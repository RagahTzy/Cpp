#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int total = 0;
    int* ptr = arr;
    for (int i = 0; i < n; ++i) {
        total += *(ptr + i);
    }

    cout << total << endl;
    return 0;
}
