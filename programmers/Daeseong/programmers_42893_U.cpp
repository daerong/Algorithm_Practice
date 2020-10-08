#include <iostream>
// Code start

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

#define W_MAX 20
#define KEY_STR "content=\"https://"
#define KEY_STR_SIZE 17
#define LINK_STR "href=\"https://"
#define LINK_STR_SIZE 14
#define BODY_START "<body>"
#define BODY_END "</body>"
#define LINK_START "<a"
#define LINK_END "</a>"

using namespace std;

typedef struct TB {
    int index;
    float score;
} TB;

bool compare(TB a, TB b) {
    if (a.score == b.score) return a.index < b.index;
    else return a.score > b.score;
}

int solution(string word, vector<string> pages) {
    int answer = 0;

    string word_lower = word;
    for (int i = 0; i < word_lower.size(); i++) word_lower[i] = tolower(word_lower[i]);

    unordered_map<string, int> m;
    int m_index = 0;
    int word_cnt[W_MAX];
    for (int i = 0; i < W_MAX; i++) word_cnt[i] = 0;
    vector<string> links[W_MAX];

    stringstream ss;
    string temp;
    for (int i = 0; i < pages.size(); i++) {
        ss.str(pages[i]);
        bool is_body = false;
        bool link_on = false;
        while (ss >> temp) {
            if (temp.find(KEY_STR) != string::npos) {
                m.insert({ temp.substr(temp.find(KEY_STR) + KEY_STR_SIZE), m_index++ });
            }
            else if (temp.find(BODY_START) != string::npos) {
                is_body = true;
            }
            else if (temp.find(BODY_END) != string::npos) {
                is_body = false;
            }
            else if (is_body) {
                if (temp.find(LINK_START) != string::npos) {
                    link_on = true;
                }
                else if (temp.find(LINK_END) != string::npos) {
                    link_on = false;
                }
                else if (link_on) {
                    if (temp.find(LINK_STR) != string::npos) {
                        links[i].push_back(temp.substr(temp.find(LINK_STR) + LINK_STR_SIZE));
                    }
                }
                else {
                    int idx = 0;
                    for (int cid = 0; cid < temp.size(); cid++) {
                        if (temp[cid] >= 'A' || temp[cid] <= 'Z') {
                            if (tolower(temp[cid]) == word_lower[idx]) idx++;
                            else idx = 0;
                        }
                        else if (temp[cid] >= 'a' || temp[cid] <= 'z') {
                            if (temp[cid] == word_lower[idx]) idx++;
                            else idx = 0;
                        }
                        else idx = 0;

                        if (idx == word_lower.length()) {
                            word_cnt[i] += 1;
                            idx = 0;
                        }
                    }
                }
            }

            //cout << temp << endl;
        }
        //cout << word_cnt[i] << ", " << links[i].size() << endl;

        ss.clear();
    }

    for (int i = 0; i < m_index; i++) {
        float score = word_cnt[i];
        cout << i << "score = " << score << endl;
        for (int n = 0; n < links[i].size(); n++) {
            int target_id = m[links[i][n]];
            score += word_cnt[target_id] / links[n].size();
            cout << i << "score = " << links[i][n] << "/" << links[n].size() << endl;
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

    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>");
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>");;
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>");

    cout << solution(word, pages);

    return 0;
}