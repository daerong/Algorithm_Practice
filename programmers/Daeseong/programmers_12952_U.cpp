//solution
//- ����, ����, �밢���� ��ġ�� �ʰ� ��ġ�ϴ� ������ ���� ���ϴ� ����.
//- �̷��� ������ ������ ����.
//- 1. ���� ��� ���� ���� ������ �� �����Ƿ� ��-�� ���� ����Ͽ� üũ�Ѵ�.
//- 2. dfs�� ������ ������ ã�´�.
//- 2.1. ��, ������������ üũ�Ͽ� �ߺ��� �����Ѵ�.
//- 3. ���� �ߺ��� �Ұ��ϹǷ� ������ �߰��� üũ�ؾ� �Ѵ�.
//- 3.1. ���� �ߺ��� üũ�Ѵ�.
//- 3.2. �밢���θ� üũ�Ѵ�.
//- 4. 3.�� �ش����� �ʴ� ������ ���� üũ�Ͽ� ����Ѵ�.
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. vector<int> map : y�� ���� x�� ������ �迭
//- 1.2. answer : ��, �־��� ���ǿ� �ش��ϴ� ������ ��
//- 2. expand(map, y) �Լ��� ���� bfs�� �����ϸ� ������ ã�Ƴ�����.
//- 2.1. y�� �ش��ϴ� x�� �����ϰ� is_cross() �Լ����� �ߺ����θ� üũ�Ѵ�.
//- 2.1.1. 0 ~ y-1���� ������ Ȯ���Ѵ�.
//- 2.1.2. map[]���� map[y]�� ���� ���� ���� �ִ� �� Ȯ���Ѵ�.
//- 2.1.3. map[]���� map[y]�� ���� �밢�� �̷�� �� Ȯ���Ѵ�.
//- 2.1.4. 2.1.2.�� 2.1.3.�� �ش��Ѵٸ� ��Ģ�� �����ϹǷ� �����Ѵ�.
//- 3. �� ��� �ϳ��� queen�� �����ϹǷ� y == n�� ��, ������ Ȯ���Ѵ�.
//- 3.1. 2.1.4.�� �ش����� �ʴ� �����̸� answer�� 1 ������Ų��.
//- 4. answer�� ����Ѵ�.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;

bool is_cross(vector<int> map, int y) {
    for (int i = 0; i < y; i++) {
        if (map[i] == map[y]) return true;
        if (abs(map[i] - map[y]) == abs(i - y)) return true;
    }
    return false;
}

void expand(vector<int> map, int y) {
    if (y == map.size()) {
        answer++;
        return;
    }

    for (int x = 0; x < map.size(); x++) {
        map[y] = x;
        if (!is_cross(map, y)) {
            expand(map, y + 1);
        }
    }
}

int solution(int n) {
    vector<int> map(n);
    expand(map, 0);
    return answer;
}