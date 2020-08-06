//Solution
//- ������ ����� �̿��ϸ� ������ ���� ��� ������ �� �ִ�.
//- 1. ���� ���Լ����� ���� ������ �����Ѵ�.
//- 2. ó�� ���� ���� �ñ⸦ end_point�� �����Ѵ�.
//- 3. ���� ���� ���� �ñⰡ end_point���� ���� ���, end_point�� ���� ������ �����Ѵ�.
//- 4. ���� ���� ���� �ñⰡ end_point���� ���� ���, ��� ���� 1 ������Ų��.
//	- �� ��� ������ ������ ��� ������ �Ϸ�Ǿ����Ƿ� end_point�� ���ο� ������ ���� �ñ�� �����Ѵ�.
//-5. ������ �ݺ��� ���ؼ��� ����ñ⸦ ������ �������Ƿ� ��� ���� 1 ������Ų��.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end());
	int end_point = routes[0][1];

	for (int i = 1; i < routes.size(); i++) {
		if (routes[i][1] < end_point) {
			end_point = routes[i][1];
			continue;
		}
			
		if (routes[i][0] > end_point) {
			answer += 1;
			end_point = routes[i][1];
		}
	}

	answer += 1;

	return answer;
}