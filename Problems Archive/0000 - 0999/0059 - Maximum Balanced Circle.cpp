#include <iostream>
#include <vector>
using namespace std;

vector<int> heights;

void max(int n, int m) {
	vector<int> count;
	count.resize(m);
	for (int i = 0; i < n; i++) { count[heights[i]]++; }
	for (int i = 0; i < m; i++) { cout << count[i] << " "; }
	cout << endl;
	int from = 1, to = 1, cur_count = 0;
	int max_from = 1, max_to = 1, max_count = 0;
	bool odd = false, high = false, both = false;
	bool max_odd = false, max_high = false, max_both = false;
	int odd_cnt = 0;

	for (int i = 1; i <= m; i++) {
		if (i == m) {
			to--;
			if (cur_count > max_count) {
				max_from = from; max_to = to; max_count = cur_count;
				max_odd = odd; max_high = high; max_both = both;
			}
			break;
		}
		if (count[i] == 0 && cur_count == 0) { from++; to++; continue; }
		if (count[i] == 0) {
			to--;
			if (cur_count > max_count) {
				max_from = from; max_to = to; max_count = cur_count;
				max_odd = odd; max_high = high; max_both = both;
			}
			to += 2; from = to; cur_count = 0;
			odd = false; high = false; both = false; continue;
		}
		if (cur_count == 0) {
			cur_count += count[i];
			odd = count[i] % 2;
			if (odd) { odd_cnt = count[i]; high = false; }
			to++; continue;
		}
		//I already took a number and the current count is non-zero
		if (count[i] % 2 == 0) {
			cur_count += count[i];
			to++; continue;
		}
		//I already took a number and the current count is odd
		if (!odd) {
			cur_count += count[i];
			if (cur_count > max_count) {
				max_from = from; max_to = to; max_count = cur_count;
				max_odd = odd; max_high = high; max_both = both;
			}
			to++; from = to; cur_count = 0;
			odd = false; high = false; both = false; continue;
		}
		//the first and current counts are odd
		if (to - from == 1) {
			cur_count += count[i]; both = true;
			if (cur_count > max_count) {
				max_from = from; max_to = to; max_count = cur_count;
				max_odd = odd; max_high = high; max_both = both;
			}
			to++; from = to; cur_count = 0;
			odd = false; high = false; both = false; continue;
		}
		//I already took more than one number and the first and current counts are odd
		if (count[i] > odd_cnt) {
			from++; cur_count += count[i] - odd_cnt; high = true;
			if (cur_count > max_count) {
				max_from = from; max_to = to; max_count = cur_count;
				max_odd = odd; max_high = high; max_both = both;
			}
			to++; from = to; cur_count = 0;
			odd = false; high = false; both = false; continue;
		}
		//I already took a number and the current count is odd and I started with an odd count bigger than the current one
		to--;
		if (cur_count > max_count) {
			max_from = from; max_to = to; max_count = cur_count;
			max_odd = odd; max_high = high; max_both = both;
		}
		to += 2; from = to; cur_count = 0;
		odd = false; high = false; both = false; continue;
	}

	from = max_from; to = max_to;
	odd = max_odd; high = max_high; both = max_both;
	cout << max_count << endl;

	if (!odd) {
		for (int i = from; i <= to; i++) {
			int c = count[i] / 2;
			while (count[i] != c) { cout << i << " "; count[i]--; }
		}
		for (int i = to; i >= from; i--) {
			while (count[i] != 0) {
				cout << i; count[i]--;
				if (i != from || count[i] != 0) { cout << " "; }
			}
		}
		cout << endl; return;
	}
	if (both) {
		while (count[from] != 0) { 
			cout << from << " "; count[from]--;
		}
		while (count[to] != 0) {
			cout << to; count[to]--;
			if (count[to] != 0) { cout << " "; }
		}
		cout << endl; return;
	}
	if (high) {
		for (int i = from; i < to; i++) {
			int c = count[i] / 2;
			while (count[i] != c) { cout << i << " "; count[i]--; }
		}
		while (count[to] != 0) { cout << to << " "; count[to]--; }
		for (int i = to - 1; i >= from; i--) {
			while (count[i] != 0) {
				cout << i;
				if (i != from || count[i] != 0) { cout << " "; }
				count[i]--;
			}
		}
		cout << endl; return;
	}
	for (int i = to; i > from; i--) {
		int c = count[i] / 2;
		while (count[i] != c) { cout << i << " "; count[i]--; }
	}
	while (count[from] != 0) { cout << from << " "; count[from]--; }
	for (int i = from + 1; i <= to; i++) {
		while (count[i] != 0) {
			cout << i;
			if (i != from || count[i] != 0) { cout << " "; }
			count[i]--;
		}
	}
}

int main() {
	int n; cin >> n; int m = 0;
	heights.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
		m = (m < heights[i]) ? heights[i] : m;
	}
	max(n, m + 1);
	cin.ignore(2); return 0;
}