#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define po pop_back
#define mp make_pair
#define ull unsigned long long int
#define ll long long 
#define lli long long int
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pll>   vpll;

const int mod = 1000000009;

bool checkPrime(int n)
{
    if(n<=1)return false;
    if(n<=3)return true;
    if(n%2==0 || n%3==0)return false;
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0)return false;
        
    }
    return true;
}
int maxDivisor(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return n/i;
    }
    return 1;
}
int main()
{

    int n;
    cin>>n;
    int dp[n+1];
    dp[0]=0;dp[1]=0;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {

        if(checkPrime(i)==true)
            dp[i]=i;
        else
            dp[i]=dp[maxDivisor(i)]+i/maxDivisor(i);
    }


    f(i,0,n+1)
        cout<<i<<" "<<dp[i]<<"\n";

            
}

