#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

void find_seq() {
	sort(v.begin(), v.end());
	long long cur;
	for (unsigned int i = 0; i < v.size(); i++) {
		long long x = (v[i] % 2 == 0) ? v[i] / 2 : -1;
		long long y = v[i] * 3;
		bool b1 = binary_search(v.begin(), v.end(), x);
		if (b1) { continue; }
		bool b2 = binary_search(v.begin(), v.end(), y);
		if (b2) { continue; }
		cur = v[i]; break;
	}
	unsigned int i = 0;
	while (true) {
		cout << cur; i++;
		if (i != v.size()) { cout << " "; }
		else { cout << endl; break; }
		long long x = (cur % 3 == 0) ? cur / 3 : -1;
		long long y = cur * 2;
		bool b1 = binary_search(v.begin(), v.end(), x);
		if (b1) { cur = x; continue; }
		bool b2 = binary_search(v.begin(), v.end(), y);
		if (b2) { cur = y; continue; }
	}
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	find_seq();
	cin.ignore(2); return 0;
}