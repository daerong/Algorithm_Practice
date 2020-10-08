#include <iostream>
// Code start

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define PROPERTY_TAG "property=\"og:url\""
#define CONTENT_TAG_S "content=\"https://"
#define CONTENT_TAG_E "\"/>"
#define BODY_TAG "<body>"
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

    vector<string> links[20];
    int cnt[20];
    for (int i = 0; i < 20; i++) cnt[i] = 0;

    for (int i = 0; i < pages.size(); i++) {
        str = pages[i];

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

        if (str.find(BODY_TAG) != string::npos) {
            string body_tag = BODY_TAG;
            str = str.substr(str.find(BODY_TAG) + body_tag.length());
        }

        int search_cnt = 0;
        bool is_connect = false;
        while (str.length() != 0) {
            if (str[0] == '<') {
                bool is_href = true;
                string href_s = HREF_TAG_S;

                if (href_s.length() > str.length()) break;
                for (int locate = 0; locate < href_s.length(); locate++) {
                    if (href_s[locate] != str[locate]) {
                        is_href = false;
                        break;
                    }
                }

                if (is_href) {
                    string href_tag_s = HREF_TAG_S;
                    string href_tag_f = HREF_TAG_F;
                    int start = str.find(HREF_TAG_S) + href_tag_s.length();
                    int end = str.find(HREF_TAG_F);
                    string target = str.substr(start, end - start);

                    links[i].push_back(target);

                    str = str.substr(end + href_tag_f.length());

                    string href_tag_e = HREF_TAG_E;
                    str = str.substr(str.find(HREF_TAG_E) + href_tag_e.length());
                }
                else {
                    str = str.substr(1);
                }
            }
            else {
                if (is_connect) {
                    if (str[0] >= 'A' && str[0] <= 'Z') {}
                    else if (str[0] >= 'a' && str[0] <= 'z') {}
                    else {
                        is_connect = false;
                        search_cnt = 0;
                    }
                }
                else {
                    if (str[0] == lower_case[search_cnt] || str[0] == upper_case[search_cnt]) search_cnt++;
                    else {
                        if (str[0] >= 'A' && str[0] <= 'Z') is_connect = true;
                        else if (str[0] >= 'a' && str[0] <= 'z') is_connect = true;
                        else {}

                        search_cnt = 0;
                    }

                    if (search_cnt == word.length()) {
                        if (str[1] >= 'A' && str[1] <= 'Z') {
                            is_connect = true;
                            search_cnt = 0;
                        }
                        else if (str[1] >= 'a' && str[1] <= 'z') {
                            is_connect = true;
                            search_cnt = 0;
                        }
                        else {
                            cnt[i] += 1;
                            search_cnt = 0;
                        }
                    }
                }

                str = str.substr(1);
            }
        }

        //cout << cnt[i] << ", " << links[i].size() << endl;
    }

    float scores[20];
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

    //string word = "blind";
    //vector<string> pages;
    //pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nblind lorem blind ipsum dolor blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> link to b </a>\n</body>\n</html>");
    //pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nsuspendisse potenti. vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> link to a </a>\nblind sed congue urna varius. suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> link to c </a>\n</body>\n</html>");;
    //pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nut condimentum urna at felis sodales rutrum. sed dapibus cursus diam, non interdum nulla tempor nec. phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> link to a </a>\n</body>\n</html>");

    string word = "Muzi";
    vector<string> pages;
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>");
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>");

    cout << solution(word, pages);

    return 0;
}