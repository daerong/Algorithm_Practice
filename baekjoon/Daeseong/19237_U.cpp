//Solution
//- �־��� ��� ������ �̵���Ű�� �ùķ��̼� ����
//- ���� ���������� ä�븦 ���� turn�� ����Ͽ� update�� �ٿ���.
//- Ǯ�� �� ���� ���ؿ��� ������ �κ��� �־���.
//- 1. �ֺ� ���� �ڱ� ä�밡 ��� ���� ������ �� �� �ִ�.
//- 1.1. ���� �ֱ� �̵��� ���� �ƴ�,
//- 1.2. �̵��� �� �ִ� ���� �������� ����� ���� ������.
//- Ǯ�̴� ������ ����.
//- 1. ����Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. N : N x N �� ũ��
//- 1.2. M : ��� ������
//- 1.3. K : ������ ���� duration
//- 1.4. shark �迭���� ������ ������ ��´�.
//- 1.4.1. index
//- 1.4.2. �̵�����
//- 1.4.3. ��ǥ (x, y)
//- 1.4.4. �̵� �켱����
//- 1.5. map �迭���� ������ ������ ��´�.
//- 1.5.1.���������� ä�븦 ���� ��� index
//- 1.5.2. ���������� ä�븦 ���� turn
//- 2. index�� ���� ������� �� �̵���Ų��.
//- 2.1. �̵��� ���� ������ ������ �Ǵ��Ѵ�.
//- 2.1.1. ���� �̵������� �켱���� ��� ������ �Ǵ��Ѵ�.
//- 2.1.1.1. ���� ��ġ�� �� ���� ���� ���, ���� ���� Ȯ���Ѵ�.
//- 2.1.1.2. ä�밡 �����ִ�(map ���� turn���� Ȯ��) ���� ���, ���� ���� Ȯ���Ѵ�.
//- 2.1.1.3. �� ���� ���, �ش� ������ �̵��Ѵ�.
//- 2.1.2. 2.1.1. �ܰ迡�� �̵����� ���� ���, �켱���� ��� ������ �Ǵ��Ѵ�.
//- 2.1.2.1. ���� ��ġ�� �� ���� ���� ���, ���� ���� Ȯ���Ѵ�.
//- 2.1.2.2. �ڽ��� ä�밡 �������� ���, �ش� ������ �̵��Ѵ�.
//- 2.2. �̵��� ��ġ�� �̹��Ͽ� �̵��� ���(index�� ���� ���)�� ���� ���, shark���� �����Ѵ�.
//- 2.3. �̵� ��, shark�� ���� �� 1���� �� ���, turn�� ����Ѵ�.
//- 2.4. 1000��° turn�� ������ ���, -1�� ����Ѵ�.

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