#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<deque<int>> idx;
string s;

int main() {
	cin >> s; idx.resize(3);
	for (unsigned int i = 0; i < s.size(); i++) {
		idx[s[i] - 'a'].push_back(i);
	}
	string res; int n = s.size() / 2;
	bool extra = false; char ex;
	while (2 * (int)res.size() < n) {
		int m = max(idx[0].size(), idx[1].size());
		m = max(m, (int)idx[2].size());
		if ((2*(int)res.size()) + m >= n) {
			extra = n % 2;
			int y = (n - (2 * res.size())) / 2;
			if (idx[0].size() == m) { ex = 'a'; }
			else if (idx[1].size() == m) { ex = 'b'; }
			else { ex = 'c'; }
			while (y != 0) { res.push_back(ex); y--; }
			break;
		}
		int da = idx[0].back() - idx[0].front();
		int db = idx[1].back() - idx[1].front();
		int dc = idx[2].back() - idx[2].front();
		char c;
		if (da > db) { m = da; c = 'a'; }
		else { m = db; c = 'b'; }
		if (dc > m) { m = dc; c = 'c'; }
		res.push_back(c);
		int left = idx[c - 'a'].front(), right = idx[c - 'a'].back();
		for (int j = 0; j < 3; j++) {
			while (!idx[j].empty() && idx[j].front() <= left) { idx[j].pop_front(); }
			while (!idx[j].empty() && idx[j].back() >= right) { idx[j].pop_back(); }
		}
	}
	string ser = res; reverse(ser.begin(), ser.end());
	if (extra) { cout << res << ex << ser << endl; }
	else { cout << res << ser << endl; }
	cout << endl;
	cin.ignore(2); return 0;
}