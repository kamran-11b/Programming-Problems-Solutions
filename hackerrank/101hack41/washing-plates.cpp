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

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 300005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    ll total = 0;
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        arr[i] = a+b;
        total -= b;
    }
    sort(arr,arr+n);
    for(int i = max(n-k,0); i < n; i++)
        total += arr[i];
    printf("%lld\n", max(total,0ll));
    return 0;
}


