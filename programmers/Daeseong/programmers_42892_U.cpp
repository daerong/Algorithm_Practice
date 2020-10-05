#include <iostream>
// Code start

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
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