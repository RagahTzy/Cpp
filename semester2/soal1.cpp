#include <iostream>
using namespace std;

int main() {
    int arry[201];
    int panjang, cari;
    int jawaban = -1;
    
    cin >> panjang;
    for(int i = 0; i < panjang; i++){
        cin >> arry[i];
    }
    cin >> cari;
    for(int i = 0; i < panjang; i++){
        if(arry[i] == cari){
            jawaban = i;
            break;
        }
    }
    cout << jawaban;
    return 0;
}
