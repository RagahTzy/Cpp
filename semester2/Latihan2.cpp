#include <iostream>
using namespace std;

int main() {
  int a[] = {1,2,3};
  int *ptr = a;
  cout << ptr << endl;
  cout << ptr+1 << endl;
  cout << ptr+2 << endl;
}