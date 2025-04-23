#include <iostream>
using namespace std;

int main(){
    int uang, barang, ambil = 0;
    cin >> uang >> barang;
    int harga[barang];

    for(int i = 0; i < barang; i++){
        cin >> harga[i];
    }
    for(int i = 0; i < barang; i++){
        if(uang >= harga[i]){
            ambil++;
            uang -= harga[i];
        }
    }
    cout << ambil << endl;

    return 0;
}