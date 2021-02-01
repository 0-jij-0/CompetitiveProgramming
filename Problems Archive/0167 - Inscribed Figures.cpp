#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int points(int &n) {
	int p = 0;
	for (int i = 1; i < n; i++) {
		int a = v[i] + v[i - 1];
		if (a == 5) { return -1; }
		if (a == 4) { p += 4; continue; }
		if (a == 3) { p += 3; }
		if (i > 1 && v[i] == 2 && v[i - 1] == 1 && v[i - 2] == 3) { p--; }
	}
	
	return p;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	int x = points(n);
	if (x == -1) { cout << "Infinite" << endl; }
	else { cout << "Finite" << endl << x << endl; }
	cin.ignore(2); return 0;
}