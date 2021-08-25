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
typedef pair<ll,ll> pllll;
typedef vector<int>   vi;
typedef vector<vector<int>>   vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>>   vvll;
typedef vector<vector<char>>   vvc;
const int mod = 1000000007;


// ull nCr(ull n, ull r)
// {
//     if(n<r)return 0;
//     if(n-r<r)
//         r=n-r;
//     vector<ull>arr(r+1,0);
//     arr[0]=1;
//     for(int i=1;i<=n;i++)
//         for(int j=r;j>=1;j--)
//             arr[j]=(arr[j]+arr[j-1]);         //since backword going so new need of extra vector temp for last row dp
        
//     return arr[r];
    
// }

// int Pows(int x,int y)
// {                               
                               //x=x%mod
//     if(x==0)return 0;          
//     int res=1;
//     while(y>0)
//     {
//         if(y&1)
//          res*=x;        //%mod
//         y=y>>1;
//         x*=x;          //%mod
//     }
//     return res;
// }
// 

string s;
int n;
int solve(int i,int last,int mask)
{
    if(i==n)return 1;
    int curr=s[i]-'A'+1;

    int tp=0;
    if(curr==last)
        tp+=solve(i+1,curr,mask | (1<<curr));
    tp%=998244353;
    if((mask & (1<<curr))==0)
    {
        tp+=solve(i+1,curr,mask|(1<<curr));
    }
    tp%=998244353;
    return tp;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    cin>>s;
    cout<<solve(0,0,0);
}


