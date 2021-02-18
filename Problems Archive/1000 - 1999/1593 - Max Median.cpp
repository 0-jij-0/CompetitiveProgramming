#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> a; int n, k;
 
int maxSumSubarrayAtLeastK(vector<int> &v) {
    vector<int> maxSum(n); maxSum[0] = v[0]; 
    int cur = v[0]; for (int i = 1; i < n; i++)
        maxSum[i] = cur = max(v[i], cur + v[i]);

    int sum = 0;
    for (int i = 0; i < k; i++) sum += v[i];

    int res = sum; for (int i = k; i < n; i++) {
        sum = sum + v[i] - v[i - k];
        res = max(res, sum);
        res = max(res, sum + maxSum[i - k]);
    }
    return res;
}

bool check(int m) {
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = (a[i] < m ? -1 : 1);

	return maxSumSubarrayAtLeastK(v) > 0;
}

int maxMedian() {
	int l = 0, r = n;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		check(mid) ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	cin >> n >> k; a.resize(n);
	for (auto& x : a) { cin >> x; }
	cout << maxMedian() << '\n';
	cin.ignore(2); return 0;
}