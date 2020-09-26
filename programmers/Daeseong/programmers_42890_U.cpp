//Solution
//- Using bitmask.
//- ���ٹ���� ���ø��� ���� ����� ������ ����.
//- 1. �ĺ�Ű�� ã�´�. (�ߺ��� ������ �������)
//- 1-1. �ĺ�Ű�� ���� ���� ������ �����Ѵ�. (1���� ��������)
//- 1-1-1. 1���� n(2^column�� ����)�̸��� �� ������ ���� ������ �����Ѵ�.
//- 1-1-1-1. 1-1-1�� �̷�� ���ڸ� 2���� ��ȯ �� 1�� ������ 1-1�� ������ ��ġ�� ��� ������ �����Ѵ�.
//- 1-1-1-2. ������ column�ȿ� �ִ� string�� ��� ���Ѵ�.
//- 1-1-1-3. ������ string�� map�ȿ� �ִ� �� Ȯ���Ѵ�.
//- 1-1-1-3-1. ���� ���, �ĺ�Ű�� ���� �� ���ϼ��� ����ǹǷ� �ĺ�Ű�� �̷� �� ����.
//- 1-1-1-3-2. ���� ���, map�� ������ string�� �߰��Ѵ�.
//- 1-1-1-4. ��� ���п� ���� ���ϼ��� ����Ǵ� ��� 1-1-1�� ���ڸ� result_set ���Ϳ� �߰��Ѵ�.
//- 1-2. result_set ����(���������� ��Ÿ�� �ĺ�Ű)�� ���� �ּҼ��� �Ǵ��Ѵ�.
//- 1-2-1. result_set�� ������ ���Һ��� ������ �����Ѵ�.
//- 1-2-1-1. 1-2-1.�� ���� �տ� �ִ� ��� ���ҿ� ���� �κ����� ���踦 ���� �� Ȯ���Ѵ�.
//            - (result_set[i] | result_set[j]) == result_set[i]�� ���, �κ��������� �� �� �ִ�.
//- 1-1-1-2. �κ������� ��� 1-2-1. ���Ҹ� �����Ѵ�.
//- 1-3. ���������� result_set�� �����ִ� ������ ���ϼ��� �ּҼ��� �����ϴ� �ĺ�Ű�̹Ƿ� ������ �����Ѵ�.

#include <iostream>
// Code start

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

#define C_MAX 8
#define R_MAX 20

int get_volume(int n) {
    int cnt = 0;
    for (int locate = 0; locate < 8; locate++) {
        if (n & (1 << locate)) cnt++;
    }
    return cnt;
}

int solution(vector<vector<string>> relation) {
    int row_max = relation.size();
    int col_max = relation[0].size();
    int check_max = pow(2, col_max);

    unordered_map<string, int> m;
    int m_index = 0;
    vector<int> result_set;

    int each_vol[256];
    for (int n = 1; n < check_max; n++) {
        each_vol[n] = get_volume(n);
    }

    // 1. �ĺ�Ű�� ã�´�. (�ߺ��� ������ �������)
    for (int volume = 1; volume <= col_max; volume++) {
        // 1-1. �ĺ�Ű�� ���� ���� ������ �����Ѵ�. (1���� ��������)
        for (int n = 1; n < check_max; n++) {
            // 1-1-1. 1���� n(2^column�� ����)�̸��� �� ������ ���� ������ �����Ѵ�.
            if (each_vol[n] != volume) continue;    
            // 1-1-1-1. 1-1-1�� �̷�� ���ڸ� 2���� ��ȯ �� 1�� ������ 1-1�� ������ ��ġ�� ��� ������ �����Ѵ�.
            for (int row = 0; row < row_max; row++) {
                string temp = "";
                for (int col = 0; col < col_max; col++) {
                    // 1-1-1-2. ������ column�ȿ� �ִ� string�� ��� ���Ѵ�.
                    if (n & (1 << col)) temp += relation[row][col];
                }
                // 1-1-1-3. ������ string�� map�ȿ� �ִ� �� Ȯ���Ѵ�.
                if (m.count(temp) == 1) {
                    // 1-1-1-3-1. ���� ���, �ĺ�Ű�� ���� �� ���ϼ��� ����ǹǷ� �ĺ�Ű�� �̷� �� ����.
                    m.clear();
                    m_index = 0;
                    break;
                }
                else {
                    // 1-1-1-3-2. ���� ���, map�� ������ string�� �߰��Ѵ�.
                    m.insert({ temp, m_index++ });
                }
            }

            if (!m.empty()) {
                // 1-1-1-4. ��� ���п� ���� ���ϼ��� ����Ǵ� ��� 1-1-1�� ���ڸ� result_set ���Ϳ� �߰��Ѵ�.
                result_set.push_back(n);
                m.clear();
                m_index = 0;
            }
        }
    }

    // 1-2. result_set ����(���������� ��Ÿ�� �ĺ�Ű)�� ���� �ּҼ��� �Ǵ��Ѵ�.
    for (int i = result_set.size() - 1; i >= 0; i--) {
        // 1-2-1. result_set�� ������ ���Һ��� ������ �����Ѵ�.
        for (int j = i - 1; j >= 0; j--) {
            // 1-2-1-1. 1-2-1.�� ���� �տ� �ִ� ��� ���ҿ� ���� �κ����� ���踦 ���� �� Ȯ���Ѵ�.
            if ((result_set[i] | result_set[j]) == result_set[i]) {
                // 1-1-1-2. �κ������� ��� 1-2-1. ���Ҹ� �����Ѵ�.
                result_set.erase(result_set.begin() + i);
                break;
            }
        }
    }

    // 1-3. ���������� result_set�� �����ִ� ������ ���ϼ��� �ּҼ��� �����ϴ� �ĺ�Ű�̹Ƿ� ������ �����Ѵ�.
    return result_set.size();
}

// Code end
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<string>> relation;
    relation.push_back({ "100", "ryan", "music", "2" });
    relation.push_back({ "200", "apeach", "math", "2" });
    relation.push_back({ "300", "tube", "computer", "3" });
    relation.push_back({ "400", "con", "computer", "4" });
    relation.push_back({ "500", "muzi", "music", "3" });
    relation.push_back({ "600", "apeach", "music", "2" });

    cout << solution(relation);

    return 0;
}