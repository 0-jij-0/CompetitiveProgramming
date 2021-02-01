#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n >> s;
		int x = find(s.begin(), s.end(), '>') - s.begin();
		int y = find(s.rbegin(), s.rend(), '<') - s.rbegin();
		cout << min(x, y) << endl;
	}
	cin.ignore(2); return 0;
}