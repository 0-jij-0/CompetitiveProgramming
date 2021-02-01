#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<pair<ll, int>> useFreq;
vector<int> idx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int c, n; cin >> c >> n; useFreq.resize(c + 1);
	for (int i = 0; i <= c; i++) { useFreq[i] = { 0, i }; }
	idx.resize(c + 1); iota(idx.begin(), idx.end(), 0);

	int myTie; cin >> myTie; n--;
	int firstTie = myTie;
	for (int i = 0; i < n; i++) {
		int nextTie; cin >> nextTie;
		int id = idx[nextTie];
		useFreq[id].first++;
		idx[myTie] = id;
		myTie = nextTie;
	}
	sort(useFreq.rbegin(), useFreq.rend());

	ll res = 0;
	for (int i = 0; i <= c; i++) {
		res += (i + 1) * useFreq[i].first;
	}

	cout << res << '\n';
	for (int i = 0; i <= c; i++) {
		if (useFreq[i].second == 0 || useFreq[i].second == firstTie) { continue; }
		cout << useFreq[i].second << ' ';
	}
	cout << '\n'; cin.ignore(2); return 0;
}