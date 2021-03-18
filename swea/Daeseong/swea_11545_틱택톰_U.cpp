//Solution
//- ��Ʈ����ũ�� �̿��� Ǯ��.
//- 2^16 = 65536���� ��Ʈ����ŷ ����.
//�̷��� ����
//1. X�� T�� �ϳ���, O�� T�� �� �ٸ� �ϳ��� ���� ��ġ�� ��´�.
//2. LOCATE = LOCATE | (1 << Y * 4 + X)�� ��ġ�� ������ �� �ִ�.
//3. �¸��� �� �ִ� ���̽��� ���� 4, ���� 4, �밢 2 �� 10���� ����̴�.
//4. �� ���̽��� ���� �����Ͽ� �����ϸ� X or O �¸�.
//5. mapX | map O == 65535�̸� "Draw"
//6. �� ���� ���, "Game has not completed"
//Ǯ�� ����
//1. ���� ����
//1.1. int mapX : X�� T�� ��ġ ���
//1.2. int mapO : Y�� T�� ��ġ ���
//1.3. vector<int> winFactor : ������ ��� �¸�����
//2. winFactor�� setting.
//3. winFactor & mapX, winFactor * mapO�� Ȯ��.
//3.1. ���� ���, "X won" �Ǵ� "O won" ���
//4. mapX | map O == 65535�̸� "Draw" ���
//5. �� ���� ���, "Game has not completed"

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