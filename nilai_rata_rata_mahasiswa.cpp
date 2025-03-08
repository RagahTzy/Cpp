#include <iostream>

using namespace std;

int main(){
	
	const double Tugas = 0.3;
	const double Kuis = 0.1;
	const double UTS = 0.25;
	const double UAS = 0.25;
	const double Keaktifan = 0.1;
	
	double Tugas1, Kuis1, UTS1, UAS1, Keaktifan1, Tugas2, Kuis2, UTS2, UAS2, Keaktifan2, Tugas3, Kuis3, UTS3, UAS3, Keaktifan3, ratarata;
	string HurufMutu;
	
	cout << "Masukkan nilai tugas, kuis, uts, uas, dan keaktifan secara berurutan ulangi hingga 3x :" << endl;
	cin >> Tugas1 >> Kuis1 >> UTS1 >> UAS1 >> Keaktifan1 >> Tugas2 >> Kuis2 >> UTS2 >> UAS2 >> Keaktifan2 >> Tugas3 >> Kuis3 >> UTS3 >> UAS3 >> Keaktifan3;
	
	ratarata = (Tugas1 * Tugas) + (Kuis1 * Kuis) + (UTS1 * UTS) + (UAS1 * UAS) + (Keaktifan1 * Keaktifan);
	
	if (ratarata >= 0){
		if (ratarata < 50){
			HurufMutu = "E";
		}else if(ratarata >=50 && ratarata < 56){
			HurufMutu = "D";
		}else if(ratarata >=56 && ratarata < 61){
			HurufMutu = "C";
		}else if (ratarata >= 61 && ratarata < 66){
			HurufMutu = "C+";
		}else if (ratarata >= 66 && ratarata < 71){
			HurufMutu = "B";
		}else if (ratarata >= 71 && ratarata < 76){
			HurufMutu = "B+";
		}else{
			HurufMutu = "A";
		}
	}else{cout << "Nilai tidak boleh minus";}
	
	cout << ratarata << " " << HurufMutu << endl;
	
	ratarata = (Tugas2 * Tugas) + (Kuis2 * Kuis) + (UTS2 * UTS) + (UAS2 * UAS) + (Keaktifan2 * Keaktifan);
	
	if (ratarata >= 0){
		if (ratarata < 50){
			HurufMutu = "E";
		}else if(ratarata >=50 && ratarata < 56){
			HurufMutu = "D";
		}else if(ratarata >=56 && ratarata < 61){
			HurufMutu = "C";
		}else if (ratarata >= 61 && ratarata < 66){
			HurufMutu = "C+";
		}else if (ratarata >= 66 && ratarata < 71){
			HurufMutu = "B";
		}else if (ratarata >= 71 && ratarata < 76){
			HurufMutu = "B+";
		}else{
			HurufMutu = "A";
		}
	}else{cout << "Nilai tidak boleh minus";}
	
	cout << ratarata << " " << HurufMutu << endl;
	
	ratarata = (Tugas3 * Tugas) + (Kuis3 * Kuis) + (UTS3 * UTS) + (UAS3 * UAS) + (Keaktifan3 * Keaktifan);
	
	if (ratarata >= 0){
		if (ratarata < 50){
			HurufMutu = "E";
		}else if(ratarata >=50 && ratarata < 56){
			HurufMutu = "D";
		}else if(ratarata >=56 && ratarata < 61){
			HurufMutu = "C";
		}else if (ratarata >= 61 && ratarata < 66){
			HurufMutu = "C+";
		}else if (ratarata >= 66 && ratarata < 71){
			HurufMutu = "B";
		}else if (ratarata >= 71 && ratarata < 76){
			HurufMutu = "B+";
		}else{
			HurufMutu = "A";
		}
	}else{cout << "Nilai tidak boleh minus";}
	
	cout << ratarata << " " << HurufMutu << endl;
	return 0;
}
