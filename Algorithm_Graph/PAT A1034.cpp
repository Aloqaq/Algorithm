#include<bits/stdc++.h>
using namespace std;
const int maxv = 2010;
map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;//head->人数

int G[maxv][maxv] = { 0 }, weight[maxv] = { 0 };//邻接矩阵G和点权weight
int n, k;// n 为联系的数量，k为团伙的联系值总和门槛
string Name1, Name2;
int  Time;
int numPerson;//总人数
bool vis[maxv] = { false };
int INF = 1000000000;

int change(string str) {//姓名与编号之间连接
	if (stringToInt.find(str) != stringToInt.end()) {//如果str已经出现过
		return stringToInt[str];
	}
	else {
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}

void DFS(int u, int& head, int& numMember, int& sum) {
	numMember++;
	vis[u] = true;

	if (weight[u] > weight[head]) {
		head = u;
	}
	//添加操作
	

	for (int i = 0; i < numPerson; i++) {		
		if (G[u][i]>0) {
			sum += G[u][i];
			G[u][i] = G[i][u] = 0;
			if (vis[i] == false) {
				DFS(i, head, numMember, sum);
			}
			
		}
	}
	
}

void DFSTrave() {
	for (int u = 0; u < numPerson; u++) {
		if (vis[u] == false) {
			int head = u, numMember = 0, sum = 0;
			DFS(u,head,numMember,sum);
			if (numMember > 2 && sum > k) {
				Gang[intToString[head]] = numMember;
			}
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		
		cin >> Name1 >> Name2 >> Time;
		int id1 = change(Name1);//id 与 name 绑定
		int id2 = change(Name2);
		weight[id1] += Time;
		weight[id2] += Time;
		G[id1][id2] += Time;
		G[id2][id1] += Time;
	}
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}