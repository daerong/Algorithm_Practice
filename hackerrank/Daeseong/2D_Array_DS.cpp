#include <iostream>
#include <vector>

using namespace std;

/*

*/

int hourglassSum(vector<vector<int>> arr) {
    int X, Y;
    int maxValue = -99999999;
    Y = arr.size();
    X = arr[0].size();
    for (int y = 1; y < Y - 1; y++) {
        for (int x = 1; x < X - 1; x++) {
            maxValue = max(maxValue, arr[y - 1][x - 1] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y][x] + arr[y + 1][x - 1] + arr[y + 1][x] + arr[y + 1][x + 1]);
        }
    }

    return maxValue;
}