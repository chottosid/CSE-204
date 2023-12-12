#include "Graph.cpp"
#include<fstream>
using namespace std;

int main() {
    Graph g;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;cin>>n>>m;
    int a,b;
    while (m--)
    {
        cin>>a>>b;
        g.addEdge(a,b);
    }
    int s;cin>>s;
    g.BFS(s);
    g.DFS(s);
    return 0;
}