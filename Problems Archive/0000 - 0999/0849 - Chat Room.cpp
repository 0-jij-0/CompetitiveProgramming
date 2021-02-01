#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t = "hello";

int main() {
	cin >> s; int j = -1, n = (int)s.size();
	for (int i = 0; i < 5 && j < n; i++)
		j = find(s.begin() + 1 + j, s.end(), t[i]) - s.begin();
	cout << (j == n ? "NO" : "YES") << endl;
	cin.ignore(2); return 0;
}