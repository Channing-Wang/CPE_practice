#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>

using namespace std;

void find_path(vector<int> pre, vector<int> &path, int startp, int endp)
{
    int i = endp;
    path.push_back(endp);
    while(pre[i] != -1)
    {
        i = pre[i];
        path.push_back(i);
    }
}

void bfs(vector<vector<int> > n, vector<vector<int> > w, int startp, int endp, int nodes, vector<int> &path)
{
    vector<int> pre(nodes, -1);
    vector<int> dist(nodes, nodes);
    vector<int> dist2(nodes, nodes);
    vector<bool> visit(nodes, false);
    vector<bool> visit2(nodes, false);
    queue<int> Q;

    Q.push(startp);
    visit[startp] = true;
    dist[startp] = 0;
    while(!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        for(int j = 0 ; j < n[i].size() ; ++j)
        {
            if(w[i][j] <= dist[i]) continue;

            if(!visit[n[i][j]])
            {
                visit[n[i][j]] = true;
                dist[n[i][j]] = dist[i]+1;
                pre[n[i][j]] = i;
                Q.push(n[i][j]);
            }
        }
    }
    //¥¿±`ª©bfs
    Q.push(startp);
    visit2[startp] = true;
    dist2[startp] = 0;
    while(!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        for(int j = 0 ; j < n[i].size() ; ++j)
        {
            if(!visit2[n[i][j]])
            {
                visit2[n[i][j]] = true;
                dist2[n[i][j]] = dist2[i]+1;
                Q.push(n[i][j]);
            }
        }
    }
    if((dist[endp]==dist2[endp]) && (dist[endp]<nodes))
        find_path(pre, path, startp, endp);
    else
        path.push_back(-1);
}

int main()
{
    int times, nodes, edges, startp, endp;
    int from, to, weight;
    cin >> times;
    while(times--)
    {
        cin >> nodes >> edges >> startp >> endp;
        vector<vector<int> > n(nodes);
        vector<vector<int> > w(nodes);
        vector<int> path;
        while(edges--)
        {
            cin >> from >> to >> weight;
            n[from].push_back(to);
            w[from].push_back(weight);
        }
        bfs(n, w, startp, endp, nodes, path);
        for(int i = path.size()-1 ; i >= 0 ; --i)
            cout << path[i] << ' ';
        cout << endl;
    }
    return 0;
}
