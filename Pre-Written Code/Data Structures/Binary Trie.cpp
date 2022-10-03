#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BinaryTrie {
	struct TrieNode { int next[2] = { -1, -1 }; };
	vector<TrieNode> nodes; int depth;
	
	BinaryTrie(int d) : depth(d), nodes(1) { }

	void insert(ll &x) {
		int cur = 0;
		for (int i = depth - 1; i >= 0; i--) {
			bool bit = (x >> i) & 1;
			if (nodes[cur].next[bit] == -1) {
				nodes[cur].next[bit] = (int) nodes.size();
				nodes.emplace_back();
			}
			cur = nodes[cur].next[bit];
		}
	} 

	ll maxXor(ll &x) {
		ll res = 0; int cur = 0;
		for(int i = depth - 1; i >= 0; i--) {
			bool bit = (x >> i) & 1;
			if (nodes[cur].next[!bit] == -1) { cur = nodes[cur].next[bit]; }
			else { res |= (1ll << i); cur = nodes[cur].next[!bit]; }
		}
		return res;
	}

	ll maxXorTwoElem(vector<ll> &v) {
		ll res = 0;
		for (auto &x : v) { insert(x); res = max(res, maxXor(x)); }
		return res;
	}

	ll maxXorSubarray(vector<ll> &v) {
		partial_sum(v.begin(), v.end(), v.begin(), bit_xor<ll>());
		v.push_back(0); return maxXorTwoElem(v);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}