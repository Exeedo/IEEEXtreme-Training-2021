#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int distance_squared(pair<int, int> p) {
    return p.first * p.first + p.second * p.second;
}

bool comp_distance(pair<int, int> &p1, pair<int, int> &p2) {
    return distance_squared(p1) < distance_squared(p2);
}

int main()
{
    vector<pair<int, int>> v;
    v.push_back({ -1,1 });
    v.push_back({ 0,0 });
    v.push_back({ 4,3 });
    v.push_back({ 1,0 });
    sort(v.begin(), v.end(), comp_distance);
    for (auto p : v) {
        cout << p.first << ',' << p.second << endl;
    }
}
