#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

struct DynamicHash {
	static const ll m1 = 8675309, m2 = 1e9 + 7;
	static const ll s1 = 257, s2 = 619;
	static const int SZ = 1e6;
	static ll s1Pow[SZ], s2Pow[SZ];
	static bool precomp;
	ll v1 = 0, v2 = 0; int l = 0;

	DynamicHash() {}
	DynamicHash(const DynamicHash& oh) : v1(oh.v1), v2(oh.v2), l(oh.l) {}
	DynamicHash(const string& s) {
		v1 = v2 = 0; l = 0;
		for (auto& c : s) { add(c); }
	}

	static void precompute() {
		if (precomp) { return; }
		precomp = true;
		s1Pow[0] = s2Pow[0] = 1;
		for (int i = 1; i < SZ; i++)
			s1Pow[i] = (s1Pow[i - 1] * s1) % m1;
		for (int i = 1; i < SZ; i++)
			s2Pow[i] = (s2Pow[i - 1] * s2) % m2;
	}

	void add(const char c) {
		v1 = (v1 * s1 + c) % m1;
		v2 = (v2 * s2 + c) % m2;
		l++;
	}

	bool equal(const DynamicHash& oh) {
		if (v1 != oh.v1) { return false; }
		return v2 == oh.v2;
	}

	void append(const DynamicHash& oh) {
		precompute();
		v1 = (v1 * s1Pow[oh.l] + oh.v1) % m1;
		v2 = (v2 * s2Pow[oh.l] + oh.v2) % m2;
		l += oh.l;
	}

	//Class method
	static vector<DynamicHash> getPrefixHashes(const string& word) {
		precompute();
		int n = word.size();
		vector<DynamicHash> res(n + 1);
		res[0] = DynamicHash();
		for (int i = 1; i <= n; i++) {
			res[i] = DynamicHash(res[i - 1]);
			res[i].add(word[i - 1]);
		}
		return res;
	}

	//l, r 0-indexed
	static DynamicHash substringHash(vector<DynamicHash>& prefixHashes, int l, int r) {
		DynamicHash res = prefixHashes[r + 1], toSub = prefixHashes[l];
		int diff = r - l + 1;
		res.v1 = (res.v1 - (toSub.v1 * s1Pow[diff]) % m1 + m1) % m1;
		res.v2 = (res.v2 - (toSub.v2 * s2Pow[diff]) % m2 + m2) % m2;
		res.l = diff;
		return res;
	}
};

bool DynamicHash::precomp = false;
ll DynamicHash::s1Pow[SZ];
ll DynamicHash::s2Pow[SZ];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}