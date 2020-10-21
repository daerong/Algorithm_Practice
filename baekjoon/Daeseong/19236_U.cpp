#include <iostream>
#include <vector>
#include <algorithm>

#define SHARK -2
#define N_MAX 4

typedef struct MAP {
    int index;
    int dir;
} MAP;

typedef struct FISH {
    int x;
    int y;
} FISH;

using namespace std;

// ¡è, ¢Ø, ¡ç, ¢×, ¡é, ¢Ù, ¡æ, ¢Ö
const int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void input(vector<FISH>& fishes, vector<vector<MAP>>& map) {
    for (int i = 0; i <= 16; i++) fishes.push_back({ -1, -1 });
    for (int y = 0; y < N_MAX; y++) {
        vector<MAP> line;
        for (int x = 0; x < N_MAX; x++) {
            MAP temp;
            cin >> temp.index >> temp.dir;
            temp.dir -= 1;
            line.push_back(temp);

            fishes[temp.index] = { x, y };
        }
        map.push_back(line);
    }
}

void moveFishs(vector<vector<MAP>>& map, vector<FISH>& fishes) {
    for (int i = 1; i <= 16; i++) {
        if (fishes[i].y == -1) continue;
        FISH* fish;
        FISH* nFish;
        fish = &fishes[i];

        MAP* block1 = &map[fish->y][fish->x];
        MAP* block2 = nullptr;

        int nx, ny;
        for (int dir = 0; dir < 8; dir++) {
            nx = fish->x + dx[block1->dir];
            ny = fish->y + dy[block1->dir];
            if (ny < 0 || ny >= N_MAX || nx < 0 || nx >= N_MAX || map[ny][nx].index == SHARK) {
                block1->dir = (block1->dir + 1) % 8;
                continue;
            }

            // MAP swap()
            block2 = &map[ny][nx];
            MAP block_temp = map[ny][nx];
            *block2 = *block1;
            *block1 = block_temp;

            // FISH swap()
            nFish = &fishes[block_temp.index];
            *nFish = *fish;
            *fish = { nx, ny };

            break;
        }
    }
}


int dfs(int x, int y, vector<vector<MAP>> map, vector<FISH> fishes) {
    int answer = 0;

    moveFishs(map, fishes);

    int fishFirst, fishSecond;
    int boardFirst;

    for (int i = 1; i <= 3; i++) {
        int ny = y + dy[map[y][x].dir] * i;
        int nx = x + dx[map[y][x].dir] * i;
        if (ny < 0 || ny >= N_MAX || nx < 0 || nx >= N_MAX) break;
        if (map[ny][nx].index == 0) continue;


        fishFirst = fishes[map[ny][nx].index].y;
        fishSecond = fishes[map[ny][nx].index].x;
        fishes[map[ny][nx].index] = { -1, -1 };
        boardFirst = map[ny][nx].index;
        map[ny][nx].index = SHARK;
        map[y][x].index = 0;

        answer = max(answer, dfs(nx, ny, map, fishes) + boardFirst);

        map[y][x].index = SHARK;
        map[ny][nx].index = boardFirst;
        fishes[map[ny][nx].index] = { fishSecond, fishFirst };

    }


    return answer;
}

int main() {
    vector<FISH> fishes;
    vector<vector<MAP>> map;
    input(fishes, map);

    int temp = map[0][0].index;
    fishes[map[0][0].index] = { -1, -1 };
    map[0][0].index = SHARK;

    cout << dfs(0, 0, map, fishes) + temp;

    return 0;
}