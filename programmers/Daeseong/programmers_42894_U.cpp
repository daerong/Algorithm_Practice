//Solution
//- 전형적인 시뮬레이션 문제.
//- 블럭이 맨 위에 있는지 확인하는 is_top()함수와 제거할 수 있는 블럭의 케이스를 판단하는 shape_type() 함수를 만들어 사용함.
//- 문제풀이 과정은 다음과 같다.
//- 1. y의 오름차, x의 오름차 순서대로 모든 블럭을 순회하며 다음을 수행한다.
//- 1.1. Hashmap에 이미 체크한 블럭인 지 확인한다.                  // unordered_map<int, int>
//- 1.1.1. 있으면 무시하고 다음 반복문을 수행.
//- 1.1.2. 없으면 Hashmap에 넣고 1.2.를 수행한다.
//- 1.2. 블럭의 케이스를 판단하는 shape_type() 함수를 수행한다. 
//    - 이를 통해 저장되는 블럭은 위에 검은 블럭을 쌓아 직사각형 형태가 되는 종류로 그 종류는 다음과 같다.
//- 1.2.1. 오른쪽이 더 긴 |_ 형태의 블럭.
//- 1.2.2. _|_ 형태의 블럭.
//- 1.2.3. 왼쪽이 더 긴 _| 형태의 블럭.
//- 1.2.4. 윗쪽이 더 긴 |_ 형태의 블럭.
//- 1.2.5.윗쪽이 더 긴 _| 형태의 블럭.
//- 1.3. 1.2.에서 찾아낸 블럭을 vector<LOCATE>에 추가한다.          // vector<LOCATE>
//- 2. 1.2.를 통해 저장한 블럭에 대해 다음을 수행한다.
//- 2.1. 블럭이 이미 지워진 경우, 다음 반복문을 수행한다.
//- 2.2. 블럭에 형태에 대해 각 case별로 is_top() 함수가 참인지 확인한다.
//    - top이 아니면 해당 도형 위에 검은 도형을 쌓을 수 없다.
//- 2.2.1. 1.2.1.에서 언급된 도형에 대해 오른쪽 두개의 블럭이 top인지 확인한다.
//- 2.2.2. 1.2.2.에서 언급된 도형에 대해 양쪽 두개의 블럭이 top인지 확인한다.
//- 2.2.3. 1.2.3.에서 언급된 도형에 대해 왼쪽 두개의 블럭이 top인지 확인한다.
//- 2.2.4. 1.2.4.에서 언급된 도형에 대해 오른쪽 한개의 블럭이 top인지 확인한다.
//- 2.2.5. 1.2.5.에서 언급된 도형에 대해 왼쪽 한개의 블럭이 top인지 확인한다.
//- 2.3. 2.1.의 결과가 참이라면 다음을 수행한다.
//- 2.3.1. 주어진 board 맵에서 도형을 삭제한다.
//- 2.3.2. vector<LOCATE>에서 해당도형을 삭제한다.
//- 2.3.3. 삭제된 블럭이 있는 경우, 2.으로 돌아가 모든 vector<LOCATE>에 대해 다시 수행한다.
//- 3. 모든 블럭이 삭제된 경우 삭제된 블럭의 갯수를 return한다.


#include <iostream>
// Code start

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct LOCATE {
    int id;
    int type;
    vector<pair<int, int>> locate;
    bool is_deleted;
} LOCATE;

LOCATE shape_type(int x, int y, vector<vector<int>> board, int N) {
    LOCATE result;
    result.locate.push_back(make_pair(x, y));

    result.id = board[y][x];
    result.type = -1;
    result.is_deleted = false;

    if (x + 2 < N && y + 1 < N) {
        if (board[y + 1][x] == result.id && board[y + 1][x + 1] == result.id && board[y + 1][x + 2] == result.id) {
            result.locate.push_back(make_pair(x, y + 1));
            result.locate.push_back(make_pair(x + 1, y + 1));
            result.locate.push_back(make_pair(x + 2, y + 1));
            result.type = 1;
        }
    }
    if (x - 1 >= 0 && x + 1 < N && y + 1 < N) {
        if (board[y + 1][x - 1] == result.id && board[y + 1][x] == result.id && board[y + 1][x + 1] == result.id) {
            result.locate.push_back(make_pair(x - 1, y + 1));
            result.locate.push_back(make_pair(x, y + 1));
            result.locate.push_back(make_pair(x + 1, y + 1));
            result.type = 2;
        }
    }
    if (x - 2 >= 0 && y + 1 < N) {
        if (board[y + 1][x - 2] == result.id && board[y + 1][x - 1] == result.id && board[y + 1][x] == result.id) {
            result.locate.push_back(make_pair(x - 2, y + 1));
            result.locate.push_back(make_pair(x - 1, y + 1));
            result.locate.push_back(make_pair(x, y + 1));
            result.type = 3;
        }
    }
    if (x + 1 < N && y + 2 < N) {
        if (board[y + 1][x] == result.id && board[y + 2][x] == result.id && board[y + 2][x + 1] == result.id) {
            result.locate.push_back(make_pair(x, y + 1));
            result.locate.push_back(make_pair(x, y + 2));
            result.locate.push_back(make_pair(x + 1, y + 2));
            result.type = 4;
        }
    }
    if (x - 1 >= 0 && y + 2 < N) {
        if (board[y + 1][x] == result.id && board[y + 2][x] == result.id && board[y + 2][x - 1] == result.id) {
            result.locate.push_back(make_pair(x, y + 1));
            result.locate.push_back(make_pair(x, y + 2));
            result.locate.push_back(make_pair(x - 1, y + 2));
            result.type = 5;
        }
    }

    return result;
}

bool is_top(pair<int, int> target, vector<vector<int>> board) {
    for (int y = target.second - 1; y >= 0; y--) {
        if (board[y][target.first] != 0) return false;
    }

    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();

    unordered_map<int, int> m;
    int m_index = 0;
    vector<LOCATE> vec;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == 0) continue;
            if (m.count(board[y][x]) == 1) continue;
            m.insert({ board[y][x], m_index++ });

            LOCATE temp = shape_type(x, y, board, N);
            if (temp.type == -1) continue;
            vec.push_back(temp);
        }
    }

    bool is_erased = true;
    while (is_erased) {
        is_erased = false;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].is_deleted) continue;
            switch (vec[i].type) {
            case 1:
                if (is_top(vec[i].locate[2], board) && is_top(vec[i].locate[3], board)) {
                    for (int k = 0; k <= 3; k++) {
                        board[vec[i].locate[k].second][vec[i].locate[k].first] = 0;
                    }
                    vec[i].is_deleted = true;
                    answer++;
                    is_erased = true;
                }
                break;
            case 2:
                if (is_top(vec[i].locate[1], board) && is_top(vec[i].locate[3], board)) {
                    for (int k = 0; k <= 3; k++) {
                        board[vec[i].locate[k].second][vec[i].locate[k].first] = 0;
                    }
                    vec[i].is_deleted = true;
                    answer++;
                    is_erased = true;
                }
                break;
            case 3:
                if (is_top(vec[i].locate[1], board) && is_top(vec[i].locate[2], board)) {
                    for (int k = 0; k <= 3; k++) {
                        board[vec[i].locate[k].second][vec[i].locate[k].first] = 0;
                    }
                    vec[i].is_deleted = true;
                    answer++;
                    is_erased = true;
                }
                break;
            case 4:
            case 5:
                if (is_top(vec[i].locate[3], board)) {
                    for (int k = 0; k <= 3; k++) {
                        board[vec[i].locate[k].second][vec[i].locate[k].first] = 0;
                    }
                    vec[i].is_deleted = true;
                    answer++;
                    is_erased = true;
                }
                break;
            }
        }
    }

    return answer;
}

// Code end
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> board;
    board.push_back({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    board.push_back({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    board.push_back({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    board.push_back({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    board.push_back({ 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 });
    board.push_back({ 0, 0, 0, 0, 0, 4, 4, 0, 0, 0 });
    board.push_back({ 0, 0, 0, 0, 3, 0, 4, 0, 0, 0 });
    board.push_back({ 0, 0, 0, 2, 3, 0, 0, 0, 5, 5 });
    board.push_back({ 1, 2, 2, 2, 3, 3, 0, 0, 0, 5 });
    board.push_back({ 1, 1, 1, 0, 0, 0, 0, 0, 0, 5 });

    cout << solution(board);

    return 0;
}