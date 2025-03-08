#include <iostream>

using namespace std;

void HitungRataRata(int nilai[], int n){
    int jumlah = 0;
    for (int i = 0; i < n; i++){
        jumlah = jumlah + nilai[i];
    }
    int rata = jumlah/n;
    cout << "Rata-rata nilai Mahasiswa: " << rata << endl;
}

void NilaiTertinggi(int nilai[], int n){
    int nilaitertinggi = nilai[0];
    for (int i = 0; i < n; i++){
        if(nilaitertinggi <= nilai[i]){
            nilaitertinggi = nilai[i];
        }
    }
    cout << "Nilai tertinggi Mahasiswa: " << nilaitertinggi << endl;
}

int main(){
    int nilai[10] = {82, 32, 60, 40, 84, 47, 97, 50, 64, 96};
    HitungRataRata(nilai, 10);
    NilaiTertinggi(nilai, 10);
    return 0;
}