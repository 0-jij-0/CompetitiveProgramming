#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> s; int n = (int)s.size();
		string keep = "", toSort = ""; vector<int> freq(10, 0);
		for (char c : s) freq[c - '0']++;

		for (int i = 0, j = 0; i < n && j < 10; i++) {
			while (!freq[j]) j++; freq[s[i] - '0']--;
			(s[i] - '0' == j ? keep : toSort).push_back(s[i]);
		}

		for (char& c : toSort) if (c != '9') c++;
		sort(toSort.begin(), toSort.end()); string res(n, '0');
		merge(keep.begin(), keep.end(), toSort.begin(), toSort.end(), res.begin());
		cout << res << '\n';
	}
}