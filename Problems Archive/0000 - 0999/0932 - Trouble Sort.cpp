#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &v) {
	for (int i = 1; i < (int)v.size(); i++)
		if (v[i] < v[i - 1])return false;
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; vector<int>a(n);
		for (auto &x : a) { cin >> x; }
		int z = 0, o = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x; (x ? o : z)++;
		}
		if (z && o) { cout << "Yes" << endl; continue; }
		cout << (isSorted(a) ? "Yes" : "No") << endl;
	}
	cin.ignore(2); return 0;
}