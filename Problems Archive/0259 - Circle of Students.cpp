#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool check() {
	if (v.size() == 1) { return true; }
	auto it = find(v.begin(), v.end(), 1);
	int idx = find(v.begin(), v.end(), 1) - v.begin();
	if (idx != 0 && v[idx - 1] == 2 || idx == 0 && v.back() == 2) {
		it++;
		vector<int> q; q.insert(q.begin(), it, v.end());
		v.erase(it, v.end()); v.insert(v.begin(), q.begin(), q.end());
		reverse(v.begin(), v.end());
		for (int i = 0; i < (int)v.size(); i++) {
			if (v[i] != i + 1) { return false; }
		}
		return true;
	}
	if ((idx != v.size() - 1 && v[idx + 1] == 2) || (idx == v.size() - 1 && v[0] == 2)) {
		vector<int> q; q.insert(q.begin(), v.begin(), it);
		v.erase(v.begin(), it); for (auto &x : q) { v.push_back(x); }
		for (int i = 0; i < (int)v.size(); i++) {
			if (v[i] != i + 1) { return false; }
		}
		return true;
	}
	return false;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n; cin >> n;
		v.clear(); v.resize(n);
		for (auto &x : v) { cin >> x; }
		bool b = check();
		if (b) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}