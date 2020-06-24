// start : pm 11:39
// end : pm 11:50

// Compare two distance A-C and B-C.
// And then choose smaller.
// If those has same distance, print "mouse C"  

#include <iostream>
#include <algorithm>

using namespace std;

void cat_and_mouse(int catA, int catB, int mouse) {
	int distA = abs(catA - mouse);
	int distB = abs(catB - mouse);

	if (distA == distB) cout << "Mouse C" << endl;
	else if (distA < distB) cout << "Cat A" << endl;
	else cout << "Cat B" << endl;
}

void solution() {
	int N;
	int x, y, z;
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		cat_and_mouse(x, y, z);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}