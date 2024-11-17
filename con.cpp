/* Michal Orawiec 
   Solution for https://codeforces.com/problemset/problem/938/C
*/
#include <iostream>
#include <cmath>

std::pair<int, int> calculateAnswer(int x) {
    if (x == 0)
        return std::make_pair(1, 1);

    for (int div = 1; div * div <= x; div++) {
        if (x % div == 0) { // We've found a divisor
            int div2 = x / div;
            int diff = div2 - div;
            int ratio = diff / 2;

            int n = sqrt(x + ratio * ratio);

            if (ratio == 0)
                continue;

            int m = n / ratio;

            if (m == 0)
                continue;

            if (n * n - (ceil(n / m) * ceil(n / m)) == x)
                return std::make_pair(n, m);
        }
    }

    return std::make_pair(0, 0);
}

int main() {
    int t, x;

    std::cin >> t;

    while (t--) {
        std::cin >> x;

        std::pair<int, int> answer = calculateAnswer(x);

        if (answer.first == 0)
            std::cout << -1 << "\n";
        else
            std::cout << answer.first << " " << answer.second << "\n";
    }

    return 0;
}