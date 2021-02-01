#include <iostream>
#include <vector>
using namespace std;

vector<double> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	double s = 0.0;
	for (int i = 0; i < n; i++) {
		double b = (v[i] < 0.00000) ? ceil(v[i]) : floor(v[i]);
		s += b;
	}
	int sum = (int) -s;
	if (sum > 0) {
		int i = 0;
		while (sum != 0 && i < n) {
			cout << (int)ceil(v[i]) << endl;
			if (v[i] > 0.00000 && ceil(v[i]) != floor(v[i])) { sum--; }
			i++;
		}
		while (i < n) {
			if (v[i] < 0.00000) { cout << (int) ceil(v[i]) << endl; }
			else { cout << (int)floor(v[i]) << endl; }
			i++;
		}
	}
	else {
		int i = 0;
		while (sum != 0 && i < n) {
			cout << (int)floor(v[i]) << endl;
			if (v[i] < 0.00000 && ceil(v[i]) != floor(v[i])) { sum++; }
			i++;
		}
		while (i < n) {
			if (v[i] < 0.00000) { cout << (int)ceil(v[i]) << endl; }
			else { cout << (int)floor(v[i]) << endl; }
			i++;
		}
	}
	cin.ignore(2); return 0;
}