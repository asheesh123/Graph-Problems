#include<bits/stdc++.h>
using namespace std;

int* topoSort(int V, vector<int> adj[]);

bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
    }
}

//code goes here
void topoSortUtil(set<int> &vs, stack<int> &st, int v, vector<int> adj[]){
    
    vs.insert(v);
    //cout<<vs.size()<<endl;
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        
        if(vs.find(*i)!=vs.end()){
            continue;
        }
        topoSortUtil(vs, st, *i, adj);
    }
    st.push(v);
}
int* topoSort(int V, vector<int> adj[])
{
    // Your code here
    set<int> vs;
    stack<int> st;
    for(int i=0;i<V;i++){
        if(vs.find(i)!=vs.end())
            continue;
        topoSortUtil(vs,st,i,adj);
    }
    int *arr=new int[V];
    int i=0;
    while(!st.empty()){
        arr[i++]=st.top();
        st.pop();
    }
    return arr;
}
