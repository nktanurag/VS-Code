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
vector<vector<vector<int>>>dp;
int solve(int i,int last,int mask)
{
    if(i==n)return 1;
    int curr=s[i]-'A'+1;
    if(dp[i][last][mask]!=-1)return dp[i][last][mask];
    int tp=0;
    if(curr==last)
        tp+=solve(i+1,curr,mask | (1<<curr));
    tp%=998244353;
    if((mask & (1<<curr))==0)
    {
        tp+=solve(i+1,curr,mask|(1<<curr));
    }
    tp%=998244353;
    tp+=solve(i+1,last,mask);
    tp%=998244353;
    return dp[i][last][mask]=tp;
}

int solve(int u,int &res,vector<vector<int>>&adj,vector<int>&nums)
{
    if(u==-1)return 0;

    int l=solve(adj[u][0],res,adj,nums);
    int r=solve(adj[u][1],res,adj,nums);

    res=max(res,max(max(l+nums[u],r+nums[u]),max(l+r+nums[u],nums[u])));
    return max(max(l+nums[u],r+nums[u]),max(0,nums[u]));
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>parent;
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++)
    {
        adj[parent[i]].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()==2)continue;
        if(adj[i].size()<2)
            adj[i].push_back(-1);
        if(adj[i].size()<2)
            adj[i].push_back(-1);
    }
    int res=INT_MIN;
    solve(0,res,adj);
}


int solve(ListNode* haed)
{
    if(!head || !head->next)return head;
    ListNode* curr=head;
    set<int>s;
    s.insert(haed->val);
    while(curr->next)
    {
        if(s.find(curr->next->val)==s.end())
        {
            curr=curr->next;
            s.insert(curr->next->val);
        }
        else
        {
            curr->next=curr->next->next;
            curr=curr->next;
        }
        
    }
    return head;
}


string getLargestString(string s,int k)
{
    vector<int>countMap(26,0);
    string res;
    for(auto ch:s)
    {
        countMap[ch-'a']++;
    }

    for(int i=25;i>=0;i--)
    {
        int repeat=0;
        while(countMap[i]>0)
        {
            res.push_back(char(i+'a'));
            countMap[i]--;
            repeat++;

            if(repeat == k && countMap[i]>0)
            {
                char nextChar=nextCharacter(countMap,i);

                if(nextChar=='\0')
                    return res;
                
                res.push_back(nextChar);
                repeat=0;
            }
        }
    }
}