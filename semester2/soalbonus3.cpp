#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int jam = N / 3600;
    int sisa = N % 3600;
    int menit = sisa / 60;
    int detik = sisa % 60;

    // Cetak jam
    if (jam < 10) cout << "0";
    cout << jam << ":";

    // Cetak menit
    if (menit < 10) cout << "0";
    cout << menit << ":";

    // Cetak detik
    if (detik < 10) cout << "0";
    cout << detik << endl;

    return 0;
}