//Solution
//- ������ ��Ȳ�� �´� ����� ����ϸ� �ȴ�.
//- 0. �־��� string �迭�� �����Ѵ�.
//- 1. �� ������ �ִ� m���� ����� �¿��.
//- 1-1. queue�� ���� �ջ���� ���� �����ð����� �۰ų� ���� ��� queue���� ����.
//- 1-2. ū ��� ������ �׳� ��������.
//- 1-3. queue�� ����ִ� ��� ���� �ð��� �����Ѵ�.
//- 2. ������ ������ �������ٸ� ��Ȳ���� �Ʒ� ����� �����Ѵ�.
//- 2-1. ������ ������ ���� queue�� front���� �������, ���� �ð��� �����Ѵ�.
//- 2-2. ������ ������ ���� queue�� front���� �۰ų� ���� ��� �� �°����� 1�� ���� �ð��� �����Ѵ�.


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string timeUp(string str, int up) {
    str[4] += up % 10;
    str[3] += up / 10;
    if (str[4] > '9') {
        str[3] += 1;
        str[4] -= 10;
    }
    if (str[3] >= '6') {
        str[1] += 1;
        str[3] -= 6;
    }
    if (str[1] > '9') {
        str[0] += 1;
        str[1] -= 10;
    }

    return str;
}

string timeDown(string str) {
    str[4] -= 1;
    if (str[4] < '0') {
        str[3] -= 1;
        str[4] += 10;
    }
    if (str[3] < '0') {
        str[1] -= 1;
        str[3] += 6;
    }
    if (str[1] < '0') {
        str[0] -= 1;
        str[1] += 10;
    }

    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "09:00";

    sort(timetable.begin(), timetable.end());
    queue<string, deque<string>> q(deque<string>(timetable.begin(), timetable.end()));

    string lastP;
    string lastB;
    for (int bus = 1; bus <= n; bus++) {
        if (answer > "23:59") return "23:59";
        for (int man = 1; man <= m; man++) {
            if (q.empty()) return answer;

            lastP = q.front();
            if (answer < lastP) break;
            q.pop();
        }

        lastB = answer;
        answer = timeUp(answer, t);
    }

    if (lastB < lastP) return lastB;
    else return timeDown(lastP);
}

//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n = 60;      // ȸ
//    int t = 60;      // ����(��)
//    int m = 1;      // ���
//    vector<string> timetable;
//    timetable.push_back("00:09");
//    timetable.push_back("00:10");
//    timetable.push_back("00:11");
//    timetable.push_back("00:12");
//    timetable.push_back("00:13");
//    timetable.push_back("00:14");
//    timetable.push_back("00:15");
//    timetable.push_back("00:16");
//    timetable.push_back("00:17");
//    timetable.push_back("00:18");
//    timetable.push_back("00:19");
//    timetable.push_back("00:20");
//    timetable.push_back("00:21");
//    timetable.push_back("00:22");
//    timetable.push_back("00:23");
//    timetable.push_back("00:24");
//    timetable.push_back("00:25");
//    timetable.push_back("00:26");
//    timetable.push_back("00:27");
//    timetable.push_back("00:28");
//    timetable.push_back("00:29");
//    timetable.push_back("00:30");
//    timetable.push_back("00:31");
//    timetable.push_back("00:32");
//
//    //int n = 2;      // ȸ
//    //int t = 1;      // ����(��)
//    //int m = 2;      // ���
//    //vector<string> timetable;
//    //timetable.push_back("08:00");
//    //timetable.push_back("08:00");
//    //timetable.push_back("08:00");
//    //timetable.push_back("09:00");
//    //timetable.push_back("09:05");
//
//    //int n = 1;      // ȸ
//    //int t = 1;      // ����(��)
//    //int m = 5;      // ���
//    //vector<string> timetable;
//    //timetable.push_back("08:00");
//    //timetable.push_back("08:01");
//    //timetable.push_back("08:02");
//    //timetable.push_back("08:03");
//
//    cout << solution(n, t, m, timetable);
//
//    return 0;
//}