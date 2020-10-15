//Solution
//- 사다리 게임을 조작하여 모든 사다리의 출발지 id와 도착지 id를 일치시키는 문제.
//- Failed 1 : 사다리가 trick이 되는 조건을 한정시켜서 풀었는데 예외의 상황이 있었던 것 같다.
//- Failed 2 : is_trick을 매번 확인하면 time over가 발생한다. add stick 갯수를 0~3으로 증가시키며 체크하는 게 핵심.
//- 풀이과정은 다음과 같다.
//- 1. map[y][x]에 막대를 연결한다. map[y][x]가 true이면 세로위치 y에서 x -> x + 1로 이동한다.
//- 2. 추가할 막대 갯수에 따라 dfs(x, y, cnt, mx)함수를 실행한다.
//- 2.1. answer가 추가할 막대 갯수 mx보다 작은 경우 실헹을 중단한다.
//    - dfs를 통해 변화하는 answer의 기댓값은 mx이므로 실행할 이유가 없음.
//- 2.2. cnt가 mx랑 같은 경우, is_trick()함수를 실행한다.
//- 2.2.1. is_trick()이 true인 경우, 함수는 모든 출발지 - 도착지의 id가 같다. answer에 mx를 대입하고 종료한다.
//- 2.2.2. is_trick()이 false인 경우, 반복을 종료한다.
//- 2.3. x >= N인 경우, 반복을 종료한다.
//- 2.4. y > H인 경우, dfs(x + 1, 1, cnt, mx)를 실행한다.
//- 2.5. 현재 map[y][x]에 사다리를 놓을 수 없을 경우, dfs(x, y + 1, cnt, mx)를 실행한다.
//    - map[y][x - 1], map[y][x], map[y][x + 1] 중 어느 하나라도 연결되어 있다면 연결할 수 없다.
//- 2.6. map[y][x]에 사다리를 놓고 dfs(x, y + 1, cnt + 1, mx)를 실행한다.
//- 2.7. map[y][x]의 사다리를 뺴고 dfs(x, y + 1, cnt, mx)를 실행한다.
//- 2.8. answer의 값이 3보다 큰 경우, answer에 -1을 대입한다.
//- 2.9. answer을 리턴한다.

#include <iostream>

using namespace std;

#define N_MAX 10 + 2 
#define H_MAX 30 + 1

int N, M, H;
bool map[H_MAX][N_MAX];
int answer = 4;

bool is_trick() {
    for (int x = 1; x <= N; x++) {
        int v_locate = x;
        for (int y = 1; y <= H; y++) {
            if (map[y][v_locate - 1]) v_locate--;
            else if (map[y][v_locate]) v_locate++;
        }
        if (v_locate != x) return false;
    }

    return true;
}

void dfs(int x, int y, int cnt, int mx) {
    if (mx >= answer) return;
    if (mx == cnt) {
        if (is_trick()) answer = cnt;
        return;
    }

    if (x >= N) return;
    if (y > H) {
        dfs(x + 1, 1, cnt, mx);
        return;
    }

    if (map[y][x - 1] || map[y][x] || map[y][x + 1]) {
        dfs(x, y + 1, cnt, mx);
        return;
    }

    map[y][x] = true;
    dfs(x, y + 1, cnt + 1, mx);
    map[y][x] = false;
    dfs(x, y + 1, cnt, mx);
}

int solution() {
    for (int i = 0; i <= 3; i++) dfs(1, 1, 0, i);
    if (answer > 3) answer = -1;
    return answer;
}

int main() {
    cin >> N >> M >> H;

    int a;		// 세로 위치, 왼쪽 1
    int b;		// 가로 위치, 맨 위 1
    for (int m = 1; m <= M; m++) {
        cin >> a >> b;
        map[a][b] = true;
    }

    cout << solution() << endl;

    return 0;
}