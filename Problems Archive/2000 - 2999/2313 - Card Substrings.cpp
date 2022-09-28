#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

string s; vector<int> freq(26, 0);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		char c; cin >> c; freq[c - 'a']++;
	}

	ll res = 0;
	for (int i = 0, j = 0; i < n; j = max(j, ++i)) {
		while (j < n && freq[s[j] - 'a']) { freq[s[j++] - 'a']--; }
		res += j - i; if(i != j) freq[s[i] - 'a']++;
	}

	cout << res << '\n';
}