#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int totalWaktu = 0;
    for (int i = 0; i < n; ++i) {
        int waktu;
        cin >> waktu;
        if(waktu < 0 || waktu > 100){
            return 1;
        }
        if(waktu == 0){
            return 1;
        }
        totalWaktu += waktu;
    }

    cout << totalWaktu << endl;
    return 0;
}
