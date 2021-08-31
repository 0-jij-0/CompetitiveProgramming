#include <fstream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

set<char> vowels = { 'A', 'E', 'I', 'O', 'U' };

int tryLetter(const string &s, const char c) {
	int res = 0; for (auto& x : s) if(x != c)
		res += 1 + !(vowels.count(x) ^ vowels.count(c));
	return res;
}

int main() {
	ifstream cin("A1.in.txt");
	ofstream cout("A1.out.txt");

	int T; cin >> T; 
	for (int t = 1; t <= T; t++) {
		string s; cin >> s; int n = (int)s.size();

		int res = n << 1;
		for (char c = 'A'; c <= 'Z'; c++)
			res = min(res, tryLetter(s, c));

		cout << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}