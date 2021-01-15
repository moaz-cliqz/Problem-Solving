#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;
vector<int> g[505], vg[505];
int d[505], used[505];
int dfs(int v) {
	if(used[v])    return 0;
	used[v] = 1;
	int sum = d[v];
	for(int i = 0; i < g[v].size(); i++)
		sum += dfs(g[v][i]);
	return sum;
}
int dfs2(int v) {
	if(used[v])    return 0;
	used[v] = 1;
	int sum = d[v];
	for(int i = 0; i < vg[v].size(); i++)
		sum += dfs2(vg[v][i]);
	return sum;
}
int main() {
	int cases = 0;
	int n, m, q;
	int i, j, k, x, y;
	while(scanf("%d %d", &n, &m) == 2 && n) {
		int totW = 0;
		for(i = 1; i <= n; i++) {
			scanf("%d", &d[i]);
			totW += d[i];
		}
		for(i = 1; i <= n; i++)
			g[i].clear(), vg[i].clear();
		for(i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			g[x].push_back(y);
			vg[y].push_back(x);
		}
		scanf("%d", &q);
		printf("Case #%d:\n", ++cases);
		while(q--) {
			scanf("%d", &x);
			memset(used, 0, sizeof(used));
			int minD = dfs(x);
			memset(used, 0, sizeof(used));
			int maxD = totW - dfs2(x) + d[x];
			printf("%d\n", maxD - minD);
		}
		puts("");
	}
	return 0;
}
