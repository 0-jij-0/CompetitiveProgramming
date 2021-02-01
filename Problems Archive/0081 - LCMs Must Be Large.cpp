#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> days;

bool possible() {
	if (days.size() == 1) { return true; }
	for (unsigned int i = 0; i < days.size(); i++) { sort(days[i].begin(), days[i].end()); }

	for (unsigned int i = 0; i < days.size(); i++) {
		for (unsigned int j = i + 1; j < days.size(); j++) {
			vector<int> intersection; intersection.resize(days[i].size() + days[j].size());
			vector<int>::iterator it = set_intersection(days[i].begin(), days[i].end(), days[j].begin(), days[j].end(), intersection.begin());
			intersection.resize(it - intersection.begin());
			if (intersection.empty()) { return false; }
		}
	}
	return true;
}

int main() {
	int m, n; cin >> m >> n;
	days.resize(m);
	for (int i = 0; i < m; i++) {
		int s; cin >> s; days[i].resize(s);
		for (int j = 0; j < s; j++) { cin >> days[i][j]; }
	}
	if (possible()) { cout << "possible" << endl; }
	else { cout << "impossible" << endl; }
	return 0;
}