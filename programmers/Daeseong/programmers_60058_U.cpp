//Solution
//- �־��� ���Ǵ�� �����Ͽ� "�ùٸ� ��ȣ ���ڿ�"�� �ϼ��ϴ� ����.
//- ������ �����Ͽ� ��������.
//- 1. 4-4.���ǿ� �ش��ϴ� "������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�"�� �ǹ̴�
//- 1.1. ���ڿ��� ������ �ڹٲ�� ���� �ƴ�
//- 1.2. '(' -> ')', ')' -> '('�� �ٲ�� ���̴�.
//- Ǯ�̰����� ������ ����.
//- 1. ��������� string�� ���ؾ��ϹǷ� p�� u�� v�� ������ divide()�Լ��� �����.
//- 2. "�������� ��ȣ ���ڿ�"�� �ش��ϴ� �ּұ����� u�� ���Ѵ�. (p = u + v ����)
//- 3. p�� u�� v�� ������.
//- 4. p�� ���� "�ùٸ� ��ȣ ���ڿ�" ���θ� Ȯ���ϰ� ����� ���� ������ �����Ѵ�.
//- 4.1. "�ùٸ� ��ȣ ���ڿ�"�� ���
//- 4.1.1. v�� ���� 1.���� ������ ��, u + v�� return�Ѵ�.
//- 4.2. "�ùٸ� ��ȣ ���ڿ�"�� �ƴ� ���
//- 4.2.1. u�� �յ� ���� �ϳ����� ������ ��, ��ȣ�� ������ �ٲ۴�.
//- 4.2.2. v�� ���� 1.���� �����Ѵ�.
//- 4.2.3. ������ return �Ѵ�. -> "(" + 4.2.2.���� ���� v + ")" + 4.2.1.���� ���� u

#include <string>
#include <vector>

using namespace std;

int find_locate(string& target) {
    int cnt = 0;
    int i = 0;
    do {
        if (target[i] == '(') cnt++;
        else cnt--;
        i++;
    } while (cnt != 0 && i < target.length());

    return i;
}

bool is_correct(string& target) {
    int cnt = 0;
    for (int i = 0; i < target.length(); i++) {
        if (target[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }

    return true;
}

void mirrored(string& target) {
    for (int i = target.length() - 1; i >= 0; i--) {
        if (target[i] == '(') target[i] = ')';
        else target[i] = '(';
    }
}

string divide(string& p) {
    if (p.length() == 0) return p;
    int locate = find_locate(p);
    string u = p.substr(0, locate);
    string v = p.substr(locate);

    if (is_correct(u)) {
        v = divide(v);
        return u + v;
    }
    else {
        u = p.substr(1, u.length() - 2);
        v = divide(v);
        mirrored(u);
        return "(" + v + ")" + u;
    }
}

string solution(string p) {
    return divide(p);
}