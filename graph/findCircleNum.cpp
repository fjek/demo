#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int cities, int i)
    {
        for (int j = 0; j < cities; j++)
        {
            if (isConnected[i][j] == 1 && !visited[j])
            {
                visited[j] = 1;
                dfs(isConnected, visited, cities, j);
            }
        }
    }

    // 查找连通分量数量 -- 深度优先
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int cities = isConnected.size();
        vector<int> visited(cities);
        int proviences;
        // dfs
        for (int i = 0; i < cities; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, cities, i);
                proviences++;
            }
        }
        return proviences;
    }

    // 查找连通分量数量 -- 深度优先
    int findCircleNumBFS(vector<vector<int>> &isConnected)
    {
        int cities = isConnected.size();
        vector<int> visited(cities);
        queue<int> q;
        int proviences;
        for (int i = 0; i < cities; i++)
        {   
            // 没有访问过就入队
            if (!visited[i])
            {
                q.push(i);
                while (!q.empty())
                // 队非空，访问队内元素
                {
                    int unVisitedCity = q.front();
                    q.pop();
                    visited[unVisitedCity] = 1;
                    for (int negibor = 0; negibor < cities; negibor++)
                    {
                        // 如果联通，且没有访问过，则添加到队列
                        if (isConnected[unVisitedCity][negibor] == 1 && !visited[negibor])
                        {
                            q.push(negibor);
                        }
                    }
                }
            }
        }

        return proviences;
    }
};