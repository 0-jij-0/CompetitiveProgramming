#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

vector<string> v;
vector<int> h;
int n, m;

int largestRectangleArea() {
    stack<int> st; int res = 0;
    for (int i = 0; i <= m; i++) {
        while (!st.empty() && h[st.top()] > h[i]) {
            int cur = h[st.top()]; st.pop();
            int prev = st.empty() ? -1 : st.top();
            res = max(res, cur * (i - prev - 1));
        }
        st.push(i);
    }
    return res;
}

int maximalRectangle() {
    h.resize(m + 1); int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            v[i][j] == '.' ? h[j]++ : h[j] = 0;
        res = max(res, largestRectangleArea());
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m; v.resize(n);
    for (auto& x : v) { cin >> x; }
    cout << maximalRectangle() << '\n';
    cin.ignore(2); return 0;
}