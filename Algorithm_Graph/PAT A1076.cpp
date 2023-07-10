#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxv = 1010;
int n, L;
struct node {
	int id;
	int layer;
};
vector<node>Adj[maxv];
bool inq[maxv] = { false };

int BFS(int s,int  L) {//����u���ڵ���ͨ��
	int num = 0;
	queue <node>q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	
	inq[start.id] = true;//����u�Ѿ������
	while (!q.empty()) {
		node topNode = q.front();
		q.pop();
		int u = topNode.id;

		for (int i = 0; i < Adj[u].size() ; i++) {
			node next = Adj[u][i];
			next.layer = topNode.layer +1;
			
			if (inq[next.id] == false && next.layer <= L) {
				q.push(next);
				inq[next.id] = true;
				num++;
			}
		}
	}
	return num;
}



//�����������BFS-���У���NС��1000�������ڽӾ���
int main() {
	node user;
	int numFollow, idFollow;
	cin >> n >> L;
	for (int i = 1; i <= n; i++) {//������ϵ
		cin >> numFollow;

		user.id = i;
		for (int j = 0; j < numFollow; j++) {
			cin >> idFollow;					
			user.layer = 0;
			Adj[idFollow].push_back(user);
		}
	}

	int m, s;
	cin >> m;
	
	for (int j = 0; j < m; j++) {
		memset(inq, false, sizeof(inq));
		cin >> s;		
		int num=BFS(s,L);
		cout << num << endl;
	}

	return 0;
}