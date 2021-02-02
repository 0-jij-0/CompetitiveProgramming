#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

struct answer {
	long double min = 123456789.0, max = 0.0;
	int min_mask = -1, max_mask = -1; answer() {}
	answer(long double m1, long double m2, int i1, int i2) :
		min(m1), max(m2), min_mask(i1), max_mask(i2) {}
};

vector<int> sum[13];
answer dp[550][13];
long double p[13];

int find_sum(int x) {
	int mask = 1, j = 1, res = 0;
	while (mask <= x) {
		if (mask & x) { res += j; }
		mask <<= 1; j++;
	}
	return res;
}

int find_num(int x) {
	int res = 0; int mask = 1, j = 1;
	while (mask <= x) {
		if (mask & x) { res *= 10; res += j; }
		mask <<= 1; j++;
	}
	return res;
}

void fill_sum(int x, int n) {
	if (n == 9) {
		int y = find_sum(x);
		if (y > 1 && y < 13) { sum[y].push_back(x); }
		return;
	}
	fill_sum(x << 1, n + 1);
	fill_sum(x << 1 | 1, n + 1);
}

void fill_p() {
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			p[i + j] += 1.0;
	for (int i = 0; i < 13; i++) { p[i] /= 36.0; }
}

int find_state(int x) {
	int mask = 0;
	while (x != 0) {
		int y = x % 10;
		mask = mask | (1 << (y - 1));
		x /= 10;
	}
	return mask;
}

answer exp(int mask, int s) {
	if (dp[mask][s].min_mask != -1) { return dp[mask][s]; }
	int n = (int)sum[s].size(); bool finish = n > 0;
	long double min_res = INT_MAX + 0.0, max_res = -1.0;
	int min_m = 0, max_m = 0;

	for (int i = 0; i < n; i++) {
		long double min_ans = 0.0, max_ans = 0.0;
		if ((sum[s][i] & mask) == sum[s][i]) {
			finish = false;
			int new_mask = mask ^ sum[s][i];
			for (int j = 2; j <= 12; j++) {
				min_ans += p[j] * exp(new_mask, j).min;
				max_ans += p[j] * exp(new_mask, j).max;
			}
			if (min_ans < min_res) { min_res = min_ans; min_m = sum[s][i]; }
			if (max_ans > max_res) { max_res = max_ans; max_m = sum[s][i]; }
		}
	}
	long double ld = (long double)find_num(mask);
	if (finish) { return dp[mask][s] = answer(ld, ld, 0, 0); }
	return dp[mask][s] = answer(min_res, max_res, min_m, max_m);
}

void resetDP() {
	for (int i = 0; i < 550; i++)
		for (int j = 0; j < 13; j++)
			dp[i][j] = answer();
}

int main() {
	resetDP(); fill_sum(0, 0); fill_p();
	int x, a, b; cin >> x >> a >> b;
	int mask = find_state(x);
	answer ans = exp(mask, a + b);
	if (ans.min_mask == 0) {
		cout << fixed << setprecision(5) << -1 << ' ' << (double)x << endl;
		cout << fixed << setprecision(5) << -1 << ' ' << (double)x << endl;
	}
	else {
		cout << fixed << setprecision(5) << find_num(ans.min_mask) << ' ' << ans.min << endl;
		cout << fixed << setprecision(5) << find_num(ans.max_mask) << ' ' << ans.max << endl;
	}

	cin.ignore(2); return 0;
}