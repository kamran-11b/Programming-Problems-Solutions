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

typedef pair<int,int> pii;

int sum[100];
int res[100];
int flag[100];
vector<pii> vc;
vector<int> arr;

bool func(int n, int tk, int k)
{
//    for(int i = 0; i < n; i++)
//        printf("%d %d\n", vc[i].first, vc[i].second);
    int now = 0;
    for(int i = 0; i < tk; i++)
    {
        now += arr[res[i]];
        if(now>sum[i+1]) k--;
    }
    //printf("k===%d\n", k);
    int l = k;
    int presum = now;
    int pos = n-1;
    for(int i = tk; i < n; i++)
    {
        while(pos>=0 && flag[vc[pos].second] == 1) pos--;
        now += vc[pos].first;
        if(sum[i+1]<now) k--;
        pos--;
    }
    pos = 0;
    now = presum;
    for(int i = tk; i < n; i++)
    {
        while(pos<n && flag[vc[pos].second] == 1) pos++;
        now += vc[pos].first;
        //printf("%d %d %d %d %d %d\n", i, sum[i+1], now, pos, vc[pos].first, l);
        if(sum[i+1]<now) l--;
        pos++;
    }
    //printf("%d %d\n", k, l);
    if(k <= 0 && l>=0) return 1;
    return 0;
}

class CanidsSeesaw {
public:
	vector <int> construct(vector <int> wolf, vector <int> fox, int k) {
	    memset(sum,0,sizeof sum);
	    memset(res,0,sizeof res);
	    memset(flag,0,sizeof flag);
		int n = wolf.size();
		arr = fox;
		vc.clear();
        for(int i = 1; i <= n; i++)
        {
            sum[i] = wolf[i-1]+sum[i-1];
        }
        for(int i = 0; i < n; i++)
        {
            vc.push_back(make_pair(fox[i],i));
        }
        sort(vc.begin(), vc.end());
        vector<int>  ans;
        if(!func(n,0,k)) return ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(flag[vc[j].second] == 1) continue;
                res[i] = vc[j].second;
                flag[vc[j].second] = 1;
                if(func(n,i+1,k)) break;
                flag[vc[j].second] = 0;
            }
        }
        int pre = 0;
        for(int i = 0; i < n; i++)
        {
            pre += arr[res[i]];
            if(pre>sum[i+1]) k--;
        }
        if(k!= 0) return ans;
        for(int i = 0; i < n; i++)
            ans.push_back(res[i]);
        return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, vector <int> p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	CanidsSeesaw *obj;
	vector <int> answer;
	obj = new CanidsSeesaw();
	clock_t startTime = clock();
	answer = obj->construct(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p3[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p3[i]) {
					res = false;
				}
			}
		}
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

	vector <int> p0;
	vector <int> p1;
	int p2;
	vector <int> p3;

	{
	// ----- test 0 -----
	int t0[] = {3,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	int t3[] = {1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {1,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
    //return 0;
	{
	// ----- test 2 -----
	int t0[] = {10,10,10,10,10,10,10,10,10,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,100,1,100,1,100,1,100,1,100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 7;
	int t3[] = {0,2,4,1,6,3,5,7,9,8};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {10,10,10,10,10,10,10,10,10,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,100,1,100,1,100,1,100,1,100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	int t0[] = {2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	int t3[] = {0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
