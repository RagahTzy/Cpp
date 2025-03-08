#include <iostream>
using namespace std;


int main() {
    int tahun;
    cin >> tahun;
    
    if(tahun > 0){
        if((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)){
            cout << "Tahun Kabisat";
        }else{cout << "Bukan Tahun Kabisat";}
    }else{cout << "tidak ada tahun dalam minus";}
    return 0;
}
