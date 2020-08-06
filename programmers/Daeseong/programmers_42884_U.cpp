//Solution
//- 다음의 방식을 이용하면 나가는 차를 모두 측정할 수 있다.
//- 1. 차의 진입순서를 빠른 순서로 정렬한다.
//- 2. 처음 차의 진출 시기를 end_point에 저장한다.
//- 3. 다음 차의 진출 시기가 end_point보다 작은 경우, end_point를 작은 값으로 변경한다.
//- 4. 다음 차의 진입 시기가 end_point보다 작은 경우, 결과 값을 1 증가시킨다.
//	- 이 경우 이전의 차량은 모두 측정이 완료되었으므로 end_point를 새로운 차량의 진출 시기로 변경한다.
//-5. 마지막 반복에 대해서는 종료시기를 정하지 못했으므로 결과 값을 1 증가시킨다.

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