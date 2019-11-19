#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    vector<int> distances(V,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    bool visited[V]={false};
    pq.push({0,src});
    distances[src]=0;
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        int u=p.second;
        if(visited[u])
            continue;
        visited[u]=true;
        for(int i=0;i<V;i++){
            if(graph[u][i]){
                int weight=graph[u][i];
                if(distances[i]>weight+distances[u]){
                    distances[i]=weight+distances[u];
                    pq.push({distances[i],i});
                }
            }
        }
    }
    for(int i=0;i<V;i++) 
        cout<<distances[i]<<" ";
}
