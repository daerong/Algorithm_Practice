//Solution
//= 비트연산을 통해 결과를 쉽게 얻어낼 수 있다.
//- 1. arr1과 arr2의 or연산으로 겹쳤을 때의 결과를 얻어낸다.
//- 2. 각 비트를 확인해 1인경우 #을 0인경우 공백으로 구성한다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    int result;
    for (int y = 0; y < n; y++) {
        result = arr1[y] | arr2[y];

        string str;
        for (int x = n - 1; x >= 0; x--) {
            if ((1 << x) & result) str += '#';
            else str += ' ';
        }

        answer.push_back(str);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 5;
    vector<int> arr1;
    arr1.push_back(9);
    arr1.push_back(20);
    arr1.push_back(28);
    arr1.push_back(18);
    arr1.push_back(11);
    vector<int> arr2;
    arr2.push_back(30);
    arr2.push_back(1);
    arr2.push_back(21);
    arr2.push_back(17);
    arr2.push_back(28);

    solution(n, arr1, arr2);

    return 0;
}