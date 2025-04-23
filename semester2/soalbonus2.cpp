#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;  
    
    int sum = 0;
    int ganjil = 1;  
    
    for (int i = 0; i < N; i++) {
        sum += ganjil;
        ganjil += 2;  
    }
    
    cout << sum << endl;
    return 0;
}
