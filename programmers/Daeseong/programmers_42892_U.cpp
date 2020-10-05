//Solution
//- 주어진 배열로 트리를 만들어 순회하는 문제.
//- 1. NODE의 번호(vector의 index), x, y 값으로 각 NODE를 만든다.
//- 2. 모든 레벨에 대해 오름차 순으로 set을 만든 후 순차적으로 증가하는 index를 부여한다.
//    - 이는 y가 1,2,3,~ 순서대로 진행되지 않기 때문에 빠른 접근을 위해 사용한다.
//- 3. x에 대해 오름차순으로 정렬한다.
//- 4. 모든 NODE에 대해 다음을 반복하여 트리를 완성한다.
//- 4-1. 좌측 NODE 중 y가 더 작고 x가 가장 근접한 NODE를 찾는다. (left NODE)
//- 4-2. 우측 NODE 중 y가 더 작고 x가 가장 근접한 NODE를 찾는다. (right NODE)
//- 4-3. left NODE와 right NODE에 대해 다음을 확인한다.
//- 4-3-1. left NODE가 현재 NODE에 대해 바로 위 레벨에 해당하면 다음을 수행한다. 
//- 4-3-1-1. 현재 NODE의 부모를 left NODE로 지정한다.
//- 4-3-1-2. left NODE의 오른쪽 NODE를 현재 NODE로 지정한다.
//- 4-3-2. right NODE가 현재 NODE에 대해 바로 위 레벨에 해당하면 다음을 수행한다. 
//- 4-3-2-1. 현재 NODE의 부모를 right NODE로 지정한다.
//- 4-3-2-2. right NODE의 왼쪽 NODE를 현재 NODE로 지정한다.
//- 4-3-3. left NODE, right NODE가 모두 nullptr이라면 이는 root NODE에 해당한다. (root NODE)
//- 5. 루트노드부터 다음을 수행한다.   (preorder)
//- 5-1. 현재노드의 index를 preorder에 추가한다.
//- 5-2. 왼쪽 NODE로 이동한다.
//- 5-3. 왼쪽 NODE가 nullptr인 경우, 오른쪽 NODE로 이동한다.
//- 5-4. 오른쪽 NODE도 nullptr인 경우 부모노드로 돌아간다.
//- 6. 루트노드부터 다음을 수행한다.   (postorder)
//- 6-1. 왼쪽 NODE로 이동한다.
//- 6-2. 왼쪽 NODE가 nullptr인 경우, 오른쪽 NODE로 이동한다.
//- 6-3. 오른쪽 NODE도 nullptr인 경우, 현재노드의 index를 preorder에 추가한다.
//- 6-4. 부모노드로 돌아간다.
//- 7. preorder과 postorder을 answer에 담아 return한다.


#include <iostream>
// Code start

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

typedef struct NODE {
    int index;
    int x;
    int y;
    NODE* parent;
    NODE* left;
    NODE* right;
} NODE;

bool compare(NODE a, NODE b) {
    return a.x < b.x;
}

void preorder(NODE* target, vector<int>& pre) {
    pre.push_back(target->index);
    if (target->left != NULL) preorder(target->left, pre);
    if (target->right != NULL) preorder(target->right, pre);
}

void postorder(NODE* target, vector<int>& pre) {
    if (target->left != NULL) postorder(target->left, pre);
    if (target->right != NULL) postorder(target->right, pre);
    pre.push_back(target->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    NODE* root = nullptr;

    unordered_map<int, int> m;          // lv to index
    int m_index = 0;
    set<int> s;                         // lv
    vector<NODE> v;
    for (int i = 0; i < nodeinfo.size(); i++) {
        s.insert(nodeinfo[i][1]);
        v.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1], nullptr, nullptr, nullptr });
    }
    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) m.insert({ *iter, m_index++ });

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        NODE* left = nullptr;
        NODE* right = nullptr;
        for (int l = i - 1; l >= 0; l--) {
            if (m[v[i].y] < m[v[l].y]) {
                left = &v[l];
                break;
            }
        }
        if (left != nullptr) {
            if (m[left->y] - 1 == m[v[i].y]) {
                v[i].parent = left;
                left->right = &v[i];
                //cout << v[i].index << "\'s parent = " << left->index << endl;
                continue;
            }
        }

        for (int r = i + 1; r < v.size(); r++) {
            if (m[v[i].y] < m[v[r].y]) {
                right = &v[r];
                break;
            }
        }
        if (right != nullptr) {
            if (m[right->y] - 1 == m[v[i].y]) {
                v[i].parent = right;
                right->left = &v[i];
                //cout << v[i].index << "\'s parent = " << right->index << endl;
                continue;
            }
        }

        root = &v[i];
    }

    vector<int> pre;
    preorder(root, pre);
    answer.push_back(pre);

    vector<int> post;
    postorder(root, post);
    answer.push_back(post);

    return answer;
}

// Code end
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> nodeinfo;
    nodeinfo.push_back({ 5, 3 });
    nodeinfo.push_back({ 11, 5 });
    nodeinfo.push_back({ 13, 3 });
    nodeinfo.push_back({ 3, 5 });
    nodeinfo.push_back({ 6,1 });
    nodeinfo.push_back({ 1, 3 });
    nodeinfo.push_back({ 8,6 });
    nodeinfo.push_back({ 7,2 });
    nodeinfo.push_back({ 2,2 });;

    vector<vector<int>> result = solution(nodeinfo);

    return 0;
}