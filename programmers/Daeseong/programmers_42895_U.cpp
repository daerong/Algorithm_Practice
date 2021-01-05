//Solution
//- �־��� ���� N�� ��Ģ����, ��ȣ, ��ȣ�� ������ ����� �ּ� N���� number�� ����� ������ ã�� ����
//- Failed 1 : Testcase #2 ������.
//- 1. m[5]�� �����ϱ� ����, (m[1], m[4]), (m[2], m[3]) ���ո� Ȯ���ϴ� �������� ���ܰ� �߻��ߴ�.
//- 2. (m[1], m[4]), (m[2], m[3], (m[3], m[2]), (m[4], m[1]) ���θ� Ȯ���ϴ� �ذ��ߴ�.
//- �̷��� ������ ����.
//- 1. X���� ����� ���� �� �ִ� ��� ���ڴ� m[N]�� �����Ѵ�.
//- 2. m[X]�� i�� j(1 < i, j < X)�� ������ ��Ģ�������� ������ �� �ִ�.
//- 3. ��, X���� ���ڸ� �������� ������ NN...N�� ��Ģ�������� ������ �� �����Ƿ� ������ �߰��Ѵ�.
//- 4. X�� ������Ű�� m[X]���� number�� ã�´�.
//- Ǯ�̰����� ������ ����.
//1. Ǯ�̿� �ʿ��� ���� �����Ѵ�.
//1.1. m[N] : N���� ���ڷ� ���� �� �ִ� ��� ������ ����
//2. N == number�� ���, 1�� return�Ѵ�.
//3. m[1]�� N�� ����
//3.1. m[1]�� ���Ҵ� N�� �����ϴ�.
//4. cnt�� 2~8���� ������� ������Ű�� ������ �����Ѵ�.
//4.1. cnt���� ���ڸ� ������ N...N�� m[cnt]�� �߰��Ѵ�.
//4.2. i + j = cnt(1 < i, j < cnt)�� �Ǵ� ��� ���տ� ���� ������ �����Ѵ�.
//4.2.1. m[i][] + m[j][]�� m[cnt]�� �߰��Ѵ�. (m[i][], m[j][]�� m[i], m[j]������ ���Ҹ� �ǹ�)
//4.2.2. m[i][] - m[j][]�� m[cnt]�� �߰��Ѵ�.
//4.2.3. m[i][] * m[j][]�� m[cnt]�� �߰��Ѵ�.
//4.2.4. m[i][] / m[j][]�� m[cnt]�� �߰��Ѵ�.
//4.2.4.1. m[j][]�� 0�� ���, ����.
//4.3. m[cnt]�� number�� �ִٸ� cnt�� return�Ѵ�.
//5. �� ������ �����Ͽ� number�� ã�� ���ϸ� -1�� return�Ѵ�.

#include <string>
#include <unordered_set>

using namespace std;

#define LAST 8

unordered_set<int> m[LAST + 1];

int solution(int N, int number) {
    if (N == number) return 1;
    int temp = N;
    m[1].insert(temp);
    for (int cnt = 2; cnt <= LAST; cnt++) {
        temp = temp * 10 + N;
        m[cnt].insert(temp);

        for (int i = 1; i < cnt; i++) {
            int j = cnt - i;
            for (unordered_set<int>::iterator it1 = m[i].begin(); it1 != m[i].end(); it1++) {
                for (unordered_set<int>::iterator it2 = m[j].begin(); it2 != m[j].end(); it2++) {
                    m[cnt].insert({ *it1 + *it2 });
                    m[cnt].insert({ *it1 - *it2 });
                    m[cnt].insert({ *it1 * *it2 });
                    if (*it2 != 0) m[cnt].insert(*it1 / *it2);
                }
            }
            if (m[cnt].find(number) != m[cnt].end()) return cnt;
        }
    }

    return -1;
}