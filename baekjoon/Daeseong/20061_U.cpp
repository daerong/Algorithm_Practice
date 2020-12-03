//Solution
//- ��Ʈ���� ���� �������� �����ϴ� ����.
//- ������ �����Ͽ� ��������.
//- 1. �־��� x, y ��ǥ�� �ڹٲ� �����̴�. ��������.
//- 2. �־��� map�� �״�� �����ϸ� �������� ��ٷӴ�.
//- 2.1. ���� ������ ���� x��� y������ �������� �������� �����̴�.
//- 2.2. � ������ ��ǥ�� ���ϴ� ������ ���Ŀ��� �¿���� �̻����� �������� �ʴ´�.
//- 2.3. ��, ������ full�� ���� ���� ���� ���� ������ ������ ���� �ʴ´�.
//- 2.4. �ᱹ, ��ǥ������ ����� �ʿ䰡 ���ٴ� ���̴�.
//- ������ ������ ����.
//- 1. blocks�� red ������ �־����� ���� ���ʴ�� �����Ѵ�.
//- 2. �ʿ��� blue, green�� ������ green�� ���η�, blue�� ���η� ��������.
//- 2.1. ���� ������ true, ������ false�̴�.
//- 2.2. ���� �Ʒ����� index 0�̸�, vector�� erase() �Լ��� �� ������ �����ϴ�.
//- 3. �� ������ ������ �����Ѵ�.
//- 3.1. green ������ ���� �״� �Լ� insert_green()�� �����Ѵ�.
//- 3.1.1. type�� ���� ������ �����Ѵ�.
//- 3.1.1.1. type 1 : 1x1 ���� ���,
//- 3.1.1.1.1. x��ǥ���� ���� ���� �ִ� ���� ��ġ(h)�� ã�´�. 
//- 3.1.1.1.2. h+1 ��ġ�� ���� ���´�. �̶�, h = 3�� ���, ���ο� ���� �߰��Ѵ�.
//- 3.1.1.1.3. ���� ���� ��ġ(h+1)�� ��� true�� ���, �ش� ���� �����Ѵ�. ���� ������ 1 ������Ų��.
//- 3.1.1.1.4. ���� ���̰� 4���� ���� ���, 4�� �� �� ���� ���ο� ���� �߰��Ѵ�.
//- 3.1.1.1.5. ���� ���̰� 4���� ū ���, 4�� �� �� ���� index 0 ���� �����Ѵ�.
//- 3.1.1.1. type 2 : 1x2(����) ���� ���,
//- 3.1.1.1.1. x, x+1��ǥ���� ���� ���� �ִ� ���� ��ġ(h)�� ã�´�.
//- 3.1.1.1.2. h+1 ��ġ�� ���� ���´�.�̶�, h = 3�� ���, ���ο� ���� �߰��Ѵ�.
//- 3.1.1.1.3. ���� ���� ��ġ(h+1)�� ��� true�� ���, �ش� ���� �����Ѵ�.���� ������ 1 ������Ų��.
//- 3.1.1.1.4. ���� ���̰� 4���� ���� ���, 4�� �� �� ���� ���ο� ���� �߰��Ѵ�.
//- 3.1.1.1.5. ���� ���̰� 4���� ū ���, 4�� �� �� ���� index 0 ���� �����Ѵ�.
//- 3.1.1.1. type 3 : 2x1(����) ���� ���,
//- 3.1.1.1.1. x��ǥ���� ���� ���� �ִ� ���� ��ġ(h)�� ã�´�.
//- 3.1.1.1.2. h+1, h+2 ��ġ�� ���� ���´�.�̶�, h = 3�� ���, ���ο� ���� �߰��Ѵ�.
//- 3.1.1.1.3. ���� ���� ��ġ(h+1, h+2)�� ��� true�� ���, �ش� ���� �����Ѵ�.���� ���� ������ 1 ������Ų��.
//- 3.1.1.1.4. ���� ���̰� 4���� ���� ���, 4�� �� �� ���� ���ο� ���� �߰��Ѵ�.
//- 3.1.1.1.5. ���� ���̰� 4���� ū ���, 4�� �� �� ���� index 0 ���� �����Ѵ�.
//- 3.1. blue ������ ���� �״� �Լ� insert_blue()�� �����Ѵ�.
//- 3.1.1. type�� ���� ������ �����Ѵ�.
//- 3.1.1.1. type 1 : 1x1 ���� ���, insert_green()�� �����ϰ� �����Ѵ�.
//- 3.1.1.1. type 2 : 1x2(����) ���� ���, insert_green()�� type 3�� �����ϰ� �����Ѵ�.
//- 3.1.1.1. type 3 : 2x1(����) ���� ���, insert_green()�� type 2�� �����ϰ� �����Ѵ�.
//- 4. blue, green������ true ������ ���Ͽ� �����Ѵ�.
//- 5. ù��° �ٿ��� ������ �ι�° �ٿ��� ���� ���� ���� ����Ѵ�.

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