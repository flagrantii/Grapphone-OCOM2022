#include<bits/stdc++.h>
using namespace std;
bool visited[0];
void addEgde(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int DFS(vector<int> adj[],int src){
	stack<int> st;
	int num=0;
	visited[src]=true;
	num++;
	
	st.push(src);
	while(!st.empty()){
		int tmp=st.top();
		st.pop();
		for(int i=0;i<adj[tmp].size();i++){
			if(visited[i]=false){
				visited[i]=true;
				num++;
				st.push(i);
			}
		}
	}
}

int main(){
	int V=0;
	int n;
	cin>>n;
	int u,v;
	vector<int> adj[V];
	for(int i=0;i<n;i++){
		cin>>u>>v;
		addEgde(adj,u,v);
	}
	bool visited[V+1];
	memset(visited,0,sizeof(visited));
	int cnt=0,ans=1;
	for(int i=0;i<8;i++){
		if(visited[i]==false){
			int num=DFS(adj,i);
			ans=ans*num;
		}
	}
	cout<<ans;
	return 0;
}
/*0 1
1 4
4 2
3 5
6 7*/
