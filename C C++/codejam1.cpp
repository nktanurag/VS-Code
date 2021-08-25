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

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    f(z,1,t+1)
    {
        int x,y;
        cin>>x>>y;
        string str;
        cin>>str;

        int cnt=0;
     
        for(int i=0;i<str.size();)
        {
           if(str[i]=='?')
           {
               int j=i+1;
               while(j<str.size())
               {
                   if(str[j]=='?')
                     j++;
                   else
                     break;
               }
               if(i==0 || i==str.size()-1 || j>=str.size())
                 cnt=cnt;
               else if(j-i>=1)
               {
                   if(str[i-1]=='C' && str[j]=='J')
                     cnt+=x;
                   else if(str[i-1]=='J' && str[j]=='C')
                     cnt+=y;
               }
               i=j;
           }
           else i++;
        }
        f(i,0,str.size()-1)
        {
            if(str[i]=='C' && str[i+1]=='J')
              cnt+=x;
            else if(str[i]=='J' && str[i+1]=='C')
              cnt+=y;

        }
        
        cout<<"Case #"<<z<<": "<<cnt<<"\n";
    }

}



