#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> freq, op, min_op, eq;

int main() {
	int n, k; cin >> n >> k; freq.resize(200001, 0);
	op.resize(200001, 0); min_op.resize(200001, 1000000000); eq.resize(200001, 0);
	for (int i = 0; i < n; i++) { int a; cin >> a; freq[a]++; }
	int j = 1;
	for (; j <= 200000; j++) {
		eq[j] = freq[j]; if (eq[j] >= k) { cout << 0 << endl; break; }
	}
	if(j == 200001) {
		int dif = 2, count = 1;
		while (dif < 200000) {
			for (int i = dif; i < 200001; i++) {
				int sum = 0, last_i = i;
				if (min_op[i / dif] != 1000000000) { continue; }
				for (; i < last_i + dif; i++) { 
					if (i >= 200001) { break; }
					sum += freq[i];
				}
				i--;
				if (sum + eq[i / dif] >= k) {
					sum = k - eq[i / dif];
					min_op[i / dif] = op[i / dif] + sum * count;
					continue;
				}
				if (i == 200000) { break; }
				op[i / dif] += sum * count; eq[i / dif] += sum;
			}
			count++; dif <<= 1;
		}
		int res = *min_element(min_op.begin(), min_op.end());
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}