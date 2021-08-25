#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define po pop_back
#define mp make_pair
#define fi first
#define se second
#define ull unsigned long long int
#define ll long long 
#define lli long long int

//typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int>   vi;
typedef vector<ll>    vl;
//typedef vector<pii>   vpii;
typedef vector<pll>   vpll;
typedef pair<int,string>pi;

const int MOD = 1000000007;


ull nCr(ull n, ull r)
{
    if(n<r)return 0;
    if(n-r<r)
        r=n-r;
    vector<ull>arr(r+1,0);
    arr[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=r;j>=1;j--)
            arr[j]=(arr[j]+arr[j-1]);         //since backword going so new need of extra vector temp for last row dp
        
    return arr[r];
    
}


    
    
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int R=3,C=3;
     vector<string>mat;
     mat.pb("RRD");
     mat.pb("DDU");
     mat.pb("LLL");
    
     vector<vector<int>>dist(R,vector<int>(C,INT_MAX));
    vector<vector<bool>>visited(R,vector<bool>(C,false));
    dist[0][0]=0;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    int ch[4]={'D','U','R','L'};
    
    priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>>> , greater< pair<int,pair<int,int>>> >pq;
    pq.push({0,{0,0}});
    while(!pq.empty())
    {
        int ui=pq.top().second.first;
        int uj=pq.top().second.second;
        int wt=pq.top().first;
        pq.pop();
        if(!visited[ui][uj])
        {
            visited[ui][uj]=true;
            for(int k=0;k<4;k++)
            {
                int vi=ui+dr[k];
                int vj=uj+dc[k];
                if(vi<0 || vj<0 || vi>=R || vj>=C)continue;
                int add=mat[vi][vj]==ch[k]?0:1;
                if(dist[vi][vj]>(dist[ui][uj]+add) )
                {
                    dist[vi][vj]=dist[ui][uj]+add;
                    pq.push({dist[vi][vj],{vi,vj}});
                }
            }
        }
    }
    for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<"\n";
        }
    cout<< dist[R-1][C-1];
        
}

