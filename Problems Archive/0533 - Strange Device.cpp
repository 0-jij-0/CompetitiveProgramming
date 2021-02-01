#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<int, int>> res;
int n, k;

void query(int i) {
	string s = "? ";
	for(int j = 1; j <= k + 1; j++)
		if (j == i) { continue; }
		else { s += to_string(j) + " "; }
	s.pop_back(); cout << s << '\n'; fflush(stdout);
	cin >> res[i - 1].first >> res[i - 1].second;
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int main() {
	cin >> n >> k; res.resize(k + 1);
	for (int i = 1; i <= k + 1; i++) { query(i); }
	sort(res.begin(), res.end(), compare); int c = 0, i = 0;
	while (res[i] == res.front()) { i++; c++; }
	cout << "! " << k + 1 - c << '\n'; fflush(stdout);
	cin.ignore(2); return 0;
}