#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; 
		v.resize(n); f.clear(); f.resize(101);
		for (auto& x : v) { cin >> x; f[x]++; }

		v.clear(); for(int i = 0; i < 101; i++)
			if (f[i]) { f[i]--; v.push_back(i); }
		for (int i = 0; i < 101; i++)
			while (f[i]) { f[i]--; v.push_back(i); }

		for (auto& x : v) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}