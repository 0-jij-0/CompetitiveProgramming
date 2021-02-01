#include <iostream>
#include <vector>
using namespace std;

vector<int> num, idx;
int n;

int op_num(int a, int b) {
	if (a == b) { return 0; }
	if (a > b) { swap(a, b); }
	int d = b - a;
	swap(idx[num[a]], idx[num[b]]);
	swap(num[a], num[b]);
	if (2 * d >= n) { return 1; }
	if (b <= n / 2 || a > n / 2) { return 3; }
	return 5;
}

void move_op(int a, int b) {
	if (a == b) { return; }
	if (a > b) { swap(a, b); }
	int d = b - a;
	swap(idx[num[a]], idx[num[b]]);
	swap(num[a], num[b]);
	if (2 * d >= n) {
		cout << a << ' ' << b << endl; return;
	}
	if (b <= n / 2) {
		cout << a << ' ' << n << endl;
		cout << b << ' ' << n << endl;
		cout << a << ' ' << n << endl;
		return;
	}
	if (a > n / 2) {
		cout << 1 << ' ' << a << endl;
		cout << 1 << ' ' << b << endl;
		cout << 1 << ' ' << a << endl;
		return;
	}
	cout << a << ' ' << n << endl;
	cout << 1 << ' ' << b << endl;
	cout << 1 << ' ' << n << endl;
	cout << a << ' ' << n << endl;
	cout << 1 << ' ' << b << endl;
}

void restore_perm() {
	vector<int> temp1 = num, temp2 = idx;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += op_num(idx[i], i);
	}
	num = move(temp1); idx = move(temp2);
	cout << res << endl;
	for (int i = 1; i <= n; i++) {
		move_op(idx[i], i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	num.resize(n + 1); idx.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		num[i] = a; idx[a] = i;
	}
	restore_perm();
	cin.ignore(2); return 0;
}