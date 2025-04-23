#include <iostream>
using namespace std;


int main() {
    int masuk, top = -1;
    int stack[100];
    cin >> masuk;
    if(masuk <= 0 || masuk >= 100){
        return 1;
    }
    
    for(int i = 0; i < masuk; i++){
        int nilai;
        cin >> nilai;
        stack[++top] = nilai;
    }
    
    while(top >= 0){
        cout << stack[top--] << endl;
    }
    return 0;
}