#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int orss = 0, andss = 0x7fffffff;

int find_res(int i, vector<int> &v, const int &ors, const int &ands) {
	if (i == 30) { return 0; }
	int mask = 1 << (29 - i);
	if (ands & mask) { return find_res(i + 1, v, ors, ands); }
	if (!(ors & mask)) { return find_res(i + 1, v, ors, ands); }
	vector<int> z, o;
	int zors = 0, zands = 0x7fffffff, oors = 0, oands = 0x7fffffff;
	for (auto &x : v) {
		if (x & mask) {
			o.push_back(x);
			oors |= x; oands &= x;
		}
		else {
			z.push_back(x);
			zors |= x; zands &= x;
		}
	}
	return mask | min(find_res(i + 1, o, oors, oands), find_res(i + 1, z, zors, zands));
}

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { 
		cin >> x; orss |= x; andss &= x;
	}
	cout << find_res(0, v, orss, andss) << endl;
	cin.ignore(2); return 0;
}