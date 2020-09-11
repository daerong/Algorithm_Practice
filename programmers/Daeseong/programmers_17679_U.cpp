/*Solution
- �߰����� ���Ի����� �Ͼ�Ƿ� char�� vector �迭�� ���.
- ���� �ߺ��� �߻��� �� �����Ƿ� ������ priority_queue�� ���. (set�� ����ϴ� �� �� �����ҵ�)
- ���� ����� ������ ����.
- 1. vector �迭���� ������ �ݺ��Ѵ�.
- 1-1. ���� ������ 2x2�簢���� ã�´�.
- 1-2. priority_queue�� �� ������ �߰��Ѵ�.
- 2. priority_queue���� ������ �ݺ��Ѵ�.
- 2-1. ���� ��ġ�� ���ٸ� �����Ѵ�.
- 2-2. ������ġ�� vector ������ �����Ѵ�.
- 2-3. ���� ���θ� üũ�Ѵ�.
- 3. ���� ���θ� Ȯ���Ͽ� ������ ���ٸ� ����, �ִٸ� 2���� �ݺ��Ѵ�*/.


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define M_MAX 30

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    vector<char> vec[30];
    for (int y = m - 1; y >= 0; y--) {
        string temp = board[y];
        for (int x = 0; x < n; x++) {
            vec[x].emplace_back(temp[x]);
        }
    }
    
    priority_queue<int> pq[30];

    bool is_change = true;
    while (is_change) {
        is_change = false;
        for (int x = 1; x < n; x++) {
            if (vec[x - 1].size() < 2 || vec[x].size() < 2) continue;
            int minLen = min(vec[x - 1].size(), vec[x].size());
            for (int y = 1; y < minLen; y++) {
                if (vec[x][y - 1] == vec[x][y]) {
                    if (vec[x][y] == vec[x - 1][y - 1] && vec[x - 1][y - 1] == vec[x - 1][y]) {
                        pq[x].push(y);
                        pq[x].push(y - 1);
                        pq[x - 1].push(y);
                        pq[x - 1].push(y - 1);
                    }
                }
            }
        }

        for (int x = 0; x < n; x++) {
            if (!pq[x].empty()) is_change = true;
            int locate = -1;
            while (!pq[x].empty()) {
                if (locate == pq[x].top()) {
                    pq[x].pop();
                    continue;
                }

                locate = pq[x].top();
                pq[x].pop();

                vec[x].erase(vec[x].begin() + locate);
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m = 4;
    int n = 5;
    vector<string> board;
    board.push_back("CCBDE");
    board.push_back("AAADE");
    board.push_back("AAABF");
    board.push_back("CCBBF");

    cout << solution(m, n, board);

    return 0;
}