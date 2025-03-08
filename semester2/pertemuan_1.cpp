#include <iostream>

using namespace std;

int cariAngka(int array[], int ukuran, int target){
    for(int i = 0; i < ukuran; i++){
        if(array[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){

    int data[] = {10, 25, 30, 45, 50};
    int ukuran = sizeof(data)/sizeof(data[0]);
    int cari = 20;
    int hasil = cariAngka(data, ukuran, cari);

    if(hasil != -1){
        cout << "Angka " << cari << " ditemukan pada index " << hasil << endl;
    }else{
        cout << "Angka " << cari << " tidak ditemukan dalam data." << endl;
    }

    return 0;
}