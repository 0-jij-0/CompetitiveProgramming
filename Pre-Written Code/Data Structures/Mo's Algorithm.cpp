#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

const int block = 450;			//Set it to sqrt(n)
int freq[(int)1e6 + 2];		//Set to the range of numbers
vector<int> nums;
ll curAns;

struct query {
	int L, R, idx;
	query(int l, int r, int i) : L(l), R(r), idx(i) {}

	bool operator<(const query& q2) {
		int b1 = L / block, b2 = q2.L / block;
		if (b1 != b2) { return b1 < b2; }
		return (b1 & 1) ? (R > q2.R) : (R < q2.R);
	}
};

//i is only an index in the array!
void add(int i) {
	
}

void remove(int i) {

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, t; cin >> n >> t;
	nums.resize(n);
	for (auto &x : nums) { cin >> x; }

	vector<query> queries;
	for (int i = 0; i < t; i++) {
		int l, r; cin >> l >> r; l--; r--;
		queries.push_back(query(l, r, i));
	}
	sort(queries.begin(), queries.end());

	vector<ll> ans(t);
	int L = 0, R = -1;
	for (auto &q : queries) {
		while (R < q.R) { add(++R); }
		while (L > q.L) { add(--L); }
		while (L < q.L) { remove(L++); }
		while (R > q.R) { remove(R--); }
		ans[q.idx] = curAns;
	}

	for (auto &x : ans) { cout << x << '\n'; }
}