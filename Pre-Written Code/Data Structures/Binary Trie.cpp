#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;

struct BinaryTrie {
	struct TrieNode {int count = 0; TrieNode* next[2] = { NULL, NULL }; } *root;
	int depth; BinaryTrie(int d) : depth(d) { root = new TrieNode(); }

	void insert(ll &x) {
		TrieNode *cur = root;
		for (int i = depth - 1; i >= 0; i--) {
			bool bit = (x >> i) & 1;
			if (cur->next[bit] == NULL) { cur->next[bit] = new TrieNode(); }
			cur->count++; cur = cur->next[bit];
		}
	} 

	ll maxXor(ll &x) {
		ll res = 0; TrieNode* cur = root;
		for(int i = depth - 1; i >= 0; i--) {
			res <<= 1; bool bit = (x >> i) & 1;
			if (cur->next[!bit] == NULL) { cur = cur->next[bit]; }
			else { res |= 1; cur = cur->next[!bit]; }
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