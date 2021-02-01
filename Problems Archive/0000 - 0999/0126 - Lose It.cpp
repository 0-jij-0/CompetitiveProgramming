#include <iostream>
#include <vector>
#include <map>
using namespace std;

int mapp[43];
vector<int> v;

int main() {
	mapp[4] = 1; mapp[8] = 2; mapp[15] = 3;
	mapp[16] = 4; mapp[23] = 5; mapp[42] = 6;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v.push_back(mapp[a]);
	}
	multimap<int, int> subs; int count = 0;
	for (int i = 0; i < n; i++) {
		int &m = v[i];
		if (m == 1) { pair<int, int> p(m, i); subs.insert(p); continue; }
		auto it = subs.find(m - 1); if (it == subs.end()) { count++; continue; }
		subs.erase(it); if (m == 6) { continue; }
		pair<int, int> p(m, i); subs.insert(p);
	}
	auto it = subs.begin();
	for (; it != subs.end(); it++) { count += it->first; }
	cout << count << endl;
	cin.ignore(2); return 0;
}