#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    sort(works.begin(), works.end(), greater<int>());
    
    int last_time = works[0];
    int summation = 0;
    int location;
    for (location = 1; location < works.size(); location++) {
        if (last_time == works[location]) continue;
        summation += location * (last_time - works[location]);
        last_time = works[location];
        if (summation >= n) break;
    }

    int add_height = (summation - n) / location;
    int term = (summation - n) % location;

    for (int i = 0; i < location; i++) {
        if (i < term) works[i] = last_time + add_height + 1;
        else works[i] = last_time + add_height;
    }
    
    long long answer = 0;
    for (int i = 0; i < works.size(); i++) {
        if (works[i] < 0) {
            answer = 0;
            break;
        }
        answer += pow(works[i], 2.0);
    }

    return answer;
}