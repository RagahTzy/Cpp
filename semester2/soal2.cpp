#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int masuk, jumlah = 0;
    int nilai[100];
    cin >> masuk;
    for(int i = 0; i < masuk; i++){
        cin >> nilai[i];
    }
    for(int i = 0; i < masuk; i++){
        jumlah += nilai[i];
    }
    cout << jumlah/masuk;
    return 0;
}