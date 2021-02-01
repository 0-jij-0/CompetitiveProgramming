#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	int i1 = 0, j2 = n - 1, i2, j1;
	for (int i = 0; i < n; i++) {
		if (v[i] != v[j2]) { j1 = i; break; }
	}
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] != v[i1]) { i2 = i; break; }
	}
	int m = ((j2 - j1) > (i2 - i1)) ? j2 - j1 : i2 - i1;
	cout << m << endl;
	cin.ignore(2); return 0;
}