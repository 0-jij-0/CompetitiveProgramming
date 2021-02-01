#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, a; int n;

vector<int> easy() {
	vector<int> res(n);
	for (int i = 0; 2 * i < n; i++)
		res[2 * i] = a[n - 1 - i];
	for (int i = 0; 2 * i + 1 < n; i++)
		res[2 * i + 1] = a[i];
	return move(res);
}

vector<int> hard() {
	vector<int> res(n);
	int i = 0; for (; 2 * i < n; i++)
		res[2 * i] = a[n - 1 - i];

	int j = n - 1 - n % 2;
	for (int k = 0; k <= n - 1 - i; k++, j -= 2) res[j] = a[k];
	return move(res);
}

int check(vector<int> &b) {
	int res = 0; for (int i = 1; i < n - 1; i++)
		res += (b[i] < b[i - 1] && b[i] < b[i + 1]);
	return res;
}

int main() {
	cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	a = v; sort(a.begin(), a.end());

	vector<int> e = easy(), h = hard();
	int E = check(e), H = check(h);
	if (E < H) { swap(E, H); swap(e, h); }

	cout << E << '\n';
	for (auto &x : e) cout << x << ' '; 
	cout << '\n';cin.ignore(2); return 0;
}