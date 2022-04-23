#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; int n = (int)s.size();
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	bool upper = s.front() >= 'A' && s.front() <= 'Z';
	bool lower = s.back() >= 'a' && s.back() <= 'z';
	cout << (upper && lower && s.size() == n ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}