#include <iostream>
using namespace std;

//int kali(int a, int b){
//	return a * b;
//}

//void kali(int a, int b){
//	cout << a * b << endl;
//}

//	void tampilkanPilihan(){
//		cout << "1. Kali" << endl;
//		cout << "2. Kali" << endl;
//		cout << "3. Kali" << endl;
//		cout << "4. Kali" << endl;
//	}

//	int faktorial(int n){
//		if (n <= 1){
//			return 1;
//		}else {
//			return n * faktorial(n - 1);
//		}
//	}

	double celToFahren (double suhu){
		return (suhu * 9 / 5) + 32;
	}
	
	double celToReamur (double suhu){
		return suhu * 4 / 5;
	}
	
	double reamurToCel (double suhu){
		return suhu * 5 / 4;
	}
	
	double reamurToFahren (double suhu){
		return (suhu * 9 / 4) + 32;
	}
	
	double fahrenToCel (double suhu){
		return (suhu - 32) * 5 / 9;
	}
	
	double fahrenToReamur (double suhu){
		return (suhu - 32) * 4 / 9;
	}
	
int main(){
	char format1, format2;
	double suhu;
	cout << "Masukkan Format Awal Suhu :";
	cin >> format1;
	cout << "Masukkan Format Akhir Suhu :";
	cin >> format2;
	cout << "Masukkan Suhu Awal :";
	cin >> suhu;
	
	cout << "Hasil Akhir :";
	if (format1 == 'c' || format1 == 'C'){
		if (format2 == 'f' || format2 == 'F'){
			cout << celToFahren(suhu) << endl;
		} else if (format2 == 'r' || format2 == 'R'){
		cout << celToReamur(suhu) << endl;
		}
	} else if (format1 == 'r' || format1 == 'R'){
		if(format2 == 'c' || format2 == 'C'){
			cout << reamurToCel(suhu) << endl;
		} else if (format2 == 'f' || format2 == 'F'){
			cout << reamurToFahren(suhu) << endl;
		}
	} else if (format1 == 'f' || format1 == 'F'){
		if(format2 == 'c' || format2 == 'C'){
			cout << fahrenToCel(suhu) << endl;
		} else if (format2 == 'r' || format2 == 'R'){
			cout << fahrenToReamur(suhu) << endl;
		}
	}
	
	
//	int a = 2;
//	int b = 10;
//	
//	cout << kali(a, b);

//	kali(4,5);

//	tampilkanPilihan();

//	cout << faktorial(8);

	return 0;
}
