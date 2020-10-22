#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SHARK -2
#define N_MAX 4

typedef struct MAP {
    int index;
    int dir;
} MAP;

typedef struct FISH {
    int x;
    int y;
    bool is_dead;
} FISH;

// ¡è, ¢Ø, ¡ç, ¢×, ¡é, ¢Ù, ¡æ, ¢Ö
const int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

MAP* shark;

void input(vector<FISH>& fishes, vector<vector<MAP>>& map) {
    for (int i = 0; i <= 16; i++) fishes.push_back({ -1, -1, false });
    for (int y = 0; y < N_MAX; y++) {
        vector<MAP> line;
        for (int x = 0; x < N_MAX; x++) {
            MAP temp;
            cin >> temp.index >> temp.dir;
            temp.dir -= 1;
            line.push_back(temp);

            fishes[temp.index] = { x, y, false };
        }
        map.push_back(line);
    }
}

void moveFishs(vector<vector<MAP>>& map, vector<FISH>& fishes) {
    for (int i = 1; i <= 16; i++) {
        if (fishes[i].is_dead) continue;
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

    MAP* origin = &map[y][x];
    FISH fish;

    for (int i = 1; i <= 3; i++) {
        int ny = y + dy[origin->dir] * i;
        int nx = x + dx[origin->dir] * i;
        if (ny < 0 || ny >= N_MAX || nx < 0 || nx >= N_MAX) break;
        if (map[ny][nx].index == 0) continue;


        MAP* target = &map[ny][nx];
        fish = fishes[target->index];
        fishes[target->index].is_dead = true;

        MAP temp = *target;
        target->index = SHARK;
        origin->index = 0;

        answer = max(answer, dfs(nx, ny, map, fishes) + temp.index);

        origin->index = SHARK;
        target->index = temp.index;

        fishes[target->index] = fish;
    }


    return answer;
}

int main() {
    vector<FISH> fishes;
    vector<vector<MAP>> map;
    input(fishes, map);

    int answer = map[0][0].index;

    fishes[map[0][0].index].is_dead = true;
    map[0][0].index = SHARK;

    answer += dfs(0, 0, map, fishes);

    cout << answer;

    return 0;
}