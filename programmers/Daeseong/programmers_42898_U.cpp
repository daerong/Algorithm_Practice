#include <string>
#include <vector>

#define MAP_MAX 102

using namespace std;

bool visited[MAP_MAX][MAP_MAX];
int map[MAP_MAX][MAP_MAX];
int N;
int M;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int last_step;
int result;

void setting(int m, int n, vector<vector<int>> puddles) {
    N = n;
    M = m;
    vector<int> temp;
    while (!puddles.empty()) {
        temp = puddles.back();
        puddles.pop_back();
        visited[temp[1]][temp[0]] = true;
    }
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            map[y][x] = 1000000000;
        }
    }
}
void connection(int x, int y, int cnt) {
    if (visited[y][x]) return;
    if (x <= 0 || x > M || y <= 0 || y > N) return;
    if (cnt > map[y][x]) return;

    if (x == M && y == N) {
        if (map[y][x] > cnt) {
            map[y][x] = cnt;
            result = 1;
        }
        else {
            result += 1;
        }

        return;
    }

    visited[y][x] = true;
    map[y][x] = cnt;

    int nx, ny;
    for (int dir = 0; dir < 4; dir++) {
        nx = x + dx[dir];
        ny = y + dy[dir];
        connection(nx, ny, cnt + 1);
    }

    visited[y][x] = false;
}
int solution(int m, int n, vector<vector<int>> puddles) {
    setting(m, n, puddles);
    connection(1, 1, 0);
    int answer = result;
    return answer;
}