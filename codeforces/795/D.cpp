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

int arr[MX];
int arr2[MX];
int cnt[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        if(i>=l && r >= i)
            cnt[arr[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr2[i]);
        if(i>=l && r >= i)
            cnt[arr2[i]]--;
        else{
            if(arr[i] != arr2[i]) cnt[i] = -100;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] != 0)
        {
            puts("LIE");
            return 0;
        }
    }
    puts("TRUTH");
    return 0;
}

