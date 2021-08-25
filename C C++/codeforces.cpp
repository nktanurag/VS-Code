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

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pll>   vpll;
typedef pair<int,string>pi;

const int MOD = 1000000007;



int n=10;
int leftA[10]={5,4,4,3,3,2,2,1,1,0};
int leftB[10]={5,5,4,4,3,3,2,2,1,1};
int solve(int i,int s1,int s2,string &str,vector<vector<vector<int>>>&dp)
{
    int mn=n-1;
    if(i==n)return n;
    if(leftA[i]<s2-s1)return i-1;
    if(leftB[i]<s1-s2)return i-1;
    if(dp[i][s1][s2]!=-1)return dp[i][s1][s2];
  
    if(str[i]=='1' && i%2==0)
       mn=solve(i+1,s1+1,s2,str,dp);
    else if(str[i]=='1' && i%2!=0)
       mn=solve(i+1,s1,s2+1,str,dp);
    else if(str[i]=='0' && i%2==0)
       mn=solve(i+1,s1,s2,str,dp);
    else if(str[i]=='0' && i%2!=0)
       mn=solve(i+1,s1,s2,str,dp);  
    else{
        mn=min(min(solve(i+1,s1,s2+1,str,dp),solve(i+1,s1+1,s2,str,dp)),solve(i+1,s1,s2,str,dp));
    }
    return dp[i][s1][s2]=mn;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        vector<vector<vector<int>>>dp(15,vvi(12,vi(12,-1)));
        cout<<solve(0,0,0,str,dp)+1<<"\n";
        
    }
    
}