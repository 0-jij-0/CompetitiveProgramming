#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s, t;

int max_substr_len() {
	vector<int> first(t.size()), last(t.size());
	int i = 0, j = 0;
	while (j != t.size()) {
		if (s[i] != t[j]) { i++; continue; }
		first[j] = i; i++; j++;
	}
	i = s.size() - 1; j = t.size() - 1;
	while (j != -1) {
		if (s[i] != t[j]) { i--; continue; }
		last[j] = i; i--; j--;
	}
	int res = max(last[0], (int)s.size() - first.back() - 1);
	for (int i = 1; i < (int)t.size(); i++) {
		res = max(res, last[i] - first[i - 1] - 1);
	}
	return res;
}

int main() {
	cin >> s >> t;
	cout << max_substr_len() << endl;
	cin.ignore(2); return 0;
}