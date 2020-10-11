//Solution
//- �������� �ùķ��̼� ����.
//- ���� �� ���� �ִ��� Ȯ���ϴ� is_top()�Լ��� ������ �� �ִ� ���� ���̽��� �Ǵ��ϴ� shape_type() �Լ��� ����� �����.
//- ����Ǯ�� ������ ������ ����.
//- 1. y�� ������, x�� ������ ������� ��� ���� ��ȸ�ϸ� ������ �����Ѵ�.
//- 1.1. Hashmap�� �̹� üũ�� ���� �� Ȯ���Ѵ�.                  // unordered_map<int, int>
//- 1.1.1. ������ �����ϰ� ���� �ݺ����� ����.
//- 1.1.2. ������ Hashmap�� �ְ� 1.2.�� �����Ѵ�.
//- 1.2. ���� ���̽��� �Ǵ��ϴ� shape_type() �Լ��� �����Ѵ�. 
//    - �̸� ���� ����Ǵ� ���� ���� ���� ���� �׾� ���簢�� ���°� �Ǵ� ������ �� ������ ������ ����.
//- 1.2.1. �������� �� �� |_ ������ ��.
//- 1.2.2. _|_ ������ ��.
//- 1.2.3. ������ �� �� _| ������ ��.
//- 1.2.4. ������ �� �� |_ ������ ��.
//- 1.2.5.������ �� �� _| ������ ��.
//- 1.3. 1.2.���� ã�Ƴ� ���� vector<LOCATE>�� �߰��Ѵ�.          // vector<LOCATE>
//- 2. 1.2.�� ���� ������ ���� ���� ������ �����Ѵ�.
//- 2.1. ���� �̹� ������ ���, ���� �ݺ����� �����Ѵ�.
//- 2.2. ���� ���¿� ���� �� case���� is_top() �Լ��� ������ Ȯ���Ѵ�.
//    - top�� �ƴϸ� �ش� ���� ���� ���� ������ ���� �� ����.
//- 2.2.1. 1.2.1.���� ��޵� ������ ���� ������ �ΰ��� ���� top���� Ȯ���Ѵ�.
//- 2.2.2. 1.2.2.���� ��޵� ������ ���� ���� �ΰ��� ���� top���� Ȯ���Ѵ�.
//- 2.2.3. 1.2.3.���� ��޵� ������ ���� ���� �ΰ��� ���� top���� Ȯ���Ѵ�.
//- 2.2.4. 1.2.4.���� ��޵� ������ ���� ������ �Ѱ��� ���� top���� Ȯ���Ѵ�.
//- 2.2.5. 1.2.5.���� ��޵� ������ ���� ���� �Ѱ��� ���� top���� Ȯ���Ѵ�.
//- 2.3. 2.1.�� ����� ���̶�� ������ �����Ѵ�.
//- 2.3.1. �־��� board �ʿ��� ������ �����Ѵ�.
//- 2.3.2. vector<LOCATE>���� �ش絵���� �����Ѵ�.
//- 2.3.3. ������ ���� �ִ� ���, 2.���� ���ư� ��� vector<LOCATE>�� ���� �ٽ� �����Ѵ�.
//- 3. ��� ���� ������ ��� ������ ���� ������ return�Ѵ�.


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