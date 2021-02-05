//Solution
//- 3���� �̵��� ���� BFS�� Ȯ���Ű�� ������ üũ�ϴ� ����
//- �̷��� ������ ������ ����.
//- 1. �̵��� 3������ �ð��� 0, 1�� �ٸ��� �߰��ȴ�.
//- 2. �ð��� ������������ Ȯ���� �����ؾ� �Ѵ�.
//- 3. priority_queue�� ����Ͽ� BFS�� �Ѵ�.
//- 4. time�� ������������ ����ǹǷ� B�� ��ġ�ϴ� ���� ���� ����Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. visited : �湮�� üũ�� �迭
//- 1.2. pq : �ð��� ��������, index�� ������������ ���ĵ� �켱���� ť
//- 2. BFS()�� �����ϸ� �������� ã�´�.
//- 2.1. ó������ (A, 0)���� �����Ѵ�.
//- 2.2. B�� ��ġ�ϸ� time�� ����ϰ� �ݺ��� �����Ѵ�.
//- 2.3. �湮���� ���� ���, �湮�� üũ�ϰ� 3���� �̵��� ���� pq�� �߰��Ѵ�.
//- 2.4. ���� �������� 2.2.�ܰ踦 �ݺ��Ѵ�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 100001

typedef struct NDOE {
    int step;
    int time;
} NODE;
bool operator <(NODE a, NODE b) {
    if (a.time == b.time) return a.step > b.step;
    return a.time > b.time;
}

int A, B;
bool visited[N_MAX];

void init() {
    cin >> A >> B;
}

int bfs() {
    priority_queue<NODE> pq;

    pq.push({ A, 0 });
    visited[A] = true;

    NODE temp;
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();

        if (temp.step == B) return temp.time;

        if (temp.step * 2 < N_MAX && !visited[temp.step * 2]) {
            pq.push({ temp.step * 2, temp.time });
            visited[temp.step * 2] = true;
        }

        if (temp.step + 1 < N_MAX && !visited[temp.step + 1]) {
            pq.push({ temp.step + 1,temp.time + 1 });
            visited[temp.step + 1] = true;
        }

        if (temp.step - 1 >= 0 && !visited[temp.step - 1]) {
            pq.push({ temp.step - 1,temp.time + 1 });
            visited[temp.step - 1] = true;
        }
    }
}

void solution() {
    init();
    cout << bfs() << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}