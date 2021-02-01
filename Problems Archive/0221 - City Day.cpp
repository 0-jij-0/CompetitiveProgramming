#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, x, y;

bool check(int idx) {
	for (int i = idx - 1; i >= 0 && i >= idx - x; i--) {
		if (v[i] < v[idx]) { return false; }
	}
	for (int i = idx + 1; i < n && i <= idx + y; i++) {
		if (v[i] < v[idx]) { return false; }
	}
	return true;
}

int main() {
	cin >> n >> x >> y;
	v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (check(i)) { idx = i; break; }
	}
	cout << idx + 1 << endl;
	cin.ignore(2); return 0;
}