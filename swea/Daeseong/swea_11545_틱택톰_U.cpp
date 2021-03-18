//Solution
//- 비트마스크를 이용한 풀이.
//- 2^16 = 65536으로 비트마스킹 가능.
//이론적 접근
//1. X와 T를 하나로, O와 T를 또 다른 하나로 정해 위치를 담는다.
//2. LOCATE = LOCATE | (1 << Y * 4 + X)로 위치를 지정할 수 있다.
//3. 승리할 수 있는 케이스는 가로 4, 세로 4, 대각 2 총 10가지 경우이다.
//4. 각 케이스에 대해 대입하여 성립하면 X or O 승리.
//5. mapX | map O == 65535이면 "Draw"
//6. 그 외의 경우, "Game has not completed"
//풀이 과정
//1. 변수 선언
//1.1. int mapX : X와 T의 위치 기록
//1.2. int mapO : Y와 T의 위치 기록
//1.3. vector<int> winFactor : 가능한 모든 승리조건
//2. winFactor를 setting.
//3. winFactor & mapX, winFactor * mapO를 확인.
//3.1. 있을 경우, "X won" 또는 "O won" 출력
//4. mapX | map O == 65535이면 "Draw" 출력
//5. 그 외의 경우, "Game has not completed"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAP_MAX 65535

int mapX;
int mapO;

vector<int> winFactor;

void init() {
    mapX = 0;
    mapO = 0;

    char temp;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cin >> temp;
            switch (temp) {
            case '.':
                break;
            case 'X':
                mapX |= 1 << (y * 4 + x);
                break;
            case 'O':
                mapO |= 1 << (y * 4 + x);
                break;
            case 'T':
                mapX |= 1 << (y * 4 + x);
                mapO |= 1 << (y * 4 + x);
                break;
            }
        }
    }
}

int solution() {
    for (vector<int>::iterator it = winFactor.begin(); it != winFactor.end(); it++) {
        if (*it == (mapX & *it)) return 1;
        else if (*it == (mapO & *it)) return 2;
    }

    if ((mapX | mapO) == MAP_MAX) return 0;
    return -1;
}

void solve() {
    int TC;
    cin >> TC;
    string result;
    for (int tc = 1; tc <= TC; tc++) {
        init();
        switch (solution()) {
        case 1:
            result = "X won";
            break;
        case 2:
            result = "O won";
            break;
        case 0:
            result = "Draw";
            break;
        case -1:
            result = "Game has not completed";
            break;
        }
        cout << "#" << tc << " " << result << endl;
    }
}

void winFactor_setting() {
    int ySet = (1 << 0) | (1 << 4) | (1 << 8) | (1 << 12);
    int xSet = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
    for (int i = 0; i < 4; i++) {
        winFactor.push_back(ySet);
        winFactor.push_back(xSet);
        ySet = ySet << 1;
        xSet = xSet << 4;
    }
    int cross = (1 << 0) | (1 << 5) | (1 << 10) | (1 << 15);
    winFactor.push_back(cross);
    cross = (1 << 3) | (1 << 6) | (1 << 9) | (1 << 12);
    winFactor.push_back(cross);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    winFactor_setting();
    solve();

    return 0;
}