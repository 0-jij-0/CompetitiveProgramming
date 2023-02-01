#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string A, B; ll ans = 0;

ll findEqual(string& a) {
	ll res = 0; int n = (int)a.size();
	for (int i = 0, j = 0; i < n; i++) {
		j = max(j, i);
		while (j < n && (a[j] == B[j] || a[j] == '$')) j++;
		res += j - i;
	}
	return res;
}

void checkAll(string& letters, set<char>& chosen, int k, int i) {
	if (i == letters.size()) {
		if (k) return;
		string a = A; for (char& c : a)
			if (chosen.count(c)) c = '$';
		ans = max(ans, findEqual(a));
		return;
	}
	checkAll(letters, chosen, k, i + 1);
	if (k) {
		chosen.insert(letters[i]);
		checkAll(letters, chosen, k - 1, i + 1);
		chosen.erase(letters[i]);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k >> A >> B; ans = 0;
		set<char> used(A.begin(), A.end()), chosen;
		string letters(used.begin(), used.end());
		checkAll(letters, chosen, min(k, (int)letters.size()), 0);
		cout << ans << '\n';
	}
}