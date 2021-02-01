#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s[3], k[3]; int n;
vector<pair<int, pair<int, int>>> comb;
vector<int> c;

bool check_time(int x) {
	int t[3] = { k[0], k[1], k[2] };
	int i = 0, j = 0;
	while (i < n) {
		if (j >= 6) { break; }
		if (comb[j].second.first == comb[j].second.second && t[comb[j].second.first] < 2) { j++; continue; }
		if (!t[comb[j].second.first] || !t[comb[j].second.second]) { j++; continue; }
		if (comb[j].first * c[i] < x) { j++; continue; }
		t[comb[j].second.first]--; t[comb[j].second.second]--; i++;
	}
	return !(t[0] || t[1] || t[2]);
}

int find_min_time() {
	int l = 0, r = comb.back().first * c.front();
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		bool b = check_time(mid);
		if (b) { l = mid; }
		else { r = mid - 1; }
	}
	return l;
}

int main() {
	cin >> k[0] >> k[1] >> k[2];
	cin >> s[0] >> s[1] >> s[2];
	n = (k[0] + k[1] + k[2]) / 2;
	c.resize(n); for (auto &x : c) { cin >> x; }
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			comb.push_back({ s[i] + s[j], {i, j} });
	sort(comb.begin(), comb.end());
	sort(c.rbegin(), c.rend());
	cout << find_min_time() << endl;
	cin.ignore(2); return 0;
}