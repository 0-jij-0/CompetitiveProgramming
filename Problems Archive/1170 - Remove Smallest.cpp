#include <iostream>
#include <vector>
using namespace std;

vector<int> v, freq;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		freq.clear(); freq.resize(102, 0);
		for (auto &x : v) { cin >> x; freq[x]++; }
		int i = 0; while (!freq[i]) { i++; }
		bool b = true; while (freq[i]) { i++; }
		while (i < 102) if (freq[i++]) b = false;
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}