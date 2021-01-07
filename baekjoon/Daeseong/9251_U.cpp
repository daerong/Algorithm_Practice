//Solution
//- ������ȹ���� �� LCS!!
//- �̷��� ������ ����.
//- 1. �� ���ڿ��� �ε����� x, y�� ��,
//- 2. str[x] != str[y]�� ���,
//- 2.1. dp[y][x]�� dp[y][x-1], dp[y-1][x] �� ū ���� ���Ѵ�. 
//- 2.2. �ѱ��ڸ� ���Ѵٰ� �ؼ� �� ���� ���ڿ��� ������� �ʴ´�.
//- 3. str[x] == str[y]�� ���, 
//- 3.1. dp[y][x] = dp[y-1][x-1] + 1�̴�.
//- 3.2. �׷��� ������ ������ �߻��Ѵ�. ex> AAAA, ABCD
//- 3.3. dp[Y-1][X-1]�� ���� ������� LCS�� ���´�.
//Inefficient 1 : 8ms�� 4ms�� �ι谡���� �ð��� �ҿ�ƴ�. 
//- �ڵ�� �ϴܿ� �ּ�ó�� ��.
//- ����
//- 1. ��� x, y�� �ƴ�, �Ϻθ� �����Ѵ�.
//- 1.1. str1 == str2�� ���, ����+1�� �����Ѵ�.
//- ����
//- 1. dp[][]�� -1�� �ʱ�ȭ �ؾ��Ѵ�.
//- 2. if�� �ʿ�.
//- 2.1. if(x < 0 || y < 0)�� ���� �� üũ.
//- 2.2. if(dp[][] != -1)�� �湮���� üũ
//- Ǯ�̴� ������ ����.
//- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
//- 1.1. str1, str2 : �־��� ���ڿ�
//- 1.2. dp[y][x] : str1[x], str2[y]������ LCS ����
//- 2. expand() �Լ����� dp[][]�� �ϼ��Ѵ�.
//- 2.1. x, y�� ���� ������Ű�� ������ �����Ѵ�.
//- 2.1.1. str1[x] == str2[y]�� ���, 
//- 2.1.1.1. dp[y][x]�� �밢���� dp[y-1][x-1]�� 1�� ���� ���� �����Ѵ�.
//- 2.1.2. str1[x] != str2[y]�� ���, 
//- 2.1.2.1. dp[y][x]�� �������� dp[y-1][x], dp[y][x-1] �� ū ���� �����Ѵ�.
//- 3. dp[Y][X]�� ���� ����Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

#define STR_MAX 1001

int X;
int Y;
string str1;
string str2;
int dp[STR_MAX][STR_MAX];

void init() {
	cin >> str1 >> str2;
	X = str1.length();
	Y = str2.length();
	str1 = " " + str1;
	str2 = " " + str2;
}

void expand() {
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			if (str1[x] == str2[y]) dp[y][x] = dp[y - 1][x - 1] + 1;
			else dp[y][x] = max(dp[y - 1][x], dp[y][x - 1]);
		}
	}
}

void solution() {
	init();
	expand();
	cout << dp[Y][X] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}

////Inefficient 1
////- Ǯ�̴� ������ ����.
////- 1. Ǯ�̿� �ʿ��� ������ �����Ѵ�.
////- 1.1. str1, str2 : �־��� ���ڿ�
////- 1.2. X : str1�� ����
////- 1.3. Y : str2�� ����
////- 1.4. dp[y][x] : str1[x], str2[y]������ LCS ����
////- 2. X-1, Y-1�� �������� expand()�� �����Ͽ� dp[][]�� ä���.
////- 2.1. ���� �ۿ��� 0�� return
////- 2.2. dp[][] == -1�� ���, dp[][] return
////- 2.3. ������ ���ǿ� ���� dp[y][x]�� ������Ʈ �ϰ� return
////- 2.3.1. str1[x] == str2[y]�� ���, �밢�� dp[y-1][x-1]�� 1�� ���Ѵ�.
////- 2.3.2. str1[x] != str2[y]�� ���, dp[y-1][x], dp[y][x-1] �� ū ���� ���Ѵ�.
////- 3. dp[Y-1][X-1]�� ���� ����Ѵ�.
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//#define STR_MAX 1001
//
//int X;
//int Y;
//string str1;
//string str2;
//int dp[STR_MAX][STR_MAX];
//
//void init() {
//	cin >> str1 >> str2;
//	X = str1.length();
//	Y = str2.length();
//	for (int y = 0; y < Y; y++) {
//		for (int x = 0; x < X; x++) {
//			dp[y][x] = -1;
//		}
//	}
//}
//
//int expand(int x, int y) {
//	if (x < 0 || y < 0) return 0;
//	if (dp[y][x] != -1) return dp[y][x];
//
//	if (str1[x] == str2[y]) {
//		return dp[y][x] = expand(x - 1, y - 1) + 1;
//	}
//	else {
//		return dp[y][x] = max(expand(x - 1, y), expand(x, y - 1));
//	}
//}
//
//void solution() {
//	init();
//	cout << expand(X - 1, Y - 1) << endl;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	solution();
//
//	return 0;
//}