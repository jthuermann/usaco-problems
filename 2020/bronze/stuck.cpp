// USACO 2020 December Contest, Bronze
// Problem 3. Stuck in a Rut
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1061

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> cows;

long long get_distance(int index, vector<long long>& distances, vector<int>& east, vector<int>& north, bool is_north) {
    if (distances[index] != 0)
        return distances[index];
    pair<long long, long long> cow_t = cows[index];
    pair<long long, long long> cow_o;
    long long max_distance = -1;
    if (is_north) {
        for (int n: north)
            if (cows[n].first == cow_t.first && cows[n].second > cow_t.second) {
                if (max_distance == -1)
                    max_distance = cows[n].second - cow_t.second;
                else
                    max_distance = min(max_distance, cows[n].second - cow_t.second);
            }
    } else {
        for (int e: east)
            if (cows[e].second == cow_t.second && cows[e].first > cow_t.first) {
                if (max_distance == -1)
                    max_distance = cows[e].first - cow_t.first;
                else
                    max_distance = min(max_distance, cows[e].first - cow_t.first);
            }
    }
    if (is_north) {
        for (int e: east) {
            cow_o = cows[e];
            if (max_distance != -1 && max_distance <= cow_o.second - cow_t.second)
                continue;
            if (cow_o.first > cow_t.first || cow_o.second < cow_t.second)
                continue;
            if (cow_o.second - cow_t.second <= cow_t.first - cow_o.first)
                continue;
            long long distance_e = get_distance(e, distances, east, north, false);
            if (distance_e == -1 || distance_e > cow_t.first - cow_o.first) {
                distances[index] = cow_o.second - cow_t.second;
                return distances[index];
            }
        }
        distances[index] = max(-1ll, max_distance);
        return distances[index];
    } else {
        for (int n: north) {
            cow_o = cows[n];
            if (max_distance != -1 && max_distance <= cow_o.first - cow_t.first)
                continue;
            if (cow_t.first > cow_o.first || cow_t.second < cow_o.second)
                continue;
            if (cow_o.first - cow_t.first <= cow_t.second - cow_o.second)
                continue;
            long long distance_n = get_distance(n, distances, east, north, true);
            if (distance_n == -1 || distance_n > cow_t.second - cow_o.second) {
                distances[index] = cow_o.first - cow_t.first;
                return distances[index];
            }
        }
        distances[index] = max(-1ll, max_distance);
        return distances[index];
    }
}

bool cmp_north(int a, int b) {
    if (cows[a].first == cows[b].first)
        return cows[a].second < cows[b].second;
    return cows[a].first < cows[b].first;
}

bool cmp_east(int a, int b) {
    if (cows[a].second == cows[b].second)
        return cows[a].first < cows[b].first;
    return cows[a].second < cows[b].second;
}

int main() {
    int N;
    cin >> N;
    vector<long long> distances(N, 0);
    vector<int> east;
    vector<int> north;
    for (int i = 0; i < N; i++) {
        char direction;
        long long x, y;
        cin >> direction >> x >> y;
        cows.push_back(make_pair(x, y));
        if (direction == 'N')
            north.push_back(static_cast<int>(cows.size() - 1));
        else
            east.push_back(static_cast<int>(cows.size() - 1));
    }
    sort(north.begin(), north.end(), cmp_north);
    sort(east.begin(), east.end(), cmp_east);
    for (int i = 0; i < north.size(); i++)
        get_distance(north[i], distances, east, north, true);
    for (int i = 0; i < east.size(); i++)
        get_distance(east[i], distances, east, north, false);
    for (int i = 0; i < N; i++) {
        if (distances[i] != -1)
            cout << distances[i] << endl;
        else
            cout << "Infinity" << endl;
    }
}
