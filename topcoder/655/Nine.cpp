#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<cstring>

using namespace std;
typedef long long ll;

const ll mod = 1000000007;

int po[10];

int get(int mask, int pos) {
    return (mask/po[pos])%9;
}

int setv(int mask, int pos, int v) {
    return mask+(v-get(mask,pos))*po[pos];
}

int getbit(int mask, int pos) {
    return (mask>>pos)&1;
}

int cnt[1<<6];

ll dp[1<<6][59049];
ll dp2[10][5050];

ll func2(int m, int k) {
    if(k == 0) {
        if(m == 0) return 1;
        return 0;
    }
    ll & res = dp2[m][k];
    if(res != -1) return res;
    res = 0;
    for(int i = 0; i < 10; i++) {
        res += func2((((m-i)%9)+9)%9, k-1);
    }
    res %= mod;
    //printf("%d %d %lld\n", m, k, res);
    return res;
}

ll func(int pos, int mask, int n) {
    //printf("%d %d %d\n", pos, mask, cnt[pos]);
    if(pos == (1<<n)) {
        if(mask == 0) return 1;
        return 0;
    }
    ll & res = dp[pos][mask];
    if(res != -1) return res;
    res = 0;

    for(int i = 0; i < 9; i++) {
        int now = mask;
        for(int j = 0; j < n; j++) {
            int mo = getbit(pos,j)*i+get(mask,j);
            now = setv(now,j,mo%9);
        }
        res += (func(pos+1,now,n)*func2(i,cnt[pos]))%mod;
    }
    res %= mod;
    return res;
}

class Nine {
public:
    int count(int N, vector <int> d) {
        po[0] = 1;
        for(int i = 1; i <= N; i++)
            po[i] = po[i-1]*9;
        memset(dp,-1,sizeof dp);
        memset(dp2,-1,sizeof dp2);
        memset(cnt,0,sizeof cnt);
        for(int i = 0; i < d.size(); i++) {
            cnt[d[i]]++;
        }
        return func(0,0,N);
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}";
    cout << "]" << endl;
    Nine *obj;
    int answer;
    obj = new Nine();
    clock_t startTime = clock();
    answer = obj->count(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p2;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    int p0;
    vector <int> p1;
    int p2;

    {
        // ----- test 0 -----
        p0 = 2;
        int t1[] = {1,2};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 4;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 2;
        int t1[] = {1,2,3};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 16;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }
    //return 0;
    {
        // ----- test 2 -----
        p0 = 1;
        int t1[] = {0,0,1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 200;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 5;
        int t1[] = {1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 450877328;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 5;
        int t1[] = {31,31,31,31,31};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 11112;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
