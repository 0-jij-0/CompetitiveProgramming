#include <iostream>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; while(m--){
		int a, b; cin >> a >> b;
		if(a > b) swap(a, b);
		cout << a << ' ' << b << '\n';
	}
}