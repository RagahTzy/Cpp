#include <iostream>

using namespace std;

int main(){
	int genap = 0;
	int ganjil = 1;
	do{
		cout << "ini adalah angka genap : " << genap<< endl;
		genap += 2;
	}while(genap < 21);
	
	while(ganjil <=21){
		cout << "ini adalah angka ganjil : " << ganjil << endl;
		ganjil += 2;
	}
	
	for(int i=1; i <= 5; i++){
		for(int j = 5;j >=i;j--){
			cout << "  ";
		}
		for(int k = 1; k <= (2*i - 1); k++){
			cout << "* ";
		}
		cout << endl;
	}
	
	for(int i=1; i <= 5; i++){
		for(int j = 1;j <=i;j++){
			cout << "  ";
		}
		for(int k = 5; k >= (2*i - 5); k--){
			cout << "* ";
		}
		cout << endl;
	}
	
	return 0;
}
