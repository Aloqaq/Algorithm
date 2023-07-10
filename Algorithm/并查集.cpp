#include<bits/stdc++.h>
using namespace std;

/*
# 【模板】并查集

## 题目描述
如题，现在有一个并查集，你需要完成合并和查询操作。
## 输入格式
第一行包含两个整数 N,M ,表示共有 N 个元素和 M 个操作。
接下来 M 行，每行包含三个整数 Z_i,X_i,Y_i。
当 Z_i=1 时，将 X_i 与 Y_i 所在的集合合并。
当 Z_i=2 时，输出 X_i与 Y_i 是否在同一集合内，是的输出`Y` ；否则输出 `N` 。
## 输出格式
对于每一个 Z_i=2 的操作，都有一行输出，每行包含一个大写字母，为 `Y` 或者 `N` 。

## 样例 #1
### 样例输入 #1
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
### 样例输出 #1
```
N
Y
N
Y
```
说明：对于100%的数据，1<=N<=10^4,1<=M<=2*10^5
*/
const int maxN = 10010;
const int maxM = 200010;
int N, M;
int Z[maxM], X[maxM], Y[maxM];
int father[maxN];

////查找操作
//int findFather(int v) {
//	if (v == father[v])	return v;//找到根结点
//	else {
//		int F = findFather(father[v]);//递归往上查找根结点
//		father[v] = F;//将根结点赋值给father[v]
//		return F;
//	}
//}

//路径压缩
int findFather(int x) {
	//由于x会在下面变成根结点，先把x保存一下
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}

	//到这里，x存放的是根节点。下面把路径上所有结点的father都改成根结点
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[a] = x;
	}
	return x;
}

//合并操作
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);

	if (faA == faB)	return;
	else father[faA] = faB;
}


int main()
{
	cin >> N >> M;

	//初始化并查集-每个元素单独成集合
	for (int i = 1; i <= N; i++) {
		father[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> Z[i] >> X[i] >> Y[i];//输入M个操作
		if (Z[i] == 1) {//Z=1，合并
			Union(X[i], Y[i]);
		}
		else {//Z=2，判断
			if (findFather(X[i]) == findFather(Y[i]))	cout << "Y" << endl;
			else
			{
				cout << "N" << endl;
			}
		}
	}
	return 0;
}