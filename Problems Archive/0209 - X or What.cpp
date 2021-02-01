#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<int> odd_idx;
vector<int> num;

int count1s(int n) {
	int res = 0;
	while (n != 0) {
		if (n % 2) { res++; }
		n /= 2;
	}
	return res;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";
		int n, q; cin >> n >> q;
		num.clear(); odd_idx.clear();
		int xor_sum = 0;
		for (int j = 0; j < n; j++) {
			int a; cin >> a; xor_sum ^= a;
			num.push_back(a);
			if (count1s(a) % 2) { odd_idx.insert(j); }
		}
		for (int j = 0; j < q; j++) {
			int p, v; cin >> p >> v;
			if ((count1s(num[p]) % 2) ^ (count1s(v) % 2)) {
				if (count1s(v) % 2) { odd_idx.insert(p); }
				else { odd_idx.erase(p); }
			}
			xor_sum ^= num[p]; num[p] = v; xor_sum ^= num[p];
			int x = count1s(xor_sum);
			if (x % 2 == 0) { cout << n; }
			else {
				int l = *odd_idx.rbegin();
				int r = n - *odd_idx.begin() - 1;
				cout << max(l, r);
			}
			if (j + 1 != q) { cout << ' '; }
			else { cout << endl; }
		}
	}
	cin.ignore(2); return 0;
}