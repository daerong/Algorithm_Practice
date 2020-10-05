//Solution
//- �־��� �迭�� Ʈ���� ����� ��ȸ�ϴ� ����.
//- 1. NODE�� ��ȣ(vector�� index), x, y ������ �� NODE�� �����.
//- 2. ��� ������ ���� ������ ������ set�� ���� �� ���������� �����ϴ� index�� �ο��Ѵ�.
//    - �̴� y�� 1,2,3,~ ������� ������� �ʱ� ������ ���� ������ ���� ����Ѵ�.
//- 3. x�� ���� ������������ �����Ѵ�.
//- 4. ��� NODE�� ���� ������ �ݺ��Ͽ� Ʈ���� �ϼ��Ѵ�.
//- 4-1. ���� NODE �� y�� �� �۰� x�� ���� ������ NODE�� ã�´�. (left NODE)
//- 4-2. ���� NODE �� y�� �� �۰� x�� ���� ������ NODE�� ã�´�. (right NODE)
//- 4-3. left NODE�� right NODE�� ���� ������ Ȯ���Ѵ�.
//- 4-3-1. left NODE�� ���� NODE�� ���� �ٷ� �� ������ �ش��ϸ� ������ �����Ѵ�. 
//- 4-3-1-1. ���� NODE�� �θ� left NODE�� �����Ѵ�.
//- 4-3-1-2. left NODE�� ������ NODE�� ���� NODE�� �����Ѵ�.
//- 4-3-2. right NODE�� ���� NODE�� ���� �ٷ� �� ������ �ش��ϸ� ������ �����Ѵ�. 
//- 4-3-2-1. ���� NODE�� �θ� right NODE�� �����Ѵ�.
//- 4-3-2-2. right NODE�� ���� NODE�� ���� NODE�� �����Ѵ�.
//- 4-3-3. left NODE, right NODE�� ��� nullptr�̶�� �̴� root NODE�� �ش��Ѵ�. (root NODE)
//- 5. ��Ʈ������ ������ �����Ѵ�.   (preorder)
//- 5-1. �������� index�� preorder�� �߰��Ѵ�.
//- 5-2. ���� NODE�� �̵��Ѵ�.
//- 5-3. ���� NODE�� nullptr�� ���, ������ NODE�� �̵��Ѵ�.
//- 5-4. ������ NODE�� nullptr�� ��� �θ���� ���ư���.
//- 6. ��Ʈ������ ������ �����Ѵ�.   (postorder)
//- 6-1. ���� NODE�� �̵��Ѵ�.
//- 6-2. ���� NODE�� nullptr�� ���, ������ NODE�� �̵��Ѵ�.
//- 6-3. ������ NODE�� nullptr�� ���, �������� index�� preorder�� �߰��Ѵ�.
//- 6-4. �θ���� ���ư���.
//- 7. preorder�� postorder�� answer�� ��� return�Ѵ�.


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