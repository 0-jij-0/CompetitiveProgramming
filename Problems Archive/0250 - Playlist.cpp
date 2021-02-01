#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
vector<pair<int, int>> songs;
vector<pair<int, int>> beauty;

int n, k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t, b; cin >> t >> b;
		pair<int, int>p(t, b);
		songs.push_back(p);
	}
	sort(songs.begin(), songs.end());
	for (int i = 0; i < n; i++) {
		pair<int, int> p(songs[i].second, i);
		beauty.push_back(p);
	}
	sort(beauty.begin(), beauty.end());

	ll sum = 0; int last = n - k + 1;
	for (int i = 0; i < k - 1; i++) {
		sum += songs[n - 1 - i].first;
	}
	ll max = 0; set<int> ind;
	for (int i = 0; i < n; i++) {
		int idx = beauty[i].second;
		ll b = (ll)beauty[i].first, len = (ll)songs[idx].first;
		if (idx < last) {
			sum += len; b *= sum; sum -= len;
			ind.insert(idx);
		}
		else if (last > 0) { 
			last--; while (ind.find(last) != ind.end()) { last--; }
			if (last >= 0) { sum += songs[last].first; }
			b *= sum; sum -= len;
		}
		else { b *= sum; sum -= len; }
		if (b > max) { max = b; }
	}
	cout << max << endl;
	cin.ignore(2); return 0;

}