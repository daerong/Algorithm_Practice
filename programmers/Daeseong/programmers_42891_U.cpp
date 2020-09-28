//Solution
//- ���� �� �Ǵ��ϸ� ���� �ذ��� �� �ִ�.
//- 1. Priority queue(���� pq)�� ��� ���Ҹ� push�Ѵ�. (�ð��� ��������, �ε����� ��������)
//- 2. pq�� top ��ġ ������ time�� t�� �� ��, ������ �����Ѵ�. (��, t�� ���� ������ food�� time���� ����)
//- 2.1. pq ���Ұ� ���� ��� -1�� return�Ѵ�.
//- 2.2. t * pq.size() ���� ���� ������ �����Ѵ�.
//- 2.2.1. k >= t * pq.size()�� ���, k�� ���� �캯�� �� ��ŭ �����ϰ� pq���� t�� �ش��ϴ� ������ �����Ѵ�.
//- 2.2.2. k < t * pq.size()�� ���, ������ food�� ��ġ�� ã�´�.
//- 2.2.2.1. 2.2.2 ���ǿ����� food�� volume�� ������ �ʱ� ������ ���� food�� �ε����� ã���� �ȴ�.
//- 2.2.2.2. k�� pq.size()�� ���� �������� x�� ��, �̴� ���������� ���� food�� ��ġ�̴�.
//- 2.2.2.3. x�� ���������� �����ϵ� �̹� ������ food�� ���ؼ��� �����Ѵ�.
//- 2.2.2.4. x�� 0���� �۾����� ������ index�� return�Ѵ�.


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