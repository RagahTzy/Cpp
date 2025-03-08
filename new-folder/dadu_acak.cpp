#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//program fungsi dadu acak

int main(){
	
	while(true){
		cout << "Lempar Dadu?" << endl;
		char jawaban;
		cin >> jawaban;
		if(jawaban == 'y' || jawaban == 'Y'){
			srand(time(0));
			cout << "Angka dadu anda : " << 1 + (rand() % 6) << endl;
		}else if(jawaban == 'n' || jawaban == 'N'){
			break;
		}else{
			cout << "tolong hanya masukkan huruf y/n" << endl;
		}
	}
	return 0;
}
