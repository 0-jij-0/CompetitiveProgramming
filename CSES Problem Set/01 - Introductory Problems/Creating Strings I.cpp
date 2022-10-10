#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s; cin >> s; sort(s.begin(), s.end()); vector<string> res(1, s);
	while (next_permutation(s.begin(), s.end())) { res.push_back(s); }
	cout << res.size() << '\n'; for (auto &x : res) { cout << x << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}