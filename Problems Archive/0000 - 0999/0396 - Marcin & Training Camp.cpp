#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<long long> a; vector<int> b; int n;
vector<set<int>> not_better;
set<long long> res; map<long long, int> m;

void add(int idx, long long x) {
	if (m[x] > 1) { not_better[idx].insert(idx); return; }
	int i = 0;
	for (auto &y : m) {
		if (y.first == x) { i++; continue; }
		long long AND = x & y.first;
		if (x ^ AND) { i++; continue; }
		not_better[idx].insert(i); i++;
	}
}

long long max_skills() {
	bool check = true; set<int> rem;
	while (check) {
		check = false;
		for (int i = 0; i < (int)m.size(); i++) {
			if (rem.count(i)) { continue; }
			if (!not_better[i].empty()) { continue; }
			check = true; rem.insert(i);
			for (int j = 0; j < (int)m.size(); j++) {
				if (not_better[j].count(i)) { not_better[j].erase(i); }
			}
		}
	}
	int i = 0;
	for (auto &x : m) {
		if (not_better[i].empty()) { i++; continue; }
		res.insert(x.first); i++;
	}
	long long sum = 0; int count = 0;
	for (i = 0; i < n; i++) {
		if (res.count(a[i])) { sum += b[i]; count++; }
	}
	return (count > 1) ? sum : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n; a.resize(n); b.resize(n);
	for (auto &x : a) { cin >> x; m[x]++; }
	for (auto &x : b) { cin >> x; }
	not_better.resize(m.size());

	int i = 0; for (auto &x : m) { add(i, x.first); i++; }
	cout << max_skills() << endl;
	cin.ignore(2); return 0;
}