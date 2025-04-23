#include <iostream>
using namespace std;

void cetakBiner(int n) {
    if (n == 0) return;
    cetakBiner(n / 2);
    cout << (n % 2);
}

int main() {
    int n;
    cin >> n;

    cetakBiner(n);
    cout << endl;

    return 0;
}