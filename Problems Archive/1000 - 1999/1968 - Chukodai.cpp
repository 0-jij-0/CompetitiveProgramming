#include <iostream>
#include <string>
using namespace std;

int main(){
	string s; int a, b; cin >> s >> a >> b;
	swap(s[--a], s[--b]); cout << s << '\n';
}