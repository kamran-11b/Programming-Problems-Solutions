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
#include<complex>
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

#define MX 1000005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

queue<ll> qu;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, t, total = 0, x;
    scanf("%lld %lld", &n, &t);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        total += x;
        qu.push(x);
    }
    ll ans = 0;
    while(t>0 && (!qu.empty())) {
        if (t>=total) {
            ans += (t/total)*(qu.size());
            t %= total;
            continue;
        }
        if(qu.front()>t) {
            total -= qu.front();
            qu.pop();
            continue;
        }
        ans++;
        t -= qu.front();
        qu.push(qu.front());
        qu.pop();
    }
    printf("%lld\n", ans);
    return 0;
}

