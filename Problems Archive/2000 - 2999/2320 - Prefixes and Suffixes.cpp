#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int n; cin >> n >> s >> t;
		map<pair<int, int>, int> m;
		for (int i = 0; i < n; i++) {
			char a = s[i], b = t[n - 1 - i];
			if (a > b) swap(a, b); m[{a, b}]++;
		}

		pair<int, int> odd = { -2, 0 };
		for(auto &[p, x] : m) if(x & 1)
			if (odd.first == -2) { odd = p; }
			else { odd = { -1, -2 }; break; }

		cout << (odd.first == -2 || odd.first == odd.second ? "YES" : "NO") << '\n';
	}
}