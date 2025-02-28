//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

int tim[MX];
int arr[MX];
int arr2[MX];
int arr1[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &tim[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = n; i >= 1; i--)
        arr2[i] = max(arr2[i+1],arr[i]);
    for(int i = 1; i <= n; i++)
        arr1[i] = max(arr1[i-1],arr[i]);
    while(q--)
    {
        int ty, x, ans;
        scanf("%d %d", &ty, &x);
        if(ty == 1)
        {
            int pos = lower_bound(arr1,arr1+1+n,x)-arr1;
            if(arr1[pos]<x)
                ans = -1;
            else
                ans = tim[pos];
        }
        else
        {
            int pos = lower_bound(tim,tim+n+1,x)-tim;
            if(tim[pos]<x)
                ans = -1;
            else
                ans = arr2[pos];
        }
        printf("%d\n", ans);
    }
    return 0;
}


