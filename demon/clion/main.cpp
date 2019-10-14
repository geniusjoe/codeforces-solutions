#include<bits/stdc++.h>

//#pragma GCC optimize(2)

using namespace std;

const long long MAXN = 350;
const long long PHI = (long long) 998244352;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = (long long) 998244353;
const long long OVER_FLOW = 0x7fffffff;
const long long LOVER_FLOW = 0x7fffffffffffffff;

long long n;
struct op {
    long long x1, y1, x2, y2;
};
long long vis[MAXN][MAXN];
vector<op> res;
string str;


void add(long long x1, long long y1, long long x2, long long y2) {
    res.push_back((op) {x1, y1, x2, y2});
    vis[x2][y2]++;
}

void move(long long x1, long long y1, bool x) {
    if (x) {
        if (x1 != 1) {
            add(x1, y1, 1, y1);
        } else {
            add(x1, y1, 1, y1 == 1 ? 2 : 1);
        }
    } else {
        if (x1 != 2) {
            add(x1, y1, 2, y1);
        } else {
            add(x1, y1, 2, y1 == 1 ? 2 : 1);
        }
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("testdata.in", "r+", stdin);
    freopen("testdata.out", "w+", stdout);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif

/*
写代码时请注意：
    1.数学公式尝试化简
    2.dp或者数值太大,尝试给出递推公式
    3.概率题随机生成考虑1/2的情况,或者是满足的方案/所有可能的方案
    5.排序之前不能取模.
    6.0-1子矩阵子序列:前缀和,异或和
    7.模拟题注意代码复用.
    8.单个区间问题考虑前缀和,多个区间左右端点拆开,排序,记录端点极值
思考提醒：
    1.最大值和最小值问题可不可以用二分+贪心？
    2.dp
    3.如果规模小的话还能尝试dfs
    4.如果存在等式.转换关系少可以暴力枚举变量,或者考虑从数据大小入手
    5.离散化+打表
*/

    ios::sync_with_stdio(false);
    long long m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            cin >> str;
            for (long long k = str.size() - 1; k >= 0; k--) {
                move(i, j, str[k] == '1');
            }
        }
    }
    for (long long i = 1; i <= 2; i++) {
        for (long long j = 2; j <= m; j++) {
            while (vis[i][j]) {
                add(i, j, i, 1);
                vis[i][j]--;
            }
        }
    }

    long long cnt = res.size();
    memset(vis, 0, sizeof vis);

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            cin >> str;
            for (auto k:str) {
                move(i, j, k == '1');
            }
        }
    }
    for (long long i = 1; i <= 2; i++) {
        for (long long j = 2; j <= m; j++) {
            while (vis[i][j]) {
                add(i, j, i, 1);
                vis[i][j]--;
            }
        }
    }

    cout << res.size() << '\n';
    for (long long i = 0; i < cnt; i++) {
        cout << res[i].x1 << " " << res[i].y1 << " " << res[i].x2 << " " << res[i].y2 << '\n';
    }
    for (long long i = res.size() - 1; i >= cnt; i--) {
        cout << res[i].x2 << " " << res[i].y2 << " " << res[i].x1 << " " << res[i].y1 << '\n';
    }


#ifndef ONLINE_JUDGE
    auto end_time = clock();
    cerr << "Execution time: " << (end_time - start_time) * (int) 1e3 / CLOCKS_PER_SEC << " ms\n";
#endif

    return 0;

}