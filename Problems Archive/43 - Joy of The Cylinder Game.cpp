#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
using namespace std;

int MAX[1005][1005];
vector<vector<int>> DP;
vector<vector<int>> cylinder;
unsigned int n, m;

void maxSubArr(vector<int> &v, int &i, unsigned int &k) {
	if (k > m) { k = m; }
	list<pair<int, int>> max;
	pair<int, int> p0(v[0], 0);
	max.push_back(p0);
	for (unsigned int j = 1; j < k; j++) {
		int &n = v[j];
		while (!max.empty() && n > max.back().first) { max.pop_back(); }
		pair<int, int> p(n, j); max.push_back(p);
	}
	int center = k / 2;
	MAX[i][center] = max.front().second;
	center++;
	for (unsigned int j = k; j < m + k; j++) {
		if (v[j - k] == max.front().first) { max.pop_front(); }
		int &n = v[j % m];
		while (!max.empty() && n > max.back().first) { max.pop_back(); }
		pair<int, int> p(n, j % m); max.push_back(p);
		int max_idx = max.front().second;
		list<pair<int, int>>::iterator it = max.begin();
		while(it != max.end() && it->first == max.front().first){ 
			if (it->second < max.front().second) {
				max_idx = it->second; break;
			} it++;
		}
		MAX[i][center % m] = max_idx;
		center++;
	}
}

void joyCylinder(unsigned int &k) {
	for (unsigned int i = 0; i < m; i++) {
		DP[n-1][i] = cylinder[n-1][i];
	}
	int idx = n - 1; unsigned int dist = 2*k - 1;
	maxSubArr(DP[idx], idx, dist);

	for (unsigned int i = 1; i < n; i++) {
		idx--;
		for (unsigned int j = 0; j < m; j++) {
			DP[idx][j] = DP[idx + 1][MAX[idx + 1][j]] + cylinder[idx][j];
		}
		maxSubArr(DP[idx], idx, dist);		
	}

	int max = DP[0][0], max_idx = 0;
	for (unsigned int i = 0; i < m; i++) {
		if (DP[0][i] > max) { max = DP[0][i]; max_idx = i; }
	}

	cout << max << " " << max_idx + 1;
	if (n > 1) { cout << " "; }
	for (unsigned int i = 1; i < n; i++) {
		int idx = MAX[i][max_idx];
		cout << idx + 1; 
		if (i + 1 != n) { cout << " ";  }
		else { cout << endl; return; }
		max_idx = idx;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	DP.resize(1005);
	for (int i = 0; i < 1005; i++) { DP[i].resize(1005); }

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cylinder.clear(); cylinder.resize(n);
		unsigned int k; cin >> k;
		for (unsigned int x = 0; x < n; x++) {
			for (unsigned int y = 0; y < m; y++) {
				int a; cin >> a; cylinder[x].push_back(a);
			}
		}
		joyCylinder(k); cout << endl;
	}
	cout << endl; cin.ignore(2); return 0;
}