#include <iostream>

using namespace std;
/*
int kuadrat (int x){
	int y;
	y = x * x;
	return y;
}

void penjumlahan(int a, int b){
	cout << a << " + " << b << " = " << a+b << endl;
}

void tampilkanpilihan(){
	cout << "1. Makan" << endl;
	cout << "2. Tidur" << endl;
	cout << "3. Main" << endl;
}
*/

int faktorial(int n){
	if(n <= 1){
		return 1;
	}else{
		return n * faktorial(n - 1);
	}
}

int main(){
	/*
	int input,hasil;
	cout << "pengkuadratan dari : ";
	cin >> input;
	hasil = kuadrat(input);
	cout << endl << "adalah : " << hasil << endl;
	
	penjumlahan(5, 8);
	penjumlahan(9, 18);
	
	tampilkanpilihan();*/
	
	cout << faktorial(5);
	
	return 0;
}
