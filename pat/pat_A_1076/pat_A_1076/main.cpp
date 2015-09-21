#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 1010;
int N, L;
bool followed[maxn][maxn];  // followed[i][j], if i is followed by j
bool visit[maxn];

void solve()
{
	cin >> N >> L;
	for (int i = 1; i <= N; ++i)
	{
		int M; scanf("%d", &M);
		for (int j = 0; j < M; ++j)
		{
			int id; scanf("%d", &id);
			followed[id][i] = true;
		}
	}

	int K; cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int id; scanf("%d", &id);
		memset(visit, 0, sizeof(visit));
		queue<int> q; q.push(id); visit[id] = true;
		q.push(-1);  // separate different levels
		int level = 0;
		while (!q.empty())
		{
			if (level == L) break;
			int u_id = q.front(); q.pop();
			if (u_id == -1) { q.push(-1); ++level; continue; }
			for (int i = 1; i <= N; ++i) {
				if (!visit[i] && followed[u_id][i]) {
					q.push(i); visit[i] = true;
				}
			}
		}
		visit[id] = false; int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			if (visit[i]) ++cnt;
		}
		printf("%d\n", cnt);
	}
	return;
}

int main()
{
	solve();
	return 0;
}


/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
*/