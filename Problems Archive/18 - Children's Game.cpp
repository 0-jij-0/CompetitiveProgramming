#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(const string &a, const string &b) {
	string x = a + b, y = b + a;
	return x > y;
}

vector<string> v;

int main() {
	int n; cin >> n;
	while (n != 0) {
		v.resize(n); for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end(), compare);
		for (auto &x : v) { cout << s[i]; }
		cout << endl; cin >> n;
	}
	return 0;
}