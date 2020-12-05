//Solution
//- 주어진 대로 상어들을 이동시키는 시뮬레이션 문제
//- 가장 마지막으로 채취를 남긴 turn을 기록하여 update를 줄였다.
//- 풀이 중 문제 이해에서 미흡한 부분이 있었다.
//- 1. 주변 블럭에 자기 채취가 담긴 블럭이 여러개 일 수 있다.
//- 1.1. 가장 최근 이동한 블럭이 아닌,
//- 1.2. 이동할 수 있는 블럭이 여러개인 경우의 룰을 따른다.
//- 풀이는 다음과 같다.
//- 1. 문제풀이에 필요한 정보를 저장한다.
//- 1.1. N : N x N 맵 크기
//- 1.2. M : 상어 마릿수
//- 1.3. K : 흔적이 남는 duration
//- 1.4. shark 배열에는 다음의 정보를 담는다.
//- 1.4.1. index
//- 1.4.2. 이동방향
//- 1.4.3. 좌표 (x, y)
//- 1.4.4. 이동 우선순위
//- 1.5. map 배열에는 다음의 정보를 담는다.
//- 1.5.1.마지막으로 채취를 남긴 상어 index
//- 1.5.2. 마지막으로 채취를 남긴 turn
//- 2. index가 낮은 순서대로 상어를 이동시킨다.
//- 2.1. 이동할 블럭은 다음의 순서로 판단한다.
//- 2.1.1. 현재 이동방향의 우선순위 대로 다음을 판단한다.
//- 2.1.1.1. 블럭의 위치가 맵 내에 없는 경우, 다음 블럭을 확인한다.
//- 2.1.1.2. 채취가 남아있는(map 내의 turn으로 확인) 블럭인 경우, 다음 블럭을 확인한다.
//- 2.1.1.3. 그 외의 경우, 해당 블럭으로 이동한다.
//- 2.1.2. 2.1.1. 단계에서 이동하지 못한 경우, 우선순위 대로 다음을 판단한다.
//- 2.1.2.1. 블럭의 위치가 맵 내에 없는 경우, 다음 블럭을 확인한다.
//- 2.1.2.2. 자신의 채취가 남아있을 경우, 해당 블럭으로 이동한다.
//- 2.2. 이동한 위치에 이번턴에 이동한 상어(index가 낮은 상어)가 있을 경우, shark에서 제거한다.
//- 2.3. 이동 후, shark에 남은 상어가 1마리 인 경우, turn을 출력한다.
//- 2.4. 1000번째 turn이 지나간 경우, -1을 출력한다.

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

typedef struct SHARK {
    int index;
    int dir;
    int x;
    int y;
    vector<vector<int>> prime;
} SHARK;

typedef struct MAP {
    int id;
    int turn;
} MAP;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int N;
int M;
int K;
vector<vector<MAP>> map;                    // N * N
vector<SHARK> shark;                        // M

void init() {
    cin >> N >> M >> K;
    int temp;
    for (int m = 0; m < M; m++) shark.push_back({ m, -1, -1, -1 });
    for (int y = 0; y < N; y++) {
        vector<MAP> line;
        for (int x = 0; x < N; x++) {
            cin >> temp;
            if (temp == 0) {
                line.push_back({ temp - 1, -1 * K });
            }
            else {
                line.push_back({ temp - 1, 0 });
                shark[temp - 1].x = x;
                shark[temp - 1].y = y;
            }
        }
        map.push_back(line);
    }
    for (int m = 0; m < M; m++) {
        cin >> temp;
        shark[m].dir = temp - 1;
    }
    for (int m = 0; m < M; m++) {
        for (int i = 0; i < 4; i++) {
            vector<int> line;
            for (int j = 0; j < 4; j++) {
                cin >> temp;
                line.push_back(temp - 1);
            }
            shark[m].prime.push_back(line);
        }
    }
}

void move(int turn, vector<vector<MAP>> cp) {
    for (vector<SHARK>::iterator iter = shark.begin(); iter < shark.end();) {
        int x = (*iter).x;
        int y = (*iter).y;
        int dir = (*iter).dir;
        for (int d = 0; d < 4; d++) {
            int ndir = (*iter).prime[dir][d];
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (cp[ny][nx].turn >= turn - K) continue;

            x = nx;
            y = ny;
            dir = ndir;
            break;
        }
        if (x == (*iter).x && y == (*iter).y) {
            for (int d = 0; d < 4; d++) {
                int ndir = (*iter).prime[dir][d];
                int nx = x + dx[ndir];
                int ny = y + dy[ndir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (cp[ny][nx].id != (*iter).index) continue;

                x = nx;
                y = ny;
                dir = ndir;
                break;
            }
        }

        if (map[y][x].turn == turn) {
            iter = shark.erase(iter);
        }
        else {
            (*iter).x = x;
            (*iter).y = y;
            (*iter).dir = dir;

            map[y][x].id = (*iter).index;
            map[y][x].turn = turn;
            iter++;
        }
    }
}

void solve() {
    init();
    int t;
    for (t = 1; t <= 1000; t++) {
        move(t, map);
        if (shark.size() == 1) break;
    }
    if (t == 1001) cout << -1 << endl;
    else cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}