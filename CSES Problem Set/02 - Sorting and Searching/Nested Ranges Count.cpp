#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MIN = 0, MAX = 4 * 1000 * 100 + 5;
vector<int> A, B; 
vector<pair<pair<int, int>, int>> v;
vector<int> res1, res2, comp;

struct WaveletTree {
	int lVal, rVal; int n;
	WaveletTree* lC, * rC;
	vector<int> left; 		

	WaveletTree(int _n) : WaveletTree(0, n = _n - 1, MIN, MAX) {}

	WaveletTree(int lo, int hi, int x, int y) {
		lVal = x; rVal = y;
		if (lVal == rVal || hi < lo) { lC = rC = nullptr; return; }

		int mid = (lVal + rVal) >> 1;
		auto f = [&](const int& x) { left.push_back(x <= mid); };
		for_each(A.begin() + lo, A.begin() + hi + 1, f);
		partial_sum(left.begin(), left.end(), left.begin());

		auto comp = [&](const int& x) { return x <= mid; };
		int pivot = stable_partition(A.begin() + lo, A.begin() + hi + 1, comp) - A.begin();
		lC = new WaveletTree(lo, pivot - 1, lVal, mid);
		rC = new WaveletTree(pivot, hi, mid + 1, rVal);
	}

	//Query #2: #numbers <= k in [l, r]
	int lessThanK(int l, int r, int k) {
		if (l > r || k < lVal) { return 0; }
		if (rVal <= k) { return r - l + 1; }

		int befL = (l ? left[l - 1] : 0);
		return lC->lessThanK(befL, left[r] - 1, k) + rC->lessThanK(l - befL, r - left[r], k);
	}

	//EXTRA: #numbers >= k in [l, r]
	int greaterThanK(int l, int r, int k) { return r - l + 1 - lessThanK(l, r, k - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n); A.resize(n);
	res1.resize(n); res2.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		comp.push_back(v[i].first.first);
		comp.push_back(v[i].first.second);
		v[i].second = i;
	}

	sort(comp.begin(), comp.end()); comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 0; i < n; i++){
		v[i].first.first = lower_bound(comp.begin(), comp.end(), v[i].first.first) - comp.begin();
		v[i].first.second = lower_bound(comp.begin(), comp.end(), v[i].first.second) - comp.begin();
	}

	auto comp = [&](const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2) {
		if (p1.first.first != p2.first.first) return p1.first.first < p2.first.first;
		return p1.first.second > p2.first.second;
	}; sort(v.begin(), v.end(), comp); 
	for (int i = 0; i < n; i++) A[i] = v[i].first.second;
	WaveletTree wt(n);

	for (int i = 0; i < n; i++) {
		res1[v[i].second] = wt.lessThanK(i + 1, n - 1, v[i].first.second);
		res2[v[i].second] = wt.greaterThanK(0, i - 1, v[i].first.second);
	}

	for (auto& x : res1) cout << x << ' '; cout << '\n';
	for (auto& x : res2) cout << x << ' '; cout << '\n';
}