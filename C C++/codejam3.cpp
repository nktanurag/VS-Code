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
void reverseList(int i,int j,vector<int>&arr)
{
    int p=(j-i+1)/2;
    for(int k=1;k<=p;k++)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;j--;
    }
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    f(z,1,t+1)
    {
        int n,c;
        cin>>n>>c;
        if(c<n-1 || c>(n*(n+1)/2 -1))
        {
            cout<<"Case #"<<z<<": "<<"IMPOSSIBLE\n";
        }
        else
        {
          vector<int>expense(n,1);
          vector<int>arr;
          f(i,0,n)
             arr.pb(i+1);
          int score=c;
          score-=n-1;
          for(int i=0;i<n;i++)
          {
              if(score>(n-i-1))
              {
                  expense[i]+=n-i-1;
                  score-=n-i-1;
              }
                
              else
              {
                  expense[i]+=score;
                  break;
              }
          }
          
          
          for(int i=n-2;i>=0;i--)
          {
              reverseList(i,i+expense[i]-1,arr);
          }
          cout<<"Case #"<<z<<": ";
          f(i,0,n)
             cout<<arr[i]<<" ";
           cout<<"\n";
           
        }
    }


}



