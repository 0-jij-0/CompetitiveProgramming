#include <iostream>
#include <string>
using namespace std;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string s; cin >> s; int n = (int)s.size();
		string res; int depth = 0;
		for (int i = 0; i < n; i++) {
			int x = s[i] - '0';
			if (x < depth) { res += string(depth - x, ')'); }
			if (x > depth) { res += string(x - depth, '('); }
			res.push_back(s[i]); depth = x;
		}
		res += string(depth, ')');
		cout << "Case #" << t << ": " << res << endl;
	}
	cin.ignore(2); return 0;
}