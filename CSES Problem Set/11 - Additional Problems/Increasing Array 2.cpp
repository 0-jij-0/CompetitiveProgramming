#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) cin >> x;

	priority_queue<int> pq; 
	pq.push(v[0]); ll res = 0; 

	for (int i = 1; i < n; i++) {
		pq.push(v[i]); if (pq.top() > v[i])	{
			res += pq.top() - v[i]; 
			pq.pop(); pq.push(v[i]);
		}
	}
	
	cout << res << '\n';
}