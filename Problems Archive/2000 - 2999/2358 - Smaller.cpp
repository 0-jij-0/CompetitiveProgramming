#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> freqS, freqT;

bool check() {
	for (int i = 1; i < 26; i++)
		if (freqT[i]) return true;
	
	for (int i = 1; i < 26; i++)
		if (freqS[i]) return false;

	return freqS[0] < freqT[0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		freqS.clear(); freqS.resize(26); freqS[0] = 1;
		freqT.clear(); freqT.resize(26); freqT[0] = 1;
		int q; cin >> q; while (q--) {
			int d, k; string x; cin >> d >> k >> x;
			vector<ll>& freq = (--d ? freqT : freqS);
			for (char c : x) freq[c - 'a'] += k;
			cout << (check() ? "YES" : "NO") << '\n';
		}
	}
}