#include<bits/stdc++.h>
using namespace std;

/*
# ��ģ�塿���鼯

## ��Ŀ����
���⣬������һ�����鼯������Ҫ��ɺϲ��Ͳ�ѯ������
## �����ʽ
��һ�а����������� N,M ,��ʾ���� N ��Ԫ�غ� M ��������
������ M �У�ÿ�а����������� Z_i,X_i,Y_i��
�� Z_i=1 ʱ���� X_i �� Y_i ���ڵļ��Ϻϲ���
�� Z_i=2 ʱ����� X_i�� Y_i �Ƿ���ͬһ�����ڣ��ǵ����`Y` ��������� `N` ��
## �����ʽ
����ÿһ�� Z_i=2 �Ĳ���������һ�������ÿ�а���һ����д��ĸ��Ϊ `Y` ���� `N` ��

## ���� #1
### �������� #1
```
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4
```
### ������� #1
```
N
Y
N
Y
```
˵��������100%�����ݣ�1<=N<=10^4,1<=M<=2*10^5
*/
const int maxN = 10010;
const int maxM = 200010;
int N, M;
int Z[maxM], X[maxM], Y[maxM];
int father[maxN];

////���Ҳ���
//int findFather(int v) {
//	if (v == father[v])	return v;//�ҵ������
//	else {
//		int F = findFather(father[v]);//�ݹ����ϲ��Ҹ����
//		father[v] = F;//������㸳ֵ��father[v]
//		return F;
//	}
//}

//·��ѹ��
int findFather(int x) {
	//����x���������ɸ���㣬�Ȱ�x����һ��
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}

	//�����x��ŵ��Ǹ��ڵ㡣�����·�������н���father���ĳɸ����
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[a] = x;
	}
	return x;
}

//�ϲ�����
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);

	if (faA == faB)	return;
	else father[faA] = faB;
}


int main()
{
	cin >> N >> M;

	//��ʼ�����鼯-ÿ��Ԫ�ص����ɼ���
	for (int i = 1; i <= N; i++) {
		father[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> Z[i] >> X[i] >> Y[i];//����M������
		if (Z[i] == 1) {//Z=1���ϲ�
			Union(X[i], Y[i]);
		}
		else {//Z=2���ж�
			if (findFather(X[i]) == findFather(Y[i]))	cout << "Y" << endl;
			else
			{
				cout << "N" << endl;
			}
		}
	}
	return 0;
}