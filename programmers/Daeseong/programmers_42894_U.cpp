#include <iostream>
// Code start

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define N_MAX 50

vector<int> x_vec[N_MAX];
int N;

typedef struct LOCATE {
    int id;
    int x;
    int y;
    int type;       // -1 : 가로, 1 : 세로
} LOCATE;

bool box_check(LOCATE target) {
    if (x_vec[target.x][target.y] == -1) return false;
    int lineCnt = 0;

    switch (target.type) {
    case -1:
        if (target.y == N - 1) return false;
        if (x_vec[target.x - 1][target.y + 1] == target.id || x_vec[target.x][target.y + 1] == target.id || x_vec[target.x + 1][target.y + 1] == target.id) {
            //cout << "horizon : " << x_vec[target.x - 1][target.y + 1] << ", " << x_vec[target.x][target.y + 1] << ", " << x_vec[target.x + 1][target.y + 1] << endl;

            if (x_vec[target.x - 1][target.y + 1] != -1 && x_vec[target.x - 1][target.y + 1] != target.id) return false;
            if (x_vec[target.x][target.y + 1] != -1 && x_vec[target.x][target.y + 1] != target.id) return false;
            if (x_vec[target.x + 1][target.y + 1] != -1 && x_vec[target.x + 1][target.y + 1] != target.id) return false;

            //cout << "horizon : " << x_vec[target.x - 1][target.y + 1] << ", " << x_vec[target.x][target.y + 1] << ", " << x_vec[target.x + 1][target.y + 1] << endl;

            for (int i = target.y + 1; i >= 0; i--) {
                if (x_vec[target.x - 1][i] == -1) continue;
                else if (x_vec[target.x - 1][i] == target.id) x_vec[target.x - 1][i] = -1;
                else if (x_vec[target.x - 1][i] == 0) x_vec[target.x - 1][i] = -1;
                else break;
            }
            for (int i = target.y + 1; i >= 0; i--) {
                if (x_vec[target.x][i] == -1) continue;
                if (x_vec[target.x][i] == target.id) x_vec[target.x][i] = -1;
                else if (x_vec[target.x][i] == 0) x_vec[target.x][i] = -1;
                else break;
            }
            for (int i = target.y + 1; i >= 0; i--) {
                if (x_vec[target.x + 1][i] == -1) continue;
                if (x_vec[target.x + 1][i] == target.id) x_vec[target.x + 1][i] = -1;
                else if (x_vec[target.x + 1][i] == 0) x_vec[target.x + 1][i] = -1;
                else break;
            }

            return true;
        }
        break;
    case 1:
        int locate = 0;
        if (target.x == N - 1) locate = -1;
        else if (target.x == 0) locate = 1;
        else if (x_vec[target.x - 1][target.y - 1] == target.id || x_vec[target.x - 1][target.y] == target.id || x_vec[target.x - 1][target.y + 1] == target.id) locate = -1;
        else if (x_vec[target.x + 1][target.y - 1] == target.id || x_vec[target.x + 1][target.y] == target.id || x_vec[target.x + 1][target.y + 1] == target.id) locate = 1;

        //cout << "vertical : " << x_vec[target.x + locate][target.y - 1] << ", " << x_vec[target.x + locate][target.y] << ", " << x_vec[target.x + locate][target.y + 1] << endl;

        if (x_vec[target.x + locate][target.y - 1] != -1 && x_vec[target.x + locate][target.y - 1] != target.id) return false;
        if (x_vec[target.x + locate][target.y] != -1 && x_vec[target.x + locate][target.y] != target.id) return false;
        if (x_vec[target.x + locate][target.y + 1] != -1 && x_vec[target.x + locate][target.y + 1] != target.id) return false;

        //cout << "vertical : " << x_vec[target.x + locate][target.y - 1] << ", " << x_vec[target.x + locate][target.y] << ", " << x_vec[target.x + locate][target.y + 1] << endl;

        for (int i = target.y + 1; i >= 0; i--) {
            if (x_vec[target.x][i] == -1) continue;
            if (x_vec[target.x][i] == target.id) x_vec[target.x][i] = -1;
            else if (x_vec[target.x][i] == 0) x_vec[target.x][i] = -1;
            else break;
        }
        for (int i = target.y + 1; i >= 0; i--) {
            if (x_vec[target.x + locate][i] == -1) continue;
            if (x_vec[target.x + locate][i] == target.id) x_vec[target.x + locate][i] = -1;
            else if (x_vec[target.x + locate][i] == 0) x_vec[target.x + locate][i] = -1;
            else break;
        }

        return true;
    }

    return false;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    unordered_map<int, LOCATE> m;
    int m_index = 0;

    N = board.size();

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == 0) continue;
            if (y == 0 || y == N - 1) {
                if (x == 0 || x == N - 1) continue;
                if (board[y][x] == board[y][x - 1] && board[y][x] == board[y][x + 1]) {
                    m.insert({ m_index++, {board[y][x], x, N - 1 - y, -1} });
                }
            }
            else if (x == 0 || x == N - 1) {
                if (y == 0 || y == N - 1) continue;
                if (board[y][x] == board[y - 1][x] && board[y][x] == board[y + 1][x]) {
                    m.insert({ m_index++, {board[y][x], x, N - 1 - y, 1} });
                }
            }
            else {
                if (board[y][x] == board[y][x - 1] && board[y][x] == board[y][x + 1]) {
                    m.insert({ m_index++, {board[y][x], x, N - 1 - y, -1} });
                }
                if (board[y][x] == board[y - 1][x] && board[y][x] == board[y + 1][x]) {
                    m.insert({ m_index++, {board[y][x], x, N - 1 - y, 1} });
                }
            }
        }
    }

    for (int x = 0; x < N; x++) {
        int y_top;
        for (y_top = 0; y_top < N; y_top++) if (board[y_top][x] != 0) break;
        for (int y = N - 1; y >= y_top; y--) x_vec[x].push_back(board[y][x]);
        while (x_vec[x].size() != N) {
            x_vec[x].push_back(-1);
        }
    }

    //for (int i = 0; i < m_index; i++) {
    //    cout << m[i].id << ", " << m[i].x << ", " << m[i].y << ", " << m[i].type << endl;
    //}

    bool is_change = true;
    while (is_change) {
        is_change = false;
        for (int i = 0; i < m_index; i++) {
            if (box_check(m[i])) {
                is_change = true;
                answer++;
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