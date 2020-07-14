#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr1[1000000];
int arr2[1000000];

int solution(vector<int> money) {
    int answer = 0;

    int N = money.size();

    arr1[0] = money[0];
    arr2[0] = 0;
    arr1[1] = money[1];
    arr2[1] = money[1];
    arr1[2] = money[2] + arr1[0];
    arr2[2] = money[2] + arr2[0];

    for (int i = 3; i < N; i++) {
        arr1[i] = money[i] + max(arr1[i - 2], arr1[i - 3]);
        arr2[i] = money[i] + max(arr2[i - 2], arr2[i - 3]);
    }

    arr1[N - 1] -= money[N - 1];

    answer = max(max(arr1[N - 2], arr1[N - 1]), max(arr2[N - 2], arr2[N - 1]));

    return answer;
}