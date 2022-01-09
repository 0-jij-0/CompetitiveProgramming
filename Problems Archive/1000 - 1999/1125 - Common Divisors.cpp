#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1000001, 0);
const int N = 1000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; while (n--) {
		int x; cin >> x; v[x]++;
	}

	for (int i = N, res = 0; i > 0; i--, res = 0) {
		for (int j = i; j <= N; j += i)	res += v[j];
		if (res > 1) { cout << i << '\n'; break; }
	}
	cin.ignore(2); return 0;
}