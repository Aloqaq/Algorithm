#include<bits/stdc++.h>
using namespace std;
const int maxv = 2010;
map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;//head->����

int G[maxv][maxv] = { 0 }, weight[maxv] = { 0 };//�ڽӾ���G�͵�Ȩweight
int n, k;// n Ϊ��ϵ��������kΪ�Ż����ϵֵ�ܺ��ż�
string Name1, Name2;
int  Time;
int numPerson;//������
bool vis[maxv] = { false };
int INF = 1000000000;

int change(string str) {//��������֮������
	if (stringToInt.find(str) != stringToInt.end()) {//���str�Ѿ����ֹ�
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
	//��Ӳ���
	

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
		int id1 = change(Name1);//id �� name ��
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