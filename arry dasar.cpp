#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    int array[100];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++) {
        bool unik = true;
        
        for (int j = 0; j < n; j++) {
            if (i != j && array[i] == array[j]) {
                unik = false;
                break;
            }
        }

        if (unik) {
            cout << array[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}

