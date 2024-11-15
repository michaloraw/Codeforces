/* Michal Orawiec 
   Solution for https://codeforces.com/problemset/problem/431/C
*/
#include <iostream>

int main() {
    int n, k, d;
    const int MAX_N = 100;
    const int MOD = 1000 * 1000 * 1000 + 7;

    /* paths[s][0] = number of paths with sum s without any edge of weight at least d
       paths[s][1] = number of paths with sum s with an edge of weight at least d
    */
    int paths[MAX_N + 1][2];

    for (int i = 0; i <= MAX_N; i++)
        paths[i][0] = paths[i][1] = 0;

    paths[0][0] = 1;

    std::cin >> n >> k >> d;

    for (int sum = 1; sum <= n; sum++) {
        int dp1 = 0;

        for (int a = 1; a <= std::min(sum, k); a++) {
            dp1 += paths[sum - a][0];
            dp1 %= MOD;
        }
        
        paths[sum][0] = dp1;

        int dp2 = 0;

        for (int a = d; a <= std::min(sum, k); a++) {
            dp2 += paths[sum - a][0];
            dp2 %= MOD;
        }

        for (int a = 1; a < std::min(sum, d); a++) {
            dp2 += paths[sum - a][1];
            dp2 %= MOD;
        }

        paths[sum][1] = dp2;
    }

    std::cout << paths[n][1] << "\n";

    return 0;
}