#include <iostream>
#include <cmath>

using namespace std;

/*yang paling sering digunakan di cmath saat ini : 
	pangkat = pow(x,y) berarti x pangkat y
	akar = sqrt(x)
	pembulatan ke atas = ceil(x)
	pembulatan ke bawah = floor(x)
*/
int main(){
	int x;
	cout << "menghitung akar dari : ";
	cin >> x;
	
	cout <<endl << "akar dari " << x << " adalah: ";
	double y= sqrt(x); double z = floor(y); cout << z;
	return 0;
}
