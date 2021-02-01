#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s; int n;

void findShortestLIS() {
	vector<int> res;
	int x = count(s.begin(), s.end(), '<');
	int small = n - x - 1, large = n;
	int i = 0, j = 0; while (i < n - 1 && s[i] == '<') { i++; }
	j = i; large -= i + 1; for (int k = 0; k <= i; k++) { res.push_back(large + k + 1); }
	while (j != n - 1) {
		if (j + 1 < n - 1 && s[j + 1] == s[i]) { j++; continue; }
		if (s[i] == '>') for(int k = 0; k < j - i + 1; k++){
			res.push_back(small--);
		}
		else {
			x = (j - i + 1); large -= x;
			for (int k = 0; k < x; k++) {
				res.push_back(large + k + 1);
			}
		}
		i = j = j + 1;
	}
	for (auto &x : res) { cout << x << ' '; } cout << '\n';
}

void findLongestLIS() {
	vector<int> res;
	int x = count(s.begin(), s.end(), '>');
	int small = x, large = x + 1; 
	res.push_back(large); large++;
	for (int i = 0; i < n - 1; i++)
		res.push_back(s[i] == '<' ? large++ : small--);
	for (auto &x : res) { cout << x << ' '; } cout << '\n';
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> s;
		findShortestLIS();
		findLongestLIS();
	}
	cin.ignore(2); return 0;
}