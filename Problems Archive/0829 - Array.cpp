#include <iostream>
#include <vector>
using namespace std;

vector<int> pos, neg, zero;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 0) { zero.push_back(x); continue; }
		(x < 0 ? neg : pos).push_back(x);
	}
	if (neg.size() % 2 == 0) { zero.push_back(neg.back()); neg.pop_back(); }
	if (pos.empty()) { 
		pos.push_back(neg.back()); neg.pop_back();
		pos.push_back(neg.back()); neg.pop_back();
	}
	cout << neg.size() << ' '; for (auto &x : neg) { cout << x << ' '; } cout << endl;
	cout << pos.size() << ' '; for (auto &x : pos) { cout << x << ' '; } cout << endl;
	cout << zero.size() << ' '; for (auto &x : zero) { cout << x << ' '; } cout << endl;
	cin.ignore(2); return 0;
}