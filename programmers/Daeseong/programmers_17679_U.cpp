/*Solution
- 중간에서 삽입삭제가 일어나므로 char형 vector 배열을 사용.
- 삭제 중복이 발생할 수 있으므로 삭제는 priority_queue를 사용. (set을 사용하는 게 더 유리할듯)
- 동작 방식은 다음과 같다.
- 1. vector 배열에서 다음을 반복한다.
- 1-1. 같은 성분의 2x2사각형을 찾는다.
- 1-2. priority_queue에 각 성분을 추가한다.
- 2. priority_queue에서 다음을 반복한다.
- 2-1. 이전 위치와 같다면 무시한다.
- 2-2. 현재위치의 vector 성분을 삭제한다.
- 2-3. 변경 여부를 체크한다.
- 3. 변경 여부를 확인하여 변경이 없다면 종료, 있다면 2부터 반복한다*/.


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