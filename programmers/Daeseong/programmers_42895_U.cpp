#include <string>
#include <unordered_map>
#include <algorithm>

#define CNT_MAX 8

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;
    if (number <= 1) return 2;

    unordered_map<int, bool> dp[CNT_MAX + 1];
    dp[1].insert({ N, true });
    int temp = N;
    for (int i = 2; i <= CNT_MAX; i++) {
        temp = temp * 10 + N;
        dp[i].insert({ temp, true });
    }

    for (int cnt = 2; cnt <= 8; cnt++) {
        for (int num1 = 1; num1 <= cnt / 2; num1++) {
            int num2 = cnt - num1;
            for (unordered_map<int, bool>::iterator it1 = dp[num1].begin(); it1 != dp[num1].end(); it1++) {
                int temp;
                for (unordered_map<int, bool>::iterator it2 = dp[num2].begin(); it2 != dp[num2].end(); it2++) {
                    temp = it1->first + it2->first;
                    if (temp == number) return cnt;
                    if (dp[cnt].count(temp) == 0) dp[cnt].insert({ temp, true });
                    temp = abs(it1->first - it2->first);
                    if (temp == number) return cnt;
                    if (dp[cnt].count(temp) == 0) dp[cnt].insert({ temp, true });
                    /*temp = it1->first - it2->first;
                    if (temp == number) return cnt;
                    if (dp[cnt].count(temp) == 0) dp[cnt].insert({ temp, true });
                    temp = it2->first - it1->first;
                    if (temp == number) return cnt;
                    if (dp[cnt].count(temp) == 0) dp[cnt].insert({ temp, true });*/
                    temp = it1->first * it2->first;
                    if (temp == number) return cnt;
                    if (dp[cnt].count(temp) == 0) dp[cnt].insert({ temp, true });
                    if (temp == 0) continue;
                    if (it1->first >= it2->first) temp = it1->first / it2->first;
                    else temp = it2->first / it1->first;
                    if (temp == number) return cnt;
                    if (dp[cnt].count(temp) == 0) dp[cnt].insert({ temp, true });
                }
            }
        }
    }

    return -1;
}