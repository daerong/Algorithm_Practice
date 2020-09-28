//Solution
//- 정렬 후 판단하면 쉽게 해결할 수 있다.
//- 1. Priority queue(이하 pq)에 모든 원소를 push한다. (시간의 오름차순, 인덱스의 오름차순)
//- 2. pq의 top 위치 원소의 time이 t라 할 떄, 다음을 수행한다. (단, t는 이전 삭제된 food의 time과의 차이)
//- 2.1. pq 원소가 없을 경우 -1을 return한다.
//- 2.2. t * pq.size() 값에 따라 다음을 수행한다.
//- 2.2.1. k >= t * pq.size()인 경우, k의 값을 우변의 값 만큼 차감하고 pq에서 t에 해당하는 성분을 제거한다.
//- 2.2.2. k < t * pq.size()인 경우, 마지막 food의 위치를 찾는다.
//- 2.2.2.1. 2.2.2 조건에서는 food의 volume은 변하지 않기 때문에 남은 food의 인덱스를 찾으면 된다.
//- 2.2.2.2. k를 pq.size()로 나눈 나머지가 x일 때, 이는 마지막으로 먹은 food의 위치이다.
//- 2.2.2.3. x를 순차적으로 차감하되 이미 삭제된 food에 대해서는 무시한다.
//- 2.2.2.4. x가 0보다 작아지는 순간의 index를 return한다.


#include <iostream>
// Code start

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct FOOD {
    int index;
    int time;
} FOOD;

bool operator <(FOOD a, FOOD b) {
    if (a.time == b.time) return a.index > b.index;
    else return a.time > b.time;
}

int solution(vector<int> food_times, long long k) {
    bool checked[200001];
    for (int i = 0; i < food_times.size(); i++) checked[i] = false;

    priority_queue<FOOD> pq;
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({ i, food_times[i] });
    }

    long long last_cycle = 0;
    while (!pq.empty()) {
        long long this_cycle = pq.top().time;
        long long food_size = pq.size();
        if (k >= food_size * (this_cycle - last_cycle)) {
            k -= food_size * (this_cycle - last_cycle);
            while (!pq.empty()) {
                if (pq.top().time == this_cycle) {
                    checked[pq.top().index] = true;
                    pq.pop();
                }
                else break;
            }
        }
        else {
            int target = k % pq.size();
            for (int i = 0; i < food_times.size(); i++) {
                if (checked[i]) continue;
                target--;
                if (target < 0) return i + 1;
            }
        }

        last_cycle = this_cycle;
    }

    return -1;
}

// Code end
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> food_times;
    food_times.push_back(3);
    food_times.push_back(1);
    food_times.push_back(2);

    long long k = 5;

    cout << solution(food_times, k);

    return 0;
}