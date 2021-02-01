#include <iostream>
using namespace std;

int main() {
	int n; cin >> n; 
	if (n % 2) { cout << 0 << endl;	} 
	else { n >>= 1; cout << (n - 1) / 2 << endl; }
	cin.ignore(2); return 0;
}