#include <iostream>
using namespace std;

int a[100];

int main() {
	for (int i = 0; i < 100; i++) { a[i] = i + 1; }
	cout << "? "; fflush(stdout);
	for (int i = 0; i < 100; i++) { cout << a[i] << ' '; fflush(stdout); a[i] <<= 7; }
	cout << endl; int x; cin >> x;
	cout << "? "; fflush(stdout);
	for (int i = 0; i < 100; i++) { cout << a[i] << ' '; fflush(stdout); }
	cout << endl; int y; cin >> y;
	cout << "! " << ((x >> 7) << 7) + y % 128 << endl; fflush(stdout);
	cin.ignore(2); return 0;
}