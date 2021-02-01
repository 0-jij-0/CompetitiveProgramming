#include <iostream>
using namespace std;
typedef long long ll;

int countBits(int x) {
	int res = 0; 
	while (x) { res++; x = x & (x - 1); }
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;

	while (t--) {
		unsigned int C; cin >> C;

		if (C == 0) { cout << "MOV R0, R0, LSR #32\n"; cout << "END\n"; continue; }
		if (C == 1) { cout << "END\n"; continue; }

		if (countBits(C) > 17) {
			C = ~C; bool one = C % 2; C += one;
			int shift = 0; while (C) {
				if (C % 2) { cout << "ADD R1, R1, R0, LSL #" << shift << '\n'; }
				C /= 2; shift++;
			}
			cout << "SUB R2, R2, R0, LSL #" << one << '\n';
			cout << "RSB R0, R1, R2, LSL #" << 0 << '\n';
		}
		else {
			int shift = 0; while (C) {
				if (C % 2) {
					bool last = (C / 2 == 0);
					if (last) {	cout << "ADD R0, R1, R0, LSL #" << shift << '\n'; }
					else { cout << "ADD R1, R1, R0, LSL #" << shift << '\n'; }
				}
				C /= 2; shift++;
			}
		}
		cout << "END\n";
	}
	cin.ignore(2); return 0;
}