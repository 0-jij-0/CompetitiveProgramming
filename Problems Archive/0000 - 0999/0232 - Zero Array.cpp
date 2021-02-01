#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v; long long sum = 0;

bool check() {
	bool b1 = sum % 2;
	bool b2 = *max_element(v.begin(), v.end()) <= sum / 2;
	return !b1 && b2;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; sum += x; }
	bool b = check();
	if (b) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	cin.ignore(2); return 0;
}