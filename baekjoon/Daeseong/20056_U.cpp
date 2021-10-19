#include <iostream>
#include <vector>

#define MAX 51
#define endl "\n"
using namespace std;

typedef struct FB {
    int x;
    int y;
    int m;
    int s;
    int d;
} FB;

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;
vector<FB> map[MAX][MAX];
vector<FB> fb;

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fb.push_back({ c, r, m, s, d });
        map[r][c].push_back({ c, r, m, s, d });
    }
}

void move() {
    for (int ny = 1; ny <= N; ny++) {
        for (int nx = 1; nx <= N; nx++) {
            map[ny][nx].clear();
        }
    }

    for (vector<FB>::iterator iter = fb.begin(); iter < fb.end(); iter++) {
        int ns = iter->s % N;

        int nx = iter->x + dx[iter->d] * ns;
        if (nx > N) nx -= N;
        if (nx <= 0) nx += N;
        int ny = iter->y + dy[iter->d] * ns;
        if (ny > N) ny -= N;
        if (ny <= 0) ny += N;

        map[nx][ny].push_back({ nx, ny, iter->m, iter->s, iter->d });
        iter->x = nx;
        iter->y = ny;
    }
}

void crush() {
    vector<FB> temp;
    for (int ny = 1; ny <= N; ny++) {
        for (int nx = 1; nx <= N; nx++) {
            if (map[ny][nx].size() == 1) {
                temp.push_back(map[ny][nx][0]);
                continue;
            }
            else {
                int mSum = 0;
                int sSum = 0;
                int cnt = map[ny][nx].size();
                bool isEven = false;
                bool isOdd = false;
                for (int k = 0; k < map[ny][nx].size(); k++) {
                    mSum += map[ny][nx][k].m;
                    sSum += map[ny][nx][k].s;
                    switch (map[ny][nx][k].d % 2) {
                    case 0:
                        isEven = true;
                        break;
                    case 1:
                        isOdd = true;
                        break;
                    }
                }

                int newM = mSum / 5;
                if (newM == 0) continue;
                int newS = sSum / cnt;

                if (isEven && isOdd) {
                    for (int k = 1; k < 8; k += 2) temp.push_back({ ny, nx, newM, newS, k });
                }
                else {
                    for (int k = 0; k < 8; k += 2) temp.push_back({ ny, nx, newM, newS, k });
                }
            }
        }
    }
    fb = temp;
}

void solve() {
    input();

    for (int i = 0; i < K; i++) {
        move();
        crush();
    }

    int Answer = 0;
    for (vector<FB>::iterator iter = fb.begin(); iter < fb.end(); iter++) Answer += iter->m;

    cout << Answer << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}