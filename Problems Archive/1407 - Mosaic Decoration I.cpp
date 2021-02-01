#include <iostream>
using namespace std;

int main() {
	int n, b, p; cin >> n >> b >> p;
	int B = 0, P = 0;
	for (int i = 0; i < n; i++) {
		int bi, pi; cin >> bi >> pi;
		B += bi; P += pi;
	}
	cout << ((B + 9) / 10) * b + ((P + 9) / 10) * p << '\n';
	cin.ignore(2); return 0;
}