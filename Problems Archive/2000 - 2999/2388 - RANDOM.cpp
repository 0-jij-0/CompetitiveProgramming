#include <bits/stdc++.h>
using namespace std;

vector<string> s, t;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int h, w; cin >> h >> w;
	s.resize(w, string(h, '.'));
	t.resize(w, string(h, '.'));

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> s[j][i];

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> t[j][i];

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	bool ok = true;
	for (int i = 0; i < w && ok; i++)
		if (s[i] != t[i]) ok = false;

	cout << (ok ? "Yes" : "No") << '\n';
}