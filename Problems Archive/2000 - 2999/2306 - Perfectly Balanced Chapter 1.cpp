#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

string s;

struct StVal {
	vector<int> freq; StVal() {}
	StVal(int v) : freq(26, 0) { freq[v] = 1; }
	StVal(const StVal& L, const StVal& R) : freq(L.freq) {
		for (int i = 0; i < 26; i++) freq[i] += R.freq[i];
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(int si, int lo, int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(s[lo] - 'a'); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	StVal query(int l, int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(int l, int r, int si, int lo, int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}
};

int main() {
	ifstream cin("perfectly_balanced_chapter_1_input.txt");
	ofstream cout("perfectly_balanced_chapter_1_output.txt");
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s; int n = (int)s.size();
		SegTree st(n); int res = 0;
		int q; cin >> q; while (q--) {
			int L, R; cin >> L >> R;
			if ((--R - --L) & 1) { continue; }
			if (R == L) { res++; continue; }

			int mid = (L + R) >> 1;
			StVal left = st.query(L, mid);
			StVal right = st.query(mid + 1, R);

			bool ok = true; int dif = 0;
			for (int i = 0; i < 26; i++)
				dif += abs(left.freq[i] - right.freq[i]);

			if (dif == 1) { res++; continue; }

			left.freq[s[mid] - 'a']--;
			right.freq[s[mid] - 'a']++;

			dif = 0; for (int i = 0; i < 26; i++)
				dif += abs(left.freq[i] - right.freq[i]);

			if (dif == 1) res++;
		}

		cout << "Case #" << t << ": " << res << '\n';
	}
}