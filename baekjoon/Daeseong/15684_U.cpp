//Solution
//- ��ٸ� ������ �����Ͽ� ��� ��ٸ��� ����� id�� ������ id�� ��ġ��Ű�� ����.
//- Failed 1 : ��ٸ��� trick�� �Ǵ� ������ �������Ѽ� Ǯ���µ� ������ ��Ȳ�� �־��� �� ����.
//- Failed 2 : is_trick�� �Ź� Ȯ���ϸ� time over�� �߻��Ѵ�. add stick ������ 0~3���� ������Ű�� üũ�ϴ� �� �ٽ�.
//- Ǯ�̰����� ������ ����.
//- 1. map[y][x]�� ���븦 �����Ѵ�. map[y][x]�� true�̸� ������ġ y���� x -> x + 1�� �̵��Ѵ�.
//- 2. �߰��� ���� ������ ���� dfs(x, y, cnt, mx)�Լ��� �����Ѵ�.
//- 2.1. answer�� �߰��� ���� ���� mx���� ���� ��� ������ �ߴ��Ѵ�.
//    - dfs�� ���� ��ȭ�ϴ� answer�� ����� mx�̹Ƿ� ������ ������ ����.
//- 2.2. cnt�� mx�� ���� ���, is_trick()�Լ��� �����Ѵ�.
//- 2.2.1. is_trick()�� true�� ���, �Լ��� ��� ����� - �������� id�� ����. answer�� mx�� �����ϰ� �����Ѵ�.
//- 2.2.2. is_trick()�� false�� ���, �ݺ��� �����Ѵ�.
//- 2.3. x >= N�� ���, �ݺ��� �����Ѵ�.
//- 2.4. y > H�� ���, dfs(x + 1, 1, cnt, mx)�� �����Ѵ�.
//- 2.5. ���� map[y][x]�� ��ٸ��� ���� �� ���� ���, dfs(x, y + 1, cnt, mx)�� �����Ѵ�.
//    - map[y][x - 1], map[y][x], map[y][x + 1] �� ��� �ϳ��� ����Ǿ� �ִٸ� ������ �� ����.
//- 2.6. map[y][x]�� ��ٸ��� ���� dfs(x, y + 1, cnt + 1, mx)�� �����Ѵ�.
//- 2.7. map[y][x]�� ��ٸ��� ���� dfs(x, y + 1, cnt, mx)�� �����Ѵ�.
//- 2.8. answer�� ���� 3���� ū ���, answer�� -1�� �����Ѵ�.
//- 2.9. answer�� �����Ѵ�.

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

    int a;		// ���� ��ġ, ���� 1
    int b;		// ���� ��ġ, �� �� 1
    for (int m = 1; m <= M; m++) {
        cin >> a >> b;
        map[a][b] = true;
    }

    cout << solution() << endl;

    return 0;
}