//Solution
//- Using Hashmap.
//- k�� �ִ��� 10^12�̶� �迭�� ���� �湮üũ�� ������� �ִ�. (�޸� �ʰ��� Fail)
//- �Ʒ��� ����� ���� �ؽø����� ������ġ�� ���� �� �� �ִ�.
//- 1. Hashmap�� ����ִ� ���, Hashmap�� ä��� �� ���� ��ȣ�� ����Ű�� �Ѵ�. 
//- 2. Hashmap�� ���ִ� ���, �ؽø��� ����Ű�� ��ġ�� ã�´�.
//- 3-1. 2���� ã�� ��ġ�� ����ִ� ���, Hashmap�� ä��� �� ���� ��ȣ�� ����Ű�� �Ѵ�.
//- 3-2. 2���� ������ �ݺ��� ���, ������ �ִ� Hashmap�� ���� ��ġ�� ����ϸ� ��͹ݺ��� ���� �� �ִ�.
//        - ������� 1-2-3-4-5 ������ ��͸� �ݺ��� ���, 1, 2, 3, 4�� ��� 5�� ����Ű�� �� ���� ������ �����ϴ�.
//- 4. 2���� ã�� ��ġ�� ���ִ� ���, ���� ��ġ���� �ٽ� 2�� �����Ѵ�.


#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> answer;
unordered_map<long long, long long> m;

long long find(long long target) {
    if (m[target] == 0) {
        // 3-1. 2���� ã�� ��ġ�� ����ִ� ���, Hashmap�� ä��� �� ���� ��ȣ�� ����Ű�� �Ѵ�.
        answer.emplace_back(target);
        m[target] = target + 1;
        return target + 1;
    }

    // 4. 2���� ã�� ��ġ�� ���ִ� ���, ���� ��ġ���� �ٽ� 2�� �����Ѵ�.
    return m[target] = find(m[target]);     // 3-2. 2���� ������ �ݺ��� ���, ������ �ִ� Hashmap�� ���� ��ġ�� ����ϸ� ��͹ݺ��� ���� �� �ִ�.
}

vector<long long> solution(long long k, vector<long long> room_number) {
    m.reserve(room_number.size() + 1);          // reserve() �޸� ���Ҵ� ����
    answer.reserve(room_number.size());

    long long room_index;
    for (int i = 0; i < room_number.size(); i++) {
        room_index = room_number[i];
        if (m[room_index] == 0) {
            // 1. Hashmap�� ����ִ� ���, Hashmap�� ä��� �� ���� ��ȣ�� ����Ű�� �Ѵ�. 
            answer.emplace_back(room_index);        // �Ϲ������� push_back()���� ����
            m[room_index] = room_index + 1;
        }
        else {
            // 2. Hashmap�� ���ִ� ���, �ؽø��� ����Ű�� ��ġ�� ã�´�.
            find(m[room_index]);
        }
    }

    return answer;
}