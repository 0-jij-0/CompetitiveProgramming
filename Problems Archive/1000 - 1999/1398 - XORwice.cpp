#include <iostream>
using namespace std;

int main(){
    int t; cin >> t; while(t--) {
        int a, b; cin >> a >> b;
        int x = a & b;
        cout << (a ^ x) + (b ^ x) << '\n';
    }
    cin.ignore(2); return 0;
}