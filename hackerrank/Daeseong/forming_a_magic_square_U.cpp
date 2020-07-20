// The magic square has 8 shapes.
// So we find the diffrence between 8 cases and given one.
// If you print the smallest of 8 cases, you can pass this problem.

#include <iostream>
#include <algorithm>

using namespace std;

int magic_squares[8][3][3] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
};

int arr[3][3];

void input() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cin >> arr[y][x];
        }
    }
}

int solution(int n) {
    int sum = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            sum += abs(magic_squares[n][y][x] - arr[y][x]);
        }
    }
    return sum;
}

void solve() {
    input();
    int result = 1000000000;
    for (int n = 0; n < 8; n++) {
        result = min(result, solution(n));
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}