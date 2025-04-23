#include <iostream>
using namespace std;

int fibonacci(int angka){
    if(angka == 0){
        return 0;
    }else if(angka == 1){
        return 1;
    }else{return fibonacci(angka - 1) + fibonacci(angka - 2);}
}

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Fibonacci ke-" << angka << " adalah " << fibonacci(angka) << endl;
    return 0;
}