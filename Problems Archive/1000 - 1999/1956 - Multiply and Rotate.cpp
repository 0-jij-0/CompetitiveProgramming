#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int minOperations(int a, int n) {
	vector<int> d(1000 * 1000 + 1, -1);
	d[1] = 0; queue<int> q; q.push(1);

	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		if (cur == n) { return d[cur]; }
		ll A = cur * a;
		string b = (cur > 10 && cur % 10) ? to_string(cur) : "11";
		rotate(b.begin(), --b.end(), b.end());
		ll B = stoll(b);

		if (A <= 1000000 && d[A] == -1) { d[A] = 1 + d[cur]; q.push(A); }
		if (cur > 10 && cur % 10 && B <= 1000000 && d[B] == -1) { d[B] = 1 + d[cur]; q.push(B); }
	}
	return -1;
}

int main() {
	int a, n; cin >> a >> n;
	cout << minOperations(a, n) << '\n';
	cin.ignore(2); return 0;
}