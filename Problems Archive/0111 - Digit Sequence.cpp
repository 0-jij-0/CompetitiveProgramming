#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

vector<long long> decade, pre;

void precompute() {
	decade.resize(18); decade[0] = 0;
	int count = 1; long long x = 1;
	while(count < 18){
		decade[count] = x * 9 * count;
		count++; x *= 10;
	}
	pre.resize(18);
	partial_sum(decade.begin(), decade.end(), pre.begin());
	decade[1] = 1; for (int i = 2; i < 18; i++) { decade[i] = 10 * decade[i - 1]; }
}

int find_dig(long long k) {
	int idx = lower_bound(pre.begin(), pre.end(), k) - pre.begin();
	long long x = (k - pre[idx - 1] - 1) / idx, y = (k - pre[idx - 1] - 1) % idx;
	long long num = decade[idx] + x; string s = to_string(num);
	return s[(int)y] - '0';
}

int main() {
	precompute(); long long k; cin >> k;
	cout << find_dig(k) << endl;
	cin.ignore(2); return 0;
}