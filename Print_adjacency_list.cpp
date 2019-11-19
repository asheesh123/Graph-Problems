#include<bits/stdc++.h>
using namespace std;
class Graph{
    int E,V;
    list<int> *adjList;
    public:
        Graph(int v,int e){
            E=e;
            V=v;
            adjList=new list<int>[V];
        }
        void addEdge(int u,int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        void showList(){
            for(int i=0;i<V;i++){
                list<int>::iterator j;
                cout<<i;
                for(j=adjList[i].begin();j!=adjList[i].end();j++){
                    cout<<"-> "<<(*j);
                }
                cout<<endl;
            }
        }
        
};
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    Graph g(v,e);
	    int x,y;
	    for(int i=0;i<e;i++){
	        cin>>x>>y;
	        g.addEdge(x,y);
	    }
	    g.showList();
	}
	return 0;
}
