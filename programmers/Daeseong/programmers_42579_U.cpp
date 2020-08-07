//Solution
//- ����� ������ ���� ���� �� �ִ�.
//- 1. Genre�� ���� vector(������ vec)�� ����� �帣�� ���� ���Ѵ�.
//- 2. Genre �ȿ� song�̶�� priority_queue�� ����� song�� ������������ �����Ѵ�.
//- 3. vec�� �������� sort�Ͽ� ū ������� �����Ѵ�.
//- 4. �� Genre���� priority_queue���� ���� �̵� �ִ� 2���� ���� top-pop �����Ѵ�.


#include <string>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct SONG {
    int play;
    int index;
};

typedef struct GENRE {
    string genre;
    int cnt;
    priority_queue<SONG> pq;
};
bool operator <(SONG a, SONG b) {
    return a.play < b.play;
}

vector<GENRE> vec;

bool cmp(GENRE a, GENRE b) {
    return a.cnt > b.cnt;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    for (int i = 0; i < genres.size(); i++) {
        int locate = -1;
        for (int n = 0; n < vec.size(); n++) {
            if (vec[n].genre == genres[i]) {
                locate = n;
                break;
            }
        }

        if (locate == -1) {
            priority_queue<SONG> temp_pq;
            temp_pq.push({ plays[i], i });
            vec.push_back({ genres[i], plays[i], temp_pq });
        }
        else {
            vec[locate].cnt += plays[i];
            vec[locate].pq.push({ plays[i], i });
        }
    }

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < vec.size(); i++) {
        int index = 0;
        SONG temp;
        while (!vec[i].pq.empty()) {
            if (index > 1) break;
            temp = vec[i].pq.top();
            vec[i].pq.pop();
            answer.push_back(temp.index);
            index++;
        }
    }

    return answer;
}