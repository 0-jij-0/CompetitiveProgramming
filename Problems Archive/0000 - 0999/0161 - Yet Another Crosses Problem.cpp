#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> grid;
vector<int> vsum, hsum;
vector<pair<int, int>> blank;
int n, m;

int min_cells() {
	vector<int> hmin, vmin;
	hmin.push_back(0); vmin.push_back(0);
	for (int i = 1; i < n; i++) {
		if (hsum[i] < hsum[hmin[0]]) { 
			hmin.clear(); hmin.push_back(i); continue;
		}
		else if (hsum[i] == hsum[hmin[0]]) {
			hmin.push_back(i); continue;
		}
	}
	for (int i = 1; i < m; i++) {
		if (vsum[i] < vsum[vmin[0]]) {
			vmin.clear(); vmin.push_back(i); continue;
		}
		else if (vsum[i] == vsum[vmin[0]]) {
			vmin.push_back(i); continue;
		}
	}
	for (unsigned int i = 0; i < hmin.size(); i++) {
		for (unsigned int j = 0; j < vmin.size(); j++) {
			pair<int, int> p(hmin[i], vmin[j]);
			if (binary_search(blank.begin(), blank.end(), p)) {
				return hsum[hmin[0]] + vsum[vmin[0]] - 1;
			}
		}
	}
	return hsum[hmin[0]] + vsum[vmin[0]];
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		vsum.clear(); hsum.clear(); blank.clear();
		cin >> n >> m;
		vsum.resize(m); hsum.resize(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c; cin >> c;
				if (c == '.') {
					hsum[i]++; vsum[j]++;
					pair<int, int> p(i, j);
					blank.push_back(p);
				}
			}
		}
		cout << min_cells() << endl;
	}
	cin.ignore(2); return 0;
}

