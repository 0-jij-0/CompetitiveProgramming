#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

vector<int> p, q;

int main() {
	int n, k; cin >> n >> k; k--;
	p.resize(n); q.resize(n);
	for (auto &x : p) { cin >> x; x--; }
	for (auto &x : q) { cin >> x; x--; }
	if (k == 0) { cout << "YES" << endl << string(n, 'a') << endl; }
	else {
		set<int> dis, total, rem;
		for (int i = 0; i < n; i++) { rem.insert(i); }
		string res(n, '0'); int cur = 0;
		for (int i = 0; i < n; i++) {
			if (dis.count(p[i])) { dis.erase(p[i]); }
			else { dis.insert(p[i]); total.insert(p[i]); rem.erase(p[i]); }
			if (dis.count(q[i])) { dis.erase(q[i]); }
			else { dis.insert(q[i]); total.insert(q[i]); rem.erase(q[i]); }
			if (dis.empty()) {
				for (auto &x : total) { res[x] = cur + 'a'; }
				total.clear(); cur++;
				if (cur == k) {
					if (rem.empty()) { cur = 0; break; }
					for (auto &x : rem) { res[x] = cur + 'a'; }
					break;
				}
			}
		}
		if (cur != k) { cout << "NO" << endl; }
		else { cout << "YES" << endl << res << endl; }
	}
	cin.ignore(2); return 0;
}