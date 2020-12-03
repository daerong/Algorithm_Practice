//Solution
//- 테트리스 같은 블럭게임을 구현하는 문제.
//- 다음에 유의하여 구현하자.
//- 1. 주어진 x, y 좌표가 뒤바뀐 상태이다. 주의하자.
//- 2. 주어진 map을 그대로 구현하면 좋겠지만 까다롭다.
//- 2.1. 같은 형태의 블럭이 x축과 y축으로 나눠져서 떨어지는 구조이다.
//- 2.2. 어떤 식으로 좌표를 정하던 떨어진 이후에는 좌우반전 이상으로 변형되지 않는다.
//- 2.3. 즉, 한줄이 full로 차는 경우와 남은 블럭의 수에는 영향을 주지 않는다.
//- 2.4. 결국, 좌표문제로 고민할 필요가 없다는 것이다.
//- 구현은 다음과 같다.
//- 1. blocks에 red 영역에 주어지는 블럭을 차례대로 저장한다.
//- 2. 맵에는 blue, green이 있으며 green은 세로로, blue는 가로로 떨어진다.
//- 2.1. 블럭이 있으면 true, 없으면 false이다.
//- 2.2. 가장 아래쪽은 index 0이며, vector의 erase() 함수로 줄 삭제가 용이하다.
//- 3. 매 블럭마다 다음을 수행한다.
//- 3.1. green 영역에 블럭을 쌓는 함수 insert_green()을 실행한다.
//- 3.1.1. type에 따라 다음을 수행한다.
//- 3.1.1.1. type 1 : 1x1 블럭인 경우,
//- 3.1.1.1.1. x좌표에서 가장 위에 있는 블럭의 위치(h)를 찾는다. 
//- 3.1.1.1.2. h+1 위치에 블럭을 놓는다. 이때, h = 3인 경우, 새로운 열을 추가한다.
//- 3.1.1.1.3. 블럭을 놓은 위치(h+1)이 모두 true인 경우, 해당 열을 삭제한다. 이후 점수를 1 증가시킨다.
//- 3.1.1.1.4. 맵의 높이가 4보다 작은 경우, 4가 될 때 까지 새로운 열을 추가한다.
//- 3.1.1.1.5. 맵의 높이가 4보다 큰 경우, 4가 될 때 까지 index 0 열을 삭제한다.
//- 3.1.1.1. type 2 : 1x2(가로) 블럭인 경우,
//- 3.1.1.1.1. x, x+1좌표에서 가장 위에 있는 블럭의 위치(h)를 찾는다.
//- 3.1.1.1.2. h+1 위치에 블럭을 놓는다.이때, h = 3인 경우, 새로운 열을 추가한다.
//- 3.1.1.1.3. 블럭을 놓은 위치(h+1)이 모두 true인 경우, 해당 열을 삭제한다.이후 점수를 1 증가시킨다.
//- 3.1.1.1.4. 맵의 높이가 4보다 작은 경우, 4가 될 때 까지 새로운 열을 추가한다.
//- 3.1.1.1.5. 맵의 높이가 4보다 큰 경우, 4가 될 때 까지 index 0 열을 삭제한다.
//- 3.1.1.1. type 3 : 2x1(세로) 블럭인 경우,
//- 3.1.1.1.1. x좌표에서 가장 위에 있는 블럭의 위치(h)를 찾는다.
//- 3.1.1.1.2. h+1, h+2 위치에 블럭을 놓는다.이때, h = 3인 경우, 새로운 열을 추가한다.
//- 3.1.1.1.3. 블럭을 놓은 위치(h+1, h+2)이 모두 true인 경우, 해당 열을 삭제한다.이후 각각 점수를 1 증가시킨다.
//- 3.1.1.1.4. 맵의 높이가 4보다 작은 경우, 4가 될 때 까지 새로운 열을 추가한다.
//- 3.1.1.1.5. 맵의 높이가 4보다 큰 경우, 4가 될 때 까지 index 0 열을 삭제한다.
//- 3.1. blue 영역에 블럭을 쌓는 함수 insert_blue()을 실행한다.
//- 3.1.1. type에 따라 다음을 수행한다.
//- 3.1.1.1. type 1 : 1x1 블럭인 경우, insert_green()과 동일하게 수행한다.
//- 3.1.1.1. type 2 : 1x2(가로) 블럭인 경우, insert_green()의 type 3과 동일하게 수행한다.
//- 3.1.1.1. type 3 : 2x1(세로) 블럭인 경우, insert_green()의 type 2과 동일하게 수행한다.
//- 4. blue, green영역의 true 갯수를 구하여 저장한다.
//- 5. 첫번째 줄에는 점수를 두번째 줄에는 남은 블럭의 수를 출력한다.

#include <iostream>
#include <vector>

using namespace std;

int answer[2];
vector<vector<int>> blocks;
vector<vector<bool>> blue;
vector<vector<bool>> green;

void init() {
	int N;
	cin >> N;

	int t, x, y;
	for (int n = 0; n < N; n++) {
		cin >> t >> x >> y;
		blocks.push_back({ t, x, y });
	}

	for (int i = 0; i < 4; i++) {
		blue.push_back({ false, false ,false ,false });
		green.push_back({ false, false ,false ,false });
	}
}

void insert_blue(int type, int x) {
	int h;
	bool is_full;
	switch (type) {
	case 1:
		h = -1;
		for (int y = 3; y >= 0; y--) {
			if (blue[y][x]) {
				h = y;
				break;
			}
		}
		h++;
		if (h == 4) {
			vector<bool> line;
			for (int i = 0; i < 4; i++) {
				if (i == x) line.push_back(true);
				else line.push_back(false);
			}
			blue.push_back(line);
		}
		else {
			blue[h][x] = true;
		}

		is_full = true;
		for (int i = 0; i < 4; i++) {
			if (!blue[h][i]) {
				is_full = false;
				break;
			}
		}
		if (is_full) {
			blue.erase(blue.begin() + h);
			answer[0] += 1;
		}
		while (blue.size() < 4) {
			blue.push_back({ false, false, false, false });
		}
		while (blue.size() > 4) {
			blue.erase(blue.begin());
		}

		break;
	case 2:
		h = -1;
		for (int y = 3; y >= 0; y--) {
			if (blue[y][x]) {
				h = y;
				break;
			}
		}
		h++;
		if (h == 4) {
			vector<bool> line;
			for (int i = 0; i < 4; i++) {
				if (i == x) line.push_back(true);
				else line.push_back(false);
			}
			blue.push_back(line);
			blue.push_back(line);
		}
		else if (h == 3) {
			vector<bool> line;
			for (int i = 0; i < 4; i++) {
				if (i == x) line.push_back(true);
				else line.push_back(false);
			}
			blue.push_back(line);
			blue[h][x] = true;
		}
		else {
			blue[h][x] = true;
			blue[h + 1][x] = true;
		}

		is_full = true;
		for (int i = 0; i < 4; i++) {
			if (!blue[h + 1][i]) {
				is_full = false;
				break;
			}
		}
		if (is_full) {
			blue.erase(blue.begin() + h + 1);
			answer[0] += 1;
		}
		is_full = true;
		for (int i = 0; i < 4; i++) {
			if (!blue[h][i]) {
				is_full = false;
				break;
			}
		}
		if (is_full) {
			blue.erase(blue.begin() + h);
			answer[0] += 1;
		}
		while (blue.size() < 4) {
			blue.push_back({ false, false, false, false });
		}
		while (blue.size() > 4) {
			blue.erase(blue.begin());
		}

		break;
	case 3:
		h = -1;
		for (int y = 3; y >= 0; y--) {
			if (blue[y][x] || blue[y][x + 1]) {
				h = y;
				break;
			}
		}
		h++;
		if (h == 4) {
			vector<bool> line;
			for (int i = 0; i < 4; i++) {
				if (i == x || i == x + 1) line.push_back(true);
				else line.push_back(false);
			}
			blue.push_back(line);
		}
		else {
			blue[h][x] = true;
			blue[h][x + 1] = true;
		}

		is_full = true;
		for (int i = 0; i < 4; i++) {
			if (!blue[h][i]) {
				is_full = false;
				break;
			}
		}
		if (is_full) {
			blue.erase(blue.begin() + h);
			answer[0] += 1;
		}
		while (blue.size() < 4) {
			blue.push_back({ false, false, false, false });
		}
		while (blue.size() > 4) {
			blue.erase(blue.begin());
		}

		break;
	}
}

void insert_green(int type, int x) {
	int h;
	bool is_full;
	switch (type) {
	case 1:
		h = -1;
		for (int y = 3; y >= 0; y--) {
			if (green[y][x]) {
				h = y;
				break;
			}
		}
		h++;
		if (h == 4) {
			vector<bool> line;
			for (int i = 0; i < 4; i++) {
				if (i == x) line.push_back(true);
				else line.push_back(false);
			}
			green.push_back(line);
		}
		else {
			green[h][x] = true;
		}

		is_full = true;
		for (int i = 0; i < 4; i++) {
			if (!green[h][i]) {
				is_full = false;
				break;
			}
		}
		if (is_full) {
			green.erase(green.begin() + h);
			answer[0] += 1;
		}
		while (green.size() < 4) {
			green.push_back({ false, false, false, false });
		}
		while (green.size() > 4) {
			green.erase(green.begin());
		}

		break;
	case 2:
		h = -1;
		for (int y = 3; y >= 0; y--) {
			if (green[y][x] || green[y][x + 1]) {
				h = y;
				break;
			}
		}
		h++;
		if (h == 4) {
			vector<bool> line;
			for (int i = 0; i < 4; i++) {
				if (i == x || i == x + 1) line.push_back(true);
				else line.push_back(false);
			}
			green.push_back(line);
		}
		else {
			green[h][x] = true;
			green[h][x + 1] = true;
		}

		is_full = true;
		for (int i = 0; i < 4; i++) {
			if (!green[h][i]) {
				is_full = false;
				break;
			}
		}
		if (is_full) {
			green.erase(green.begin() + h);
			answer[0] += 1;
		}
		while (green.size() < 4) {
			green.push_back({ false, false, false, false });
		}
		while (green.size() > 4) {
			green.erase(green.begin());
		}

		break;
	case 3:
		h = -1;
		for (int y = 3; y >= 0; y--) {
			if (green[y][x]) {
				h = y;
				break;
			}
		}
		h++;
		if (h == 4) {
			vector<bool> line;
			for (int i = 0; i < 4; i++) {
				if (i == x) line.push_back(true);
				else line.push_back(false);
			}
			green.push_back(line);
			green.push_back(line);
		}
		else if (h == 3) {
			vector<bool> line;
			for (int i = 0; i < 4; i++) {
				if (i == x) line.push_back(true);
				else line.push_back(false);
			}
			green.push_back(line);
			green[h][x] = true;
		}
		else {
			green[h][x] = true;
			green[h + 1][x] = true;
		}

		is_full = true;
		for (int i = 0; i < 4; i++) {
			if (!green[h + 1][i]) {
				is_full = false;
				break;
			}
		}
		if (is_full) {
			green.erase(green.begin() + h + 1);
			answer[0] += 1;
		}
		is_full = true;
		for (int i = 0; i < 4; i++) {
			if (!green[h][i]) {
				is_full = false;
				break;
			}
		}
		if (is_full) {
			green.erase(green.begin() + h);
			answer[0] += 1;
		}
		while (green.size() < 4) {
			green.push_back({ false, false, false, false });
		}
		while (green.size() > 4) {
			green.erase(green.begin());
		}

		break;
	}
}

//void print_map() {
//	cout << blue.size() << ", " << green.size() << endl;;
//	for (int y = 3; y >= 0; y--) {
//		for (int x = 0; x < 4; x++) {
//			cout << green[y][x] << " ";
//		}
//		cout << "      ";
//		for (int x = 0; x < 4; x++) {
//			cout << blue[y][x] << " ";
//		}
//		cout << endl;
//	}
//}

void simulation() {
	for (int i = 0; i < blocks.size(); i++) {
		insert_blue(blocks[i][0], blocks[i][1]);
		insert_green(blocks[i][0], blocks[i][2]);

		//print_map();
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (blue[y][x]) answer[1] += 1;
			if (green[y][x]) answer[1] += 1;
		}
	}
}

void solve() {
	init();
	simulation();
	cout << answer[0] << endl;
	cout << answer[1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}