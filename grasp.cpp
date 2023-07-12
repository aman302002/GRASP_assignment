#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool PMC(int matched_nodes,int n, vector<int>& visited, vector<int> adj[]){
    if(n%2!=0)return false; // odd no. of nodes can't form PMC
    if(matched_nodes==n) return true; // if all node visited return true

    int ind; // find any node which is not visited to pair it
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            ind = i; break;
        }
    }
    visited[ind] = 1; 
    for(auto x : adj[ind]){
        if(visited[x]==0){
            visited[x] = 1;
            bool tempPMC = PMC(matched_nodes+2,n,visited,adj);
            if(tempPMC)return true;
            visited[x] = 0;
        }
    }

    return false;

}


int32_t main(){
    int nodes;     cin>>nodes;  // 0,1,2,....,nodes -1
    int num_edges; cin>>num_edges;  // total number of edges

    vector<pair<int,int>> edges;
    for(int i=0;i<num_edges;i++){
        int a, b; 
        cin>>a>>b;
        edges.push_back({a,b});   // storing all the edges in vector "edges"
    }

    vector<int> adj[nodes];
    for(auto x : edges){
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }

    vector<int> visited(nodes,0);

    bool check_PMC = PMC(0,nodes,visited,adj);

    if(check_PMC)cout<<"Perfect Matching Cut exist for the given graph!"<<endl;
    else cout<<"Perfect Matching Cut does not exist for the given graph"<<endl;



}