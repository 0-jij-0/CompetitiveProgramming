#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
const int bitN = 1001;

struct subsetSumStack {
	vector<int> v; bool rev; int s;
	vector<bitset<bitN>> subsetSum;

	subsetSumStack(int _s, bool r) : s(_s), rev(r) {
		subsetSum.emplace_back();
		subsetSum[0].set(rev ? s : 0);
	}

	void push(int x) {
		v.push_back(x);
		bitset<bitN>& cur = subsetSum.back();
		bitset<bitN> upd = (rev ? cur >> x : cur << x);
		subsetSum.push_back(cur | upd);
	}

	void pop() { v.pop_back(); subsetSum.pop_back(); }
	void clear() { v.clear(); subsetSum.clear(); }
	bool empty() { return subsetSum.size() == 1; }
};

vector<int> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, s; cin >> n >> s; A.resize(n);
	for (auto& x : A) cin >> x;

	subsetSumStack L(s, 1), R(s, 0); auto isGood = [&]() {
		return (L.subsetSum.back() & R.subsetSum.back()).any();
	}; 

	int res = n + 1;
	for (int i = 0, j = 0; i < n; i++, L.pop()) {
		while (j < n && !isGood()) { R.push(A[j++]); }
		if (isGood()) { res = min(res, j - i); }
		if (L.empty()) while (!R.empty()) { L.push(R.v.back()); R.pop(); }
	}

	cout << (res == n + 1 ? -1 : res) << '\n';
}