#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {
        {6, 2, -1},
        {3, 4, 0},
        {-9, 5, 3}
    };
    
    int transpose[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[j][i] = matriks[i][j];
        }
    }
    
    cout << "Hasil transpose matriks : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

