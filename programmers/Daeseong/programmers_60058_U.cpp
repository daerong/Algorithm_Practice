//°ıÈ£ °¹¼ö¸¸ °°À½ -> ±ÕÇüÀâÈù °ıÈ£ ¹®ÀÚ¿­
//½ÖÀÌ ¿Ã¹Ù·Î ÀÌ¾îÁü -> ¿Ã¹Ù¸¥ °ıÈ£ ¹®ÀÚ¿­

#include <string>
#include <vector>
#include <queue>

using namespace std;

bool is_correct(string str) {
    if (str == "") return true;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') cnt++;
        else if (str[i] == ')') cnt--;

        if (cnt < 0) return false;
    }

    return true;
}

string uv(string u, string v) {
    if (is_correct(u)) {
        int cnt = 0;
        if (v == "") return u;
        else {
            for (int i = 0; i < v.length(); i++) {
                if (v[i] == '(') cnt++;
                else if (v[i] == ')') cnt--;

                string uu = v.substr(0, i + 1);
                string vv = v.substr(i + 1);

                if (cnt == 0) return u + uv(uu, vv);
            }
        }
    }
    else {
        string temp = "(";

        int cnt = 0;
        if (v == "") temp += "";
        else {
            for (int i = 0; i < v.length(); i++) {
                if (v[i] == '(') cnt++;
                else if (v[i] == ')') cnt--;

                string uu = v.substr(0, i + 1);
                string vv = v.substr(i + 1);

                if (cnt == 0) temp += uv(uu, vv);
            }
        }

        temp += ")";
        for (int i = u.length() - 2; i > 0; i--) temp += u[i];

        return temp;
    }

    return u + v;
}

string solution(string p) {
    if (p == "") return p;

    int cnt = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') cnt++;
        else if (p[i] == ')') cnt--;

        if (cnt == 0) {
            return uv(p.substr(0, i + 1), p.substr(i + 1));
        }
    }
}