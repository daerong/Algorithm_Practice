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

    if (x + 2 < N && y + 1 < N) {
        if (board[x][y + 1] == result.id || board[x + 1][y + 1] == result.id || board[x + 2][y + 1] == result.id) {
            result.locate.push_back(make_pair(x, y + 1));
            result.locate.push_back(make_pair(x + 1, y + 1));
            result.locate.push_back(make_pair(x + 2, y + 1));
            result.type = 1;
        }
    }
    else if (x - 1 >= 0 && x + 1 < N && y + 1 < N) {
        if (board[x - 1][y + 1] == result.id || board[x][y + 1] == result.id || board[x + 1][y + 1] == result.id) {
            result.locate.push_back(make_pair(x - 1, y + 1));
            result.locate.push_back(make_pair(x, y + 1));
            result.locate.push_back(make_pair(x + 1, y + 1));
            result.type = 2;
        }
    }
    else if (x - 2 >= 0 && y + 1 < N) {
        if (board[x - 2][y + 1] == result.id || board[x - 1][y + 1] == result.id || board[x][y + 1] == result.id) {
            result.locate.push_back(make_pair(x - 2, y + 1));
            result.locate.push_back(make_pair(x - 1, y + 1));
            result.locate.push_back(make_pair(x, y + 1));
            result.type = 3;
        }
    }
    else if (x + 1 < N && y + 2 < N) {
        if (board[x][y + 1] == result.id || board[x][y + 2] == result.id || board[x + 1][y + 2] == result.id) {
            result.locate.push_back(make_pair(x, y + 1));
            result.locate.push_back(make_pair(x, y + 2));
            result.locate.push_back(make_pair(x + 1, y + 2));
            result.type = 4;
        }
    }
    else if (x - 1 >= 0 && y + 2 < N) {
        if (board[x][y + 1] == result.id || board[x][y + 2] == result.id || board[x - 1][y + 2] == result.id) {
            result.locate.push_back(make_pair(x, y + 1));
            result.locate.push_back(make_pair(x, y + 2));
            result.locate.push_back(make_pair(x - 1, y + 2));
            result.type = 5;
        }
    }

    return result;
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

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].id << ", " << vec[i].type << " : ";
        for (int j = 0; j < vec[i].locate.size(); j++) {
            cout << "(" << vec[i].locate[j].first << ", " << vec[i].locate[j].second << ") ";
        }

        cout << endl;
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