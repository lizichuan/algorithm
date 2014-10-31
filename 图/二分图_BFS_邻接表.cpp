/*
二分图的判断, bfs的方法, 邻接表
将一个结点染为白色, 将和它相邻的结点染为黑色... 如果和它相邻的结点
已经染色且颜色一样,则该图不是二分图.
>>>>>>> origin/master
*/

#include <cstdio>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

const int MAXN = 10;
const int INIT = 0;
const int BLACK = -1;
const int WRITE = 1;//染的两种颜色互为相反数
int color[MAXN];
vector<vector<int>>g(MAXN);

/*
广度优先搜索bfs, 节点从1开始编号, 范围是[1 , N]
*/
bool is_bipartite(int N)// bipartite graph 二分图, 使用bfs
{
	for (int i = 1; i <= N; ++i)
	{
		color[i] = INIT;
	}
	for (int i = 1; i <= N; ++i)//图可能不是连通(强连通)的
	{
		queue<int> que;
		if (color[i] == INIT)
		{
			que.push(i);
			color[i] = WRITE;
		}
		while (!que.empty())
		{
			int p = que.front();
			for (int i = 0; i != g[p].size(); ++i)//搜索点p邻接表
			{
				int adj = g[p][i];//adj表示邻接表成员, 与p相连的点
				if (color[adj]== INIT)
				{
					color[adj] = -color[p];//如果没有染色, 将颜色染为与原来相反
					que.push(p);
				}
				else if (color[adj] == color[p])
				{
					return false;//如果已经染色,还和现在的颜色一样,返回不是二分图
				}
			}
			que.pop();
		}
	}
	return true;
}
