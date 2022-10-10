#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, int> chars;
map<vector<int>, int> DP;
string s; int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; n = (int)s.size();
	for (char c : s) if (!chars.count(c)) chars[c] = m++;

	ll res = 0; int zero = m;
	vector<int> freq(m); DP[freq]++; 
	for(char c : s) {
		if (!freq[chars[c]]++) { zero--; }
		if (!zero) for (auto& x : freq) zero += (--x == 0);
		res += DP[freq]++;
	}

	cout << res << '\n';
}