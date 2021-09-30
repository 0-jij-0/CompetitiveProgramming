#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); deque<int> dq;
		for (auto& x : v) { 
			cin >> x; if (dq.empty()) { dq.push_back(x); continue; }
			(x < dq.front() ? dq.push_front(x) : dq.push_back(x));
		}
		for (auto& x : dq) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}