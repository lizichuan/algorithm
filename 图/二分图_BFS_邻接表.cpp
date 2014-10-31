/*
����ͼ���ж�, bfs�ķ���, �ڽӱ�
��һ�����ȾΪ��ɫ, ���������ڵĽ��ȾΪ��ɫ... ����������ڵĽ��
�Ѿ�Ⱦɫ����ɫһ��,���ͼ���Ƕ���ͼ.

*/

#include <stdio.h>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

const int MAXN = 10;
const int INIT = 0;
const int BLACK = -1;
const int WRITE = 1;//Ⱦ��������ɫ��Ϊ�෴��
int color[MAXN];
vector<vector<int>>g(MAXN);



/*
�����������bfs, �ڵ��1��ʼ���, ��Χ��[1 , N]
*/
bool is_bipartite(int N)// bipartite graph ����ͼ, ʹ��bfs
{
	for (int i = 1; i <= N; ++i)
	{
		color[i] = INIT;
	}
	for (int i = 1; i <= N; ++i)//ͼ���ܲ�����ͨ(ǿ��ͨ)��
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
			for (int i = 0; i != g[p].size(); ++i)//������p�ڽӱ�
			{
				int adj = g[p][i];//adj��ʾ�ڽӱ��Ա, ��p�����ĵ�
				if (color[adj]== INIT)
				{
					color[adj] = -color[p];//���û��Ⱦɫ, ����ɫȾΪ��ԭ���෴
					que.push(p);
				}
				else if (color[adj] == color[p])
				{
					return false;//����Ѿ�Ⱦɫ,�������ڵ���ɫһ��,���ز��Ƕ���ͼ
				}
			}
			que.pop();
		}
	}
	return true;
}
