#include<bits/stdc++.h>

//#pragma GCC optimize(2)

using namespace std;

const long long MAXN = 100500;
const long long PHI = (long long) 998244352;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = (long long) 1e9 + 7;
const long long OVER_FLOW = 0x7fffffff;
const long long LOVER_FLOW = 0x7fffffffffffffff;

int n;
long long pre_sm[MAXN], c[MAXN];
string str;

// a ^ b % c
long long qpow(long long a, long long b, long long c) {
    long long cur = 1;
    while (b) {
        if (b & 1) cur = cur * a % c;
        a = a * a % c, b >>= 1;
    }
    return cur;
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
    long long q;
    cin >> n >> q >> str;
    for (long long i = 0; i < str.size(); i++) pre_sm[i + 1] = pre_sm[i] + (str[i] == '1');
    for (long long i = 1; i <= n; i++) {
        c[i] = (c[i - 1] + qpow(2, i - 1, MOD)) % MOD;
    }
    for (long long i = 1; i <= q; i++) {
        long long u, v;
        cin >> u >> v;
        long long one_nm = pre_sm[v] - pre_sm[u - 1], zro_nm = v - (u - 1) - one_nm;
        cout << (MOD + c[v - (u - 1)] - c[zro_nm]) % MOD << '\n';
    }


#ifndef ONLINE_JUDGE
    auto end_time = clock();
    cerr << "Execution time: " << (end_time - start_time) * (int) 1e3 / CLOCKS_PER_SEC << " ms\n";
#endif

    return 0;

}