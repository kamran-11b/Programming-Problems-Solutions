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
#include <cstring>
using namespace std;

int col[100];
vector<int> adj[100][2];
bool ans = true;

void dfs(int u, int c)
{
    if(col[u] != -1)
    {
        if(col[u] != c)
        {
            ans = false;
            //printf("err %d\n", u);
        }
        return;
    }
    col[u] = c;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < adj[u][i].size(); j++)
        {
            //printf("->%d %d %d\n", u, adj[u][i][j], i);
            dfs(adj[u][i][j],c^i);
        }
    return;
}

class OddEvenTree
{
public:
    vector <int> getTree(vector <string> x)
    {
        int n = x.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(x[i][j] == '?') continue;
                int c = (x[i][j] == 'O');
                adj[i][c].push_back(j);
                adj[j][c].push_back(i);
            }
        memset(col,-1,sizeof col);
        for(int i = 0; i < n; i++)
        {
            if(col[i] == -1)
            {
                dfs(i,i!=0);
            }
        }
        vector<int> impos;
        impos.push_back(-1);
        if(!ans)
        {
            return impos;
        }
        int pos = -1;
        vector<int> res;
        for(int i = 1; i < n; i++)
        {
            if(col[i] == 1)
            {
                pos = i;
                res.push_back(0);
                res.push_back(i);
            }
        }
        for(int i = 1; i < n; i++)
        {
            if(col[i] == 0)
            {
                if(pos == -1) return impos;
                res.push_back(pos);
                res.push_back(i);
            }
        }
        return res;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <int> p1)
{
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    OddEvenTree *obj;
    vector <int> answer;
    obj = new OddEvenTree();
    clock_t startTime = clock();
    answer = obj->getTree(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << "{";
        for (int i = 0; int(p1.size()) > i; ++i)
        {
            if (i > 0)
            {
                cout << ",";
            }
            cout << p1[i];
        }
        cout << "}" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(answer.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << answer[i];
    }
    cout << "}" << endl;
    if (hasAnswer)
    {
        if (answer.size() != p1.size())
        {
            res = false;
        }
        else
        {
            for (int i = 0; int(answer.size()) > i; ++i)
            {
                if (answer[i] != p1[i])
                {
                    res = false;
                }
            }
        }
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    vector <string> p0;
    vector <int> p1;

    {
        // ----- test 0 -----
        string t0[] = {"EOE","OEO","EOE"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0,1,2,1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"EO","OE"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0,1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"OO","OE"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {-1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"EO","EE"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {-1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"EOEO","OEOE","EOEO","OEOE"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0,1,0,3,2,1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
