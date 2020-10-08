//Solution
//- ������ �±� ó���� ������ϴ� ���� �־��� ����.
//- Ǯ�� �� ������� �κ� ���
//- 1. <head>, </head>, <body>, </body>�� ã�Ƽ� �߶󳻾� Ǯ�̰� ��.
//- 2. "<meta property=\"og:url\"" �̰� ���� ã�� �߶󳻰� "content=\"https://" �̰� ã�ƾ� ��밡��
//- 3. �˻��� �˻��ÿ� �յڷ� ��, �ҹ��ڰ� �̾����� �ȵ�.
//- Ǯ�̰����� ������ ����.
//- 1. �� pages���� ������ �����Ѵ�.
//- 1-1. content�� �ش��ϴ� �ּҸ� �޾� Hashmap�� �����Ѵ�. string -> index                      (INDEX)
//- 1-2. body ���� link�� �ش��ϴ� string�� ��� vector�� �����Ѵ�.                              (LINK_CNT)
//- 1-3. body ���� �˻�� �ִ� �� Ȯ���Ѵ�. ��ҹ��� ��������Ƿ� toupper, tolower�� �����.   (SEARCH_CNT)
//- 2. ��(INDEX)�� ���� vector�� ����� link�� Ȯ���Ѵ�.
//- 2-1. Hashmap�� �ش� link�� �ִ� �� Ȯ���Ѵ�.
//- 2-2. link�� �ִ� ���, �ش� index�� (ANSWER_ARR)�� (SEARCH_CNT) / (LINK_CNT)�� ���Ѵ�.         (ANSWER_ARR)
//- 3. ��(INDEX)�� �ش��ϴ� (ANSWER_ARR)�� (SEARCH_CNT)�� ���Ѵ�.
//- 4. (ANSWER_ARR)�� �ִ밪�� �ش��ϴ� (INDEX)�� �����Ѵ�.

#include <iostream>
// Code start

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define ARR_MAX 20
#define HEAD_TAG_S "<head>"
#define HEAD_TAG_E "</head>"
#define PROPERTY_TAG "<meta property=\"og:url\""
#define CONTENT_TAG_S "content=\"https://"
#define CONTENT_TAG_E "\"/>"
#define BODY_TAG_S "<body>"
#define BODY_TAG_E "</body>"
#define HREF_TAG_S "<a href=\"https://"
#define HREF_TAG_F "\">"
#define HREF_TAG_E "</a>"

int solution(string word, vector<string> pages) {
    int answer = 0;

    string lower_case = word;
    string upper_case = word;
    for (int i = 0; i < word.length(); i++) {
        lower_case[i] = tolower(lower_case[i]);
        upper_case[i] = toupper(upper_case[i]);
    }

    unordered_map<string, int> m;
    int m_index = 0;

    string str;

    vector<string> links[ARR_MAX];
    int cnt[ARR_MAX];
    for (int i = 0; i < ARR_MAX; i++) cnt[i] = 0;

    for (int i = 0; i < pages.size(); i++) {
        str = pages[i];

        if (str.find(HEAD_TAG_S) != string::npos) {
            string head_tag_s = HEAD_TAG_S;
            str = str.substr(str.find(HEAD_TAG_S) + head_tag_s.length());

            if (str.find(PROPERTY_TAG) != string::npos) {
                string property_tag = PROPERTY_TAG;
                str = str.substr(str.find(PROPERTY_TAG) + property_tag.length());
            }

            if (str.find(CONTENT_TAG_S) != string::npos) {
                string content_tag_s = CONTENT_TAG_S;
                string content_tag_e = CONTENT_TAG_E;
                int start = str.find(CONTENT_TAG_S) + content_tag_s.length();
                int end = str.find(CONTENT_TAG_E);
                string target = str.substr(start, end - start);

                m.insert({ target , m_index++ });

                str = str.substr(end + content_tag_e.length());
            }

            if (str.find(HEAD_TAG_E) != string::npos) {
                string head_tag_e = HEAD_TAG_E;
                str = str.substr(str.find(HEAD_TAG_E) + head_tag_e.length());
            }
        }

        if (str.find(BODY_TAG_S) != string::npos) {
            string body_tag_s = BODY_TAG_S;
            str = str.substr(str.find(BODY_TAG_S) + body_tag_s.length(), str.find(BODY_TAG_E) - (str.find(BODY_TAG_S) + body_tag_s.length()));
        }

        string inner_str = str;

        while (inner_str.find(HREF_TAG_S) != string::npos) {
            string href_tag_s = HREF_TAG_S;
            string href_tag_f = HREF_TAG_F;
            int start = inner_str.find(HREF_TAG_S) + href_tag_s.length();
            int end = inner_str.find(HREF_TAG_F);
            string target = inner_str.substr(start, end - start);

            links[i].push_back(target);

            inner_str = inner_str.substr(end + href_tag_f.length());

            string href_tag_e = HREF_TAG_E;
            inner_str = inner_str.substr(inner_str.find(HREF_TAG_E) + href_tag_e.length());
        }

        while (str.length() != 0) {
            if (str[0] == '<') {
                int index = 1;
                while (str[index] != '>') index++;
                str = str.substr(index + 1);
            }
            else if (str[0] == lower_case[0] || str[0] == upper_case[0]) {
                if (str.length() >= word.length()) {
                    bool is_same = true;
                    int locate;
                    for (locate = 1; locate < word.length(); locate++) {
                        if (str[locate] != lower_case[locate] && str[locate] != upper_case[locate]) {
                            is_same = false;
                            break;
                        }
                    }

                    if (is_same) {
                        if (str[locate] >= 'A' && str[locate] <= 'Z') is_same = false;
                        else if (str[locate] >= 'a' && str[locate] <= 'z') is_same = false;
                        else cnt[i] += 1;
                    }

                    if (!is_same) {
                        for (locate; locate < str.length(); locate++) {
                            if (str[locate] >= 'A' && str[locate] <= 'Z') {}
                            else if (str[locate] >= 'a' && str[locate] <= 'z') {}
                            else break;
                        }

                        str = str.substr(locate);
                    }
                    else {
                        str = str.substr(locate + 1);
                    }

                }
                else break;
            }
            else if (str[0] >= 'a' && str[0] <= 'z') {
                if (str.length() >= word.length()) {
                    bool is_same = true;
                    int locate;
                    for (locate = 1; locate < word.length(); locate++) {
                        if (str[locate] != lower_case[locate] || str[locate] != upper_case[locate]) {
                            is_same = false;
                            break;
                        }
                    }

                    if (is_same) {
                        if (str[locate] >= 'A' && str[locate] <= 'Z') is_same = false;
                        else if (str[locate] >= 'a' && str[locate] <= 'z') is_same = false;
                        else cnt[i] += 1;
                    }

                    if (!is_same) {
                        for (locate; locate < str.length(); locate++) {
                            if (str[locate] >= 'A' && str[locate] <= 'Z') {}
                            else if (str[locate] >= 'a' && str[locate] <= 'z') {}
                            else break;
                        }

                        str = str.substr(locate);
                    }
                    else {
                        str = str.substr(locate + 1);
                    }

                }
                else break;
            }
            else str = str.substr(1);
        }

        //cout << cnt[i] << ", " << links[i].size() << endl;
    }

    float scores[ARR_MAX];
    for (int i = 0; i < m_index; i++) scores[i] = cnt[i];

    for (int i = 0; i < m_index; i++) {
        for (int n = 0; n < links[i].size(); n++) {
            if (m.count(links[i][n]) == 1) {
                if (links[i].size() == 0) continue;
                scores[m[links[i][n]]] += (float)cnt[i] / links[i].size();
            }
        }
    }

    float max_score = scores[0];

    for (int i = 1; i < m_index; i++) {
        if (max_score < scores[i]) {
            max_score = scores[i];
            answer = i;
        }
    }

    return answer;
}

// Code end
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word = "blind";
    vector<string> pages;
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nblind lorem blind ipsum dolor blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> link to b </a>\n</body>\n</html>");
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nsuspendisse potenti. vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> link to a </a>\nblind sed congue urna varius. suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> link to c </a>\n</body>\n</html>");;
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nut condimentum urna at felis sodales rutrum. sed dapibus cursus diam, non interdum nulla tempor nec. phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> link to a </a>\n</body>\n</html>");

    //string word = "Muzi";
    //vector<string> pages;
    //pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>");
    //pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>");

    cout << solution(word, pages);

    return 0;
}