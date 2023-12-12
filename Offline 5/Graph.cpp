#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Graph {
    int V;
    vector<int> adj[MAX];
    bool visited[MAX];
    public:
        Graph(int V){
            this->V=V;
        }
        Graph(){
            this->V=0;
        }
        void addEdge(int v,int w){
            adj[v].push_back(w);
            V++;
        }
        void BFS(int s){
            for(int i=0;i<V;i++)
                visited[i]=false;

            vector<pair<int,int>> v;
            queue<int> q;
            visited[s]=true;
            q.push(s);
            while(!q.empty()) {
                s=q.front();
                //cout<<s<<" ";
                q.pop();
                for(auto i:adj[s]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        v.push_back({s,i});
                        q.push(i);
                    }
                }
            }
            for(int i=0;i<V;i++)
                visited[i]=false;
            cout<<"BFS: ";
            for(auto x:v){
                cout<<"("<<x.first<<" "<<x.second<<") ";
            }
            cout<<endl;
        }
        void DFShelp(int s,vector<pair<int,int>>& v){
            visited[s]=true;
            //cout<<s<<" ";
            for(auto x:adj[s]){
                if(!visited[x]){
                    v.push_back({s,x});
                    DFShelp(x,v);
                }
            }
        }
        void DFS(int s){
            vector<pair<int,int>> v;
            cout<<"DFS: ";
            DFShelp(s,v);
            for(auto x:v){
                cout<<"("<<x.first<<" "<<x.second<<") ";
            }
            cout<<endl;
        }
};

