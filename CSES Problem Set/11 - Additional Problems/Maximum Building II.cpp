#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n, m;

void processHistogram(vector<int> &h, vector<vector<int>> &res) {
	stack<int> st;
	for (int i = 0; i <= m; i++) {
		while (!st.empty() && h[st.top()] >= h[i]) {
			int height = h[st.top()]; st.pop();
			int prev = st.empty() ? -1 : st.top();
			int first = max(h[i] + 1, prev == -1 ? 1 : h[prev] + 1);
			int width = i - prev - 1;
			if (first <= n) res[first - 1][width - 1]++;
			if (height != n) res[height][width - 1]--;
		}
		st.push(i);
	}
}

vector<vector<int>> countRectangles() {
	vector<vector<int>> res(n, vector<int>(m));
	vector<int> h(m + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			v[i][j] == '.' ? h[j]++ : h[j] = 0;
		processHistogram(h, res);
	}

	for (int j = 0; j < m; j++)
		for (int i = 1; i < n; i++)
			res[i][j] += res[i - 1][j];
	
	for (int i = 0; i < n; i++) {
		partial_sum(res[i].rbegin(), res[i].rend(), res[i].rbegin());
		partial_sum(res[i].rbegin(), res[i].rend(), res[i].rbegin());
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; v.resize(n); 
	for (auto& x : v) { cin >> x; }
	vector<vector<int>> res = countRectangles();
	for (auto &x : res) { for (auto &y : x) cout << y << ' '; cout << '\n'; }
}