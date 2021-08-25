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


int n;
vector<int>seg;
void buildSeg(int ind,int low,int high,vector<int>&nums)
{
    if(low==high)
    {
        seg[ind]=nums[low];
        return;
    }
    int mid=(low+high)/2;
    buildSeg(2*ind+1,low,mid,nums);
    buildSeg(2*ind+2,mid+1,high,nums);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int query(int ind,int low,int high,int l,int r)  // low,high cond given 
{
    int mid=(low+high)/2;
    //lie completely in range
    if(low>=l && high<=r)
        return seg[ind];
    //null intersection
    if(high<l || low>r)return 0;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return left+right;
}
void PointUpdate(int ind,int low,int high,int node,int val)
{
    if(low==high)
        seg[ind]=val;
    else{
        int mid=(low+high)/2;
        if(node>=low && node<=mid)
            PointUpdate(2*ind+1,low,mid,node,val);
        else
            PointUpdate(2*ind+2,mid+1,high,node,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
}
void NumArray(vector<int>& nums)
{
    n=nums.size();
    seg=vector<int>(n*4,0);
    buildSeg(0,0,n-1,nums);
} 

void update(int idx, int val) {
    PointUpdate(0,0,n-1,idx,val);
}

int sumRange(int left, int right) {
    return query(0,0,n-1,left,right);
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
}

    
   
    
};

/*-------------LAZY PROIPAGATION---------------*/
vector<ll>nums;
vector<ll>seg;
vector<ll>lazy;
void buildSeg(int ind,int low,int high)
{
    if(low==high)
    {
        seg[ind]=nums[low];
        return;
    }
    int mid=(low+high)/2;
    buildSeg(2*ind+1,low,mid);
    buildSeg(2*ind+2,mid+1,high);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
ll lazyQuery(int ind,int low,int high,int l,int r)  // low,high cond given 
{

    if(lazy[ind]!=0)
    {
        ll dx=lazy[ind];
        lazy[ind]=0;
        seg[ind]+=dx*(high-low+1);
        if(low!=high)
        {
            lazy[2*ind+1]+=dx;
            lazy[2*ind+2]+=dx;
        }
    }
    
    //lie completely in range
    if(low>=l && high<=r)
        return seg[ind];
    //null intersection
    if(high<l || low>r)return 0;
    //lie partialyy
    int mid=(low+high)/2;
    ll left=lazyQuery(2*ind+1,low,mid,l,r);
    ll right=lazyQuery(2*ind+2,mid+1,high,l,r);
    return left+right;
}
void lazyRangeUpdate(int ind,int low,int high,int l,int r,ll value)
{
    if(lazy[ind]!=0)
    {
        ll dx=lazy[ind];
        lazy[ind]=0;
        seg[ind]+=dx*(high-low+1);
        if(low!=high)
        {
            lazy[2*ind+1]+=dx;
            lazy[2*ind+2]+=dx;
        }
    }
    //null intersection
    if(high<l || low>r)return;

    //lie completely in range
    if(low>=l && high<=r)
    {
        ll dx=(high-low+1)*value;
        seg[ind]+=dx;
        if(low!=high)
        {
            lazy[2*ind+1]+=value;
            lazy[2*ind+2]+=value;
        }
        return;
    }   
    
    int mid=(low+high)/2;
    lazyRangeUpdate(2*ind+1,low,mid,l,r,value);
    lazyRangeUpdate(2*ind+2,mid+1,high,l,r,value);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    return; 
}

void NumArray(vector<int>& nums)
{
    n=nums.size();
    seg=vector<ll>(n*4,0);
    lazy=vector<ll>(n*4,0);
    buildSeg(0,0,n-1);
} 










//-------------binary indexed/fenwick tree---------------////////////
int N;
vector<int>fen(N);
void update(int i,int add)
{
    while(i<N)
    {
        fen[i]+=add;
        i+=(i & (!i));
    }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=fen[i];
        i=i-(i&(!i));
    }
    return s;
}
//////////////////////////////////////////////////////
