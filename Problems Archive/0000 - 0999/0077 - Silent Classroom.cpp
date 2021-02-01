#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int comb[51];
vector<string> names;

int main() {
	for (int i = 2; i < 51; i++) { comb[i] = i * (i - 1) / 2; }
	comb[0] = 0; comb[1] = 0;

	int n; cin >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		names.push_back(temp);
	}

	sort(names.begin(), names.end());

	long long res = 0;
	for (unsigned int i = 0; i < names.size() - 1; i++) {
		int rep = 1;
		while (i < (names.size() - 1) && names[i][0] == names[i + 1][0]) { rep++; i++; }

		if (rep <= 2) { continue; }
		res += comb[(rep + 1) / 2] + comb[rep / 2];
	}

	cout << res << endl;
	return 0;
}