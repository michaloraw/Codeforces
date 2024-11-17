/* Michal Orawiec 
   Solution for https://codeforces.com/problemset/problem/1473/D
*/
#include <iostream>
#include <vector>

class ProgramSolver {
private:
    int n;
    std::vector<int> minVal, maxVal, lastVal, minValFromEnd, maxValFromEnd;

public:
    ProgramSolver(std::string program) : n(program.size()) {
        int sum = 0, mini = 0, maxi = 0;

        minVal.push_back(0);
        maxVal.push_back(0);
        lastVal.push_back(0);

        for (auto operation : program) {
            if (operation == '-')
                --sum;
            else
                ++sum;

            mini = std::min(mini, sum);
            maxi = std::max(maxi, sum);

            minVal.push_back(mini);
            maxVal.push_back(maxi);
            lastVal.push_back(sum);
        }

        sum = 0;

        minValFromEnd.push_back(0);
        maxValFromEnd.push_back(0);

        for (int i = program.size() - 1; i >= 0; i--) {
            char operation = program[i];
        
            minValFromEnd.push_back(minValFromEnd.back());
            maxValFromEnd.push_back(maxValFromEnd.back());

            if (operation == '-') {
                minValFromEnd.back()--;
                maxValFromEnd.back() = std::max(0, maxValFromEnd.back() - 1);
            }
            else {
                minValFromEnd.back() = std::min(0, minValFromEnd.back() + 1);
                maxValFromEnd.back()++;
            }
        }
    }

    int distinctValues(int l, int r) {
        int distinctVals = abs(minVal[l - 1] - maxVal[l - 1]) + 1;
        int minValReverse = minValFromEnd[n - r] + lastVal[l - 1];
        int maxValReverse = maxValFromEnd[n - r] + lastVal[l - 1];

        if (minValReverse < minVal[l - 1])
            distinctVals += abs(minVal[l - 1] - minValReverse);
        if (maxValReverse > maxVal[l - 1])
            distinctVals += abs(maxVal[l - 1] - maxValReverse);

        return distinctVals;
    }
};

int main() {
    int t, n, m, l, r;
    std::string program;

    std::cin >> t;

    while (t--) {
        std::cin >> n >> m;
        std::cin >> program;

        ProgramSolver solver(program);

        while (m--) {
            std::cin >> l >> r;

            std::cout << solver.distinctValues(l, r) << "\n";
        }
    }

    return 0;
}