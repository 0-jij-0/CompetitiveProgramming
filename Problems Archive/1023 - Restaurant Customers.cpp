#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

map<int, int> t;
vector<int> freqTime;
vector<pair<int, int>> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x.first >> x.second; t[x.first] = t[x.second] = 0; }
	freqTime.resize(t.size() + 1); int id = 0;
	for (auto &x : t) { x.second = id++; }
	for (auto &x : v) { freqTime[t[x.first]]++; freqTime[t[x.second] + 1]--; }
	partial_sum(freqTime.begin(), freqTime.end(), freqTime.begin());
	cout << *max_element(freqTime.begin(), freqTime.end()) << endl;
	cin.ignore(2); return 0;
}