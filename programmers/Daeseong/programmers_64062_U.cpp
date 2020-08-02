//Solution
//- Binary Search.
//- �ǳʰ��� ��� ���� �˻�������� �ΰ�
//- �迭�� �ִ� �ּ� step ���� �ʱ� �̺� �迭�� �˻������� �Ѵ�.
//- ��ȸ �� ���� �߰����� �ǳ� �� �ִ� ���� üũ�ϰ�
//- 1. �ǳ� �� �ִٸ� �ǳ��� ���ϴ� ������ ��츦 ������
//- 2. �ǳ� �� ���ٸ� �ǳ� �� �ִ� ������ ��츦 ������.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool can_jump(int& step, int& k, vector<int>& stones) {
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - step <= 0) cnt++;
        else cnt = 0;
        if (cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int start = *min_element(stones.begin(), stones.end());
    int end = *max_element(stones.begin(), stones.end());
    int step;
    while (start <= end) {
        step = (start + end) / 2;
        if (can_jump(step, k, stones)) {
            start = step + 1;
        }
        else {
            end = step - 1;
        }
    }

    return start;
}