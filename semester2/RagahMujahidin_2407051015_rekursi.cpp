#include <iostream>
#include <string>
using namespace std;

int rekursi(string random, char huruf, int index = 0) {
    if (index >= random.length()) return 0;
    /*  pakai random.length() untuk menghitung panjang string
        agar dapat mengetahui posisi index apakah sudah mencapai
        akhir string atau belum.
        kalo udah di akhir string, return 0
    */
    if (random[index] == huruf) {
        return 1 + rekursi(random, huruf, index + 1);
    } else {
        return rekursi(random, huruf, index + 1);
    }
}

int main() {
    string random;
    char huruf;
    cout << "Masukkan string (maksimal 100 huruf): ";
    getline(cin, random);
    if (random.length() > 100) {
        cout << "Error: String tidak boleh lebih dari 100 huruf." << endl;
        return 1;
    }
    cout << "Masukkan huruf yang dicari: ";
    cin >> huruf;
    int jumlah = rekursi(random, huruf);
    cout << "Jumlah huruf '" << huruf << "' dalam string: " << jumlah << endl;

    return 0;
}