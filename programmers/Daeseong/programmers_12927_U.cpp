#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    works.push_back(0);
    sort(works.begin(), works.end(), greater<int>());
    int height = works[0];
    int width;
    int sumArea = 0;

    for (width = 1; width < works.size(); width++) {
        if (height == works[width]) continue;
        sumArea += width * (height - works[width]);
        height = works[width];
        if (sumArea >= n) break;
    }
    works.pop_back();

    if (n > sumArea) return 0;

    int add_height = (sumArea - n) / width;
    int divide_width = (sumArea - n) % width;

    int factor;
    for (int i = 0; i < width; i++) {
        factor = height + add_height;
        if (i < divide_width) answer += (factor + 1) * (factor + 1);
        else answer += factor * factor;
    }

    for (int i = width; i < works.size(); i++) {
        answer += works[i] * works[i];
    }

    return answer;
}