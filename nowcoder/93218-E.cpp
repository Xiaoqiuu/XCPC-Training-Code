//Writtern by Akitama
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#define akitama return 0;
using namespace std;

const int INF = 1e9 + 7;

struct Train {
    int startTime, speed, id;//开始时间，速度，滴滴
    vector<int> stops;
};

struct Line {
    int to, dist;//Line信息
};

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;cin >> n >> m;
    vector<Train> trains(m);
    for (int i = 0; i < m; ++i) {
        cin >> trains[i].startTime >> trains[i].speed;
        int k;cin >> k;
        trains[i].stops.resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> trains[i].stops[j];
        }
        trains[i].id = i;
    }
    //线路
    int M;cin >> M;
    vector<vector<Line>> graph(n + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    map<pair<int, int>, tuple<int, int, int>> track;
    vector<string> result(m, "NO");
    for (auto& train : trains) {
        int c_time = train.startTime;
        bool collided = false;
        for (int i = 0; i < train.stops.size() - 1; ++i) {
            int u = train.stops[i], v = train.stops[i + 1], dist = -1;
            for (auto& line : graph[u])
                if (line.to == v) {
                    dist = line.dist;
                    break;
                }
            if (dist == -1) continue;
            int a_time = c_time + dist;
            auto it = track.find({u, v});
            if (it != track.end()) {
                auto [p_time, p_speed, p_id] = it->second;
                if (p_time <= a_time && p_speed < train.speed) {
                    collided = true;
                    break;
                }
                if (p_time == a_time && p_id > train.id) {
                    collided = true;
                    break;
                }
            }
            track[{u, v}] = {a_time, train.speed, train.id};
            c_time = a_time;
        }
        if (collided) {
            result[train.id] = "YES";
        }
    }
    for (const auto& res : result) {
        cout << res << endl;
    }
    akitama;
}
