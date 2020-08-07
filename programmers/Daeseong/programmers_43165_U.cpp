//solution
//- number�� ���Һ��� -, +�� �Ͽ� ���ϴ� ����� ����� �� �� �ִ�.
//- target�� �־����� ��� ���� ���� �̿� ������ �ǹǷ� target - sum�� 0�̸� ���� ���ٰ� �� �� �ִ�.
//- ��� ���� ��ȣ�� �ݴ�� �ϸ� sum�� ��ȣ�� �ٲ�Ƿ� �Ʒ��� ������ ����ߴ�.
//- index�� ������ �̵��ϸ鼭 target�� ���� target + numbers[index]�� ������Ʈ �ȴ�.
//- �̶� �������� 0�� �Ǹ� ������� 1������Ų��.

#include <string>
#include <vector>

using namespace std;

void compare(vector<int> numbers, int target, int index, int *answer){
    if (index == numbers.size()) {
        if (target == 0) *answer += 1;
        return;
    }

    int temp = numbers[index];

    compare(numbers, target + temp, index + 1, answer);
    compare(numbers, target - temp, index + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    compare(numbers, target, 0, &answer);

    return answer;
}