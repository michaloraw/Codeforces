/* Michal Orawiec 
   Solution for https://codeforces.com/contest/960/problem/B 
*/
#include <iostream>
#include <set>
#include <vector>
#include <cmath>

class ErrorMinimizer {
private:
    int n;
    int k1, k2;

    // Multiset of the abs's
    std::multiset<int> abses;

public:
    ErrorMinimizer() = default;

    void readData();
    long long calculateMinimumError();
};

int main() {
    ErrorMinimizer minimizer;

    minimizer.readData();

    std::cout << minimizer.calculateMinimumError() << "\n";

    return 0;
}

void ErrorMinimizer::readData() {
    std::cin >> n >> k1 >> k2;

    // The first array
    std::vector<int> a;

    int tmp;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        a.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        abses.insert(abs(a[i] - tmp));
    }
}

long long ErrorMinimizer::calculateMinimumError() {
    for (int i = 0; i < k1 + k2; i++) {
        int maxAbs = *(abses.rbegin());
        abses.erase(abses.find(maxAbs));

        abses.insert(abs(maxAbs - 1));
    }

    long long result = 0;

    for (auto val : abses)
        result += pow(val, 2);

    return result;
}