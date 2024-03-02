#include <iostream>
#include "map.hpp"
using namespace std;

int main() {
    List<pair<int, double>> l = List<pair<int, double>>();

    l.Insert({1, 0});
    l.Print();

    return 0;
}
