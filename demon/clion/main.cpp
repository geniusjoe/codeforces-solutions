#include<bits/stdc++.h>

#define loca
#define debu
using namespace std;

const int MAXN = 2050;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 998244353;
const long long OVER_FLOW = 0xffffffff;

vector<int> b;
vector<int> res;
bool vis[500000];

int main() {

#ifndef ONLINE_JUDGE
    freopen("testdata.in", "r+", stdin);
    freopen("testdata.out", "w+", stdout);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif

    ios::sync_with_stdio(false);
    long long n, m, k, x;
    cin >> n >> x;
    b.push_back(0);
    vis[x] = true;
    for (int i = 1; i < (1ll << n); i++) {
        if (!vis[i]) {
            b.push_back(i);
            vis[i ^ x] = true;
        } else
            continue;
    }
    cout << b.size() - 1 << endl;
    for (int i = 1; i < b.size(); i++) {
        cout << (long long) (b[i] ^ b[i - 1]) << " ";
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    auto end_time = clock();
    cerr << "Execution time: " << (end_time - start_time) * (int) 1e3 / CLOCKS_PER_SEC << " ms\n";
#endif

    return 0;

}

/*
写代码时请注意：
    1.是否要开Long Long？数组边界处理好了么？
    2.实数精度有没有处理？
    3.特殊情况处理好了么？
    4.做一些总比不做好。
思考提醒：
    1.最大值和最小值问题可不可以用二分答案？
    2.有没有贪心策略？否则能不能dp？
*/