//Solution
//= ��Ʈ������ ���� ����� ���� �� �� �ִ�.
//- 1. arr1�� arr2�� or�������� ������ ���� ����� ����.
//- 2. �� ��Ʈ�� Ȯ���� 1�ΰ�� #�� 0�ΰ�� �������� �����Ѵ�.

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