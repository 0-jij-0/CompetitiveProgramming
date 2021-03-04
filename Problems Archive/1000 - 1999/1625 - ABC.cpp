#include <iostream>
#include <string>
using namespace std;

string s; int n; int freq[3];

int solve(string t) {
	int j = 0, res = 0;
	int ub = freq[t[0] - 'a'];
	for (int i = 0; i < n; i++) {
		if (i == ub) { j++; ub += freq[t[j] - 'a']; }
		if (s[i] != t[j]) res++;
	}
	return (res + 1) >> 1;
}

int main() {
	freopen("abc.in", "r", stdin);
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	freq[0] = freq[1] = freq[2] = 0;
	for (char &c : s) freq[c - 'a']++;
	int res = min(solve("abc"), solve("cba"));

	if (freq[0] == 0 || freq[2] == 0) res = 0;
	if (freq[1] == 0 && freq[0] > 0 && freq[2] > 0) res = -1;

	cout << res << '\n';
	cin.ignore(2); return 0;
}