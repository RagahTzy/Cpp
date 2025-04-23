#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    map<int, int> frequency;
    for (int i = 0; i < n; ++i) {
        frequency[arr[i]]++;
    }

    int maxFreq = 0;
    int result = INT_MAX;
    for (auto& pair : frequency) {
        if (pair.second > maxFreq || (pair.second == maxFreq && pair.first < result)) {
            maxFreq = pair.second;
            result = pair.first;
        }
    }

    cout << result << endl;
    return 0;
}
