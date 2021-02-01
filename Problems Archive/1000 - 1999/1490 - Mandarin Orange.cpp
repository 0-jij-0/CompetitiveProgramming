#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> v;

int largestRectangleArea(vector<int>& A) {
    stack<int> st; st.push(-1);  
    int n = (int) A.size();  int res = 0;

    for (int i = 0; i < n; i++) {
        while (st.top() != -1 and A[st.top()] >= A[i]) {
            int curH = A[st.top()]; st.pop();
            int curW = i - st.top() - 1;
            res = max(curH * curW, res);
        }
        st.push(i);
    }

    //Still few entries left on stack
    while (st.top() != -1) {
        int curH = A[st.top()]; st.pop();
        int curW = n - st.top() - 1;
        res = max(curH * curW, res);
    }
    return res;
}

int main() {
    int n; cin >> n; v.resize(n);
    for (auto& x : v) { cin >> x; }
    cout << largestRectangleArea(v) << '\n';
    cin.ignore(2); return 0;
}