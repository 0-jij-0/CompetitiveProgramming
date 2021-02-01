#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int s, in, e; cin >> s >> in >> e;
		int dif = s - in;
		if (dif > 0 && e < dif) { cout << e + 1 << endl; continue; }
		if (dif < 0 && e <= -dif) { cout << 0 << endl; continue; }
		if (dif < 0) { s += dif; e += dif; }
		else if (dif > 0) { s -= dif; e += dif; }
		cout << (e + 1) / 2 << endl;
	}
	cin.ignore(2); return 0;
}