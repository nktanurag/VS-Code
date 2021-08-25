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

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>A(n+1);
    vector<int>B(n+1);
    vector<int>C(n+1);
    A[0]=-1;B[0]=-1;C[0]=-1;
    f(i,1,n+1)
        cin>>A[i];
    f(i,1,n+1)
        cin>>B[i];
    f(i,1,n+1)
        cin>>C[i];

    sort(A.begin(),A.end());
    
    ll count=0;
    for(int j=1;j<n+1;j++)
    {
        if(binary_search(A.begin(),A.end(),B[C[j]]))
        {
            auto it1=lower_bound(A.begin(),A.end(),B[C[j]]);
            auto it2=upper_bound(A.begin(),A.end(),B[C[j]]);
            if(it1==A.end())break;
            count+=int(it2-it1);

        }    
    }
    cout<<count<<"\n";
}



