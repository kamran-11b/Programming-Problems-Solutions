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
ll BigMod(ll B,ll P,ll M)
{
    ll R=1%M;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

struct data
{
    ll nxt, sum, combi;
};

data dp[MX];
ll arr[MX];
int n;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {

        scanf("%d", &n);
        //printf("___%d %d\n", ti, n);
        ll total = 0;
        for(int i = 1; i <= n; i++)
        {
            //puts("ok");
            scanf("%lld", &arr[i]);
            total += arr[i];
        }
        ll ans = (BigMod(2,n-1,mod)*total)%mod;
        ll presum = arr[1];
        ll precom = 1;
        ll premul = arr[1];
        for(int i = 2; i <= n; i++)
        {

            int nxt = max(n-i-1,0);
            ll nxtcom = BigMod(2,nxt,mod);
            printf("presum %lld precom %lld premul%lld nxtcom%lld ans%lld\n", presum, precom, premul, nxtcom, ans);
            ll totcom = (precom*nxtcom)%mod;
            ans -= (totcom*arr[i])%mod;
            ans = (ans+mod)%mod;
            ans -= (nxtcom*presum)%mod;
            ans = (ans+mod)%mod;
            ans += (((premul*arr[i])%mod)*nxtcom)%mod;
            ans %= mod;
            ans -= presum;
            ans = (ans+mod)%mod;
            presum += (premul*arr[i])%mod+(BigMod(2,i-2,mod)*arr[i])%mod;
            precom += BigMod(2,i-2,mod);
            premul *= arr[i];
            premul %= mod;
            premul += (BigMod(2,i-2,mod)*arr[i])%mod;
            presum %= mod;
            precom %= mod;
            premul %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


