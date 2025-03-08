#include <iostream>

using namespace std;

int main(){
	
	int data1, panjang;
	cin >> panjang;
	int arry[panjang];
	
	for(int i = 0; i < panjang; i++){
		cin >> arry[i];
	}
	
	for(int i = panjang-1; i >=0; i--){
		cout << arry[i] << " ";
	}
	
	return 0;
}
