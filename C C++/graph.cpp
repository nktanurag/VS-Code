#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define po pop_back
#define fi first
#define se second
#define ull unsigned long long int
#define ll long long 
#define lli long long int
#define Sort(a) sort(a.begin(),a.end())



typedef pair<int,int>pii;
typedef pair<ll,ll> pll;
typedef vector<int>   vi;
typedef vector<vector<int>>   vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>>   vvll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
const int mod = 1000000007;




//Topological sort
// It is way of ordering vertices such that "if there is an edge directed towards vertex Vj 
// from vertex Vi, then Vi comes before Vj"
int V;
vector<int>stk;
vector<bool>visited(V,false);
vector<vector<int>>adj;        
void topoSort(int u)
{
    for(auto v:adj[u])
    {
        if(!visited[v])
        {
            visited[v]=true;
            topoSort(v);
        }
    }
    stk.push_back(u);
}
int main()
{
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            topoSort(i);
        }
    }
    // reverse(stk.begin(),stk.end());
}

//the reverse stk stack will contain the ordering of topological sort





//KOSARAJU ALGORITHM FOR STRONGLY CONNECTED COMPONENTS

//step 1
//sort all the nodes in order of topological sort
// and store it in stack
//step2
//transpose the graph(change the direction of eaach edge in the graph)
//step3
//now do dfs of each node from the top of the stack
//keep record of the visited nodes
//ignore if already visited


//step 1 toposort     
void dfs(int u,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&stk)
{
    for(auto v:adj[u])
    {
        if(!visited[v])
        {
            visited[v]=true;
            dfs(v,adj,visited,stk);
        }
    }
    stk.push_back(u);
}
int main()
{
    vector<int>stk;
    vector<bool>visited(V,false);
    vector<vector<int>>adj;   
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            dfs(i,adj,visited,stk);
        }
    }
    //step 2 transpose the graph
    //suppose adjT will be our transposed 
    vector<bool>visitedT(V,false);
    vector<vector<int>>adjT;   
    //step3
    //now do dfs of each node from the top of the stack
    //keep record of the visited nodes
    //ignore if already visited
    vector<vector<int>>res;
    while(stk.size())
    {
        int u=stk.back();
        //explore it with transposed edge
        if(!visitedT[u])
        {
            vector<int>ans;
            visitedT[u]=true;
            dfs(u,adjT,visitedT,ans);
            res.push_back(ans);   
        }
    }
    //res will contain all the strongly connected components
}



//-------------------Disjoint set union--------------//
vector<ll>sz;
vector<ll>id;
int initialize()
{
    //let n be no of vertices
    ll n;
    sz=vll(n,1);
    f(i,0,n)
        id.pb(i);
}
int sizeOfNode(int u)
{
    return sz[root(u)];
}
int root(ll x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void union1(ll x,ll y)
{
    ll p=root(x);
    ll q=root(y);
    if(p==q)return;
    if(sz[p]>sz[q])
    {
        id[q]=p;
        sz[p]+=sz[q];
    }
    else
    {
        id[p]=q;
        sz[q]+=sz[p];
    }
}
