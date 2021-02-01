#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }

	int A = 0, B = 0;
	sort(v.rbegin(), v.rend());
	bool alt = true;
	for (auto &x : v) {
		if (alt) { A += x; }
		else { B += x; }
		alt = !alt;
	}
	cout << A << ' ' << B << endl;
	cin.ignore(2); return 0;
}