#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, count1, count2;
vector<pair<int, int>> res;

int main() {
	int t; cin >> t;
	while (t--) {
		v.clear(); count1.clear(); count2.clear(); res.clear();
		int n; cin >> n; v.resize(n);
		count1.resize(n + 1, 0); count2.resize(n + 1, 0);
		for (auto &x : v) { cin >> x; }
		int wrong1 = 0, wrong2 = 0;
		int max1 = v[0], max2 = 0;
		for(int i = 1; i < n; i++){
			count2[v[i]]++; if (count2[v[i]] == 2) { wrong2++; }
			max2 = max(max2, v[i]);
		}
		count1[v[0]]++; int l1 = 1, l2 = n - 1;
		while (l1 != n) {
			if (!wrong1 && !wrong2 && max1 == l1 && max2 == l2) { res.push_back({ l1, l2 }); }
			count1[v[l1]]++; if (count1[v[l1]] == 2) { break; }
			count2[v[l1]]--; if (count2[v[l1]] == 1) { wrong2--; }
			max1 = max(max1, v[l1]); while (!count2[max2]) { max2--; }
			l1++; l2--;
		}
		cout << res.size() << endl;
		for (auto &x : res)
			cout << x.first << ' ' << x.second << endl;
	}
	cin.ignore(2); return 0;
}