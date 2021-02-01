#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> length;

int main() {
	length.resize(26, vector<int>(26, 0));
	int n; cin >> n;
	while (n--) {
		string str; cin >> str;
		set<char> s(str.begin(), str.end());
		if (s.size() > 2) { continue; }
		length[*s.begin() - 'a'][*s.rbegin() - 'a'] += str.size();
	}
	int res = 0;
	for (int i = 0; i < 26; i++)
		for (int j = i + 1; j < 26; j++)
			res = max(res, length[i][j] + length[i][i] + length[j][j]);
	cout << res << endl;
	cin.ignore(2); return 0;
}