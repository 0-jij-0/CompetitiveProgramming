#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int max_idx() {
	int max = v.front(); int idx = 0;
	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i] > max) { max = v[i]; idx = i; }
	}
	return idx;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	int idx = max_idx(); bool b = true;
	for (int i = 0; i != idx; i++) {
		if (v[i] > v[i + 1]) { b = false; break; }
	}
	for (int i = n - 1; i != idx; i--) {
		if (!b) { break; }
		if (v[i] > v[i - 1]) { b = false; break; }
	}
	if (!b) { cout << "NO" << endl; }
	else { cout << "YES" << endl; }
	cin.ignore(2); return 0;
}