#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> sz;

int find(int a) {
	if (parent[a] == -1) return a;
	return parent[a] = find(parent[a]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	sz[b] += sz[a];
	parent[a] = b;
}

void init(int N) {
	parent.assign(N, -1);
	sz.assign(N, 1);
}

int main() {
	// freopen("input.txt", "r", stdin);
	int N, Q, u, v;
	char ch;
	scanf("%d %d ", &N, &Q);
	init(N);
	for (int i = 0; i < Q; i++) {
		scanf("%c %d %d ", &ch, &u, &v);
		if (ch == '?') {
			printf((find(u) == find(v) ? "yes\n" : "no\n"));
		}
		else {
			join(u, v);
		}
	}
}
