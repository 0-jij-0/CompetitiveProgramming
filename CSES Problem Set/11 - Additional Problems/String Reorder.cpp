#include <bits/stdc++.h>
using namespace std;

string s; vector<int> freq(26);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; int n = (int)s.size();
	for (char c : s) freq[c - 'A']++;

	string res = ""; int skip = -1;
	for (int i = 0; i < n; i++) {
		int ma = 0, maIDX = -1;
		for(int j = 0; j < 26; j++) if(j != skip)
			if (ma < freq[j]) { ma = freq[j]; maIDX = j; }

		if (maIDX == -1) { res = "-1"; break; }
		if (ma > (n - i) / 2) { res.push_back(maIDX + 'A'); freq[maIDX]--; skip = maIDX; continue; }

		int first = -1;
		for(int j = 0; j < 26; j++) if(freq[j])
			if (j != skip) { first = j; break; }

		if (first == -1) { res = "-1"; break; }
		res.push_back(first + 'A'); freq[first]--; skip = first;
	}

	cout << res << '\n';
}