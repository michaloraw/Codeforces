/* Michal Orawiec 
   Solution for https://codeforces.com/problemset/problem/1368/C
*/
#include <iostream>
#include <vector>

typedef std::pair<int, int> Point;
typedef std::vector<Point> Drawing;

class Drawer {
private: 
    int n;
    Drawing drawing;

    void addPoint(int x, int y);

public:
    Drawer(int n) : n(n) {};

    Drawing getDrawing();
};

int main() {
    int n;
    std::cin >> n;

    Drawer drawer(n);

    std::cout << drawer.getDrawing().size() << "\n";

    for (auto point : drawer.getDrawing())
        std::cout << point.first << " " << point.second << "\n";
    
    return 0;
}

void Drawer::addPoint(int x, int y) {
    drawing.push_back(std::make_pair(x, y));
}

Drawing Drawer::getDrawing() {
    if (!drawing.empty())
        return drawing;

    addPoint(0, 0);
    addPoint(1, 0);

    for (int i = 1; i <= n; i++) {
        addPoint(i - 1, i);
        addPoint(i, i);
        addPoint(i +  1, i);
    }

    addPoint(n, n + 1);
    addPoint(n + 1, n + 1);

    return drawing;
}