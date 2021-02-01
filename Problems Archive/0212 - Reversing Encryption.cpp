#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	int n; cin >> n >> s;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			reverse(s.begin(), s.begin() + i);
		}
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	cin.ignore(2); return 0;
}