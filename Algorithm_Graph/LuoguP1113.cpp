#include<bits/stdc++.h>
using namespace std;


//���P1113����-�������򡪡�Ҫ����Ŷ
int main() {
	int t[100010],n,v,k,ret;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> i >> v;
		int tmp = 0;
		cin >> k;
		while ( k!=0) {
			tmp = max(t[k], tmp);
			cin >> k;
		}
		t[i] = tmp + v;
		ret = max(t[i], ret);
	}
	cout << ret << endl;
	return 0;
}