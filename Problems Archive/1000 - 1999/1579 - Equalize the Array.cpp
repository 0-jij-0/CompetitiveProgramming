#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> freq, invFreq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; int res = n, N = n;
		freq.clear(); invFreq.clear();
		while (n--) { int x; cin >> x; freq[x]++; }
		for (auto& x : freq) invFreq[x.second] += x.second;

		int less = N, more = 0, num = 0;
		for (auto it = invFreq.rbegin(); it != invFreq.rend(); it++) {
			less -= it->second;
			res = min(res, more + less);
			num += it->second / it->first;

			auto jt = it; jt++; if (jt != invFreq.rend())
				more += num * (it->first - jt->first);
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}