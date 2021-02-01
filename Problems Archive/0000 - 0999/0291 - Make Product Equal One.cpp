#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	long long min = 0, prod = 1; bool zero = false;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) { zero = true; min += 1; continue; }
		if (v[i] > 0) { min += v[i] - 1; continue; }
		min += (-v[i] - 1); prod *= -1;
	}
	if (prod == 1 || zero) { cout << min << endl; }
	else { cout << min + 2ll << endl; }
	cin.ignore(2); return 0;
}
