#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "berapa jumlah nilai yang ingin dimasukkan?";
    cin >> n;
    int data[10];
    int jumlah = 0;
    int panjangarray = sizeof(data)/sizeof(data[0]);
    
    for(int i = 0; i < panjangarray; i++){
        cout << "masukkan nilai " << i + 1 << ": ";
        cin >> data[i];
    }

    for(int i = 0; i < panjangarray; i++){
        jumlah = jumlah + data[i];
    }

    float hasil = jumlah/panjangarray;
    cout << endl << "rata-rata nilai siswa adalah:" << hasil << endl;

    for(int i = 0; i < panjangarray; i++){
        cout << "nilai " << i + 1 << ". " << data[i] << endl;
    }

    return 0;
}