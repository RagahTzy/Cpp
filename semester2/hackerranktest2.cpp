#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int k;
    cin >> n >> k;
    
    int arr [n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    k = k%n;
    int rotasi[n];
    
    for (int i=0; i<n; i++){
        rotasi[(i+k)%n] = arr[i];
    }
    
    for (int i=0; i<n; i++){
        cout << rotasi[i] << " ";
    }
    return 0;
}