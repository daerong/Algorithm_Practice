#include <string>
#include <vector>

#define MAP_MAX 102

using namespace std;
bool wet[MAP_MAX][MAP_MAX];
int map[MAP_MAX][MAP_MAX];
int N;
int M;

void setting(int m, int n, vector<vector<int>> puddles) {
    N = n;
    M = m;
    vector<int> temp;
    while (!puddles.empty()) {
        temp = puddles.back();
        puddles.pop_back();
        wet[temp[1]][temp[0]] = true;
    }

    map[1][1] = 1;
    for (int x = 2; x <= M; x++) {
        if (wet[1][x]) continue;
        map[1][x] = map[1][x - 1];
    }
    for (int y = 2; y <= N; y++) {
        if (wet[y][1]) continue;
        map[y][1] = map[y - 1][1];
    }
}
void connection() {
    for (int y = 2; y <= N; y++) {
        for (int x = 2; x <= M; x++) {
            if (wet[y][x]) continue;
            map[y][x] = map[y - 1][x] + map[y][x - 1];
        }
    }
}
int solution(int m, int n, vector<vector<int>> puddles) {
    setting(m, n, puddles);
    connection();
    return map[N][M] % 1000000007;
}