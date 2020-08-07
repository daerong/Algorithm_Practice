//Solution
//- 결과는 다음과 같이 구할 수 있다.
//- 1. Genre에 대한 vector(변수명 vec)를 만들어 장르별 합을 구한다.
//- 2. Genre 안에 song이라는 priority_queue를 만들어 song을 내림차순으로 저장한다.
//- 3. vec을 내림차순 sort하여 큰 순서대로 정렬한다.
//- 4. 각 Genre별로 priority_queue에서 곡을 뽑되 최대 2개의 곡을 top-pop 수행한다.


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