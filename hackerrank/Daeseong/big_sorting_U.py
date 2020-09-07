# Solution
# - 파이썬은 자료형의 범위가 없다. 따라서 정수형 비교가 바로 가능하다
# - 하지만 변환하지 않고 비교하는 방법을 사용할 수 있다.
# - key에 lambda를 넣어 다중 조건실을 활용했다.
# - 우선 순위는 다음과 같다.
# - 1. 길이의 오름차순
# - 2. 문자열의 오름차순

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the bigSorting function below.
def bigSorting(unsorted):
    return sorted(unsorted, key=lambda x: (len(x), x))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    unsorted = []

    for _ in range(n):
        unsorted_item = input()
        unsorted.append(unsorted_item)

    result = bigSorting(unsorted)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
