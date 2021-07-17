#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder, inorderIDX;

void postorder(int pl, int pr, int il, int lr) {
	if (pl > pr) { return; }
	int m = inorderIDX[preorder[pl]], s = m - il;
	postorder(pl + 1, pl + s, il, m - 1);
	postorder(pl + s + 1, pr, m + 1, lr);
	cout << preorder[pl] + 1 << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; 
	preorder.resize(n);
	inorderIDX.resize(n);

	for (auto &x : preorder) { cin >> x; --x; }
	for (int i = 0; i < n; i++) {
		int x; cin >> x; inorderIDX[--x] = i;
	}

	postorder(0, n - 1, 0, n - 1);
	cin.ignore(2); return 0;
}