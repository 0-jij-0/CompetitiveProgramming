#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int max_num() {
	int max = 0; int count = 0;
	for (auto &x : v) {
		if (max == 0 && x != 1) { count++; max = x - 1; continue; }
		if (x > max + 1) { max = x - 1; count++; continue; }
		if (x >= max) { max++; count++; continue; }
	}
	return count;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	cout << max_num() << endl;
	cin.ignore(2); return 0;
}