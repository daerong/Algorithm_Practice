#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'rotLeft' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER d
#
# [풀이]
# rotate는 배열이 한칸씩 앞으로 오는 것을 의미한다.
# 배열 a의 크기를 n이라 할 떄, d가 n의 배수이면 초기 상태와 동일해진다. (move = d % n, 0 <= move < n)
# 결과를 result라 했을 때, result의 시작은 a의 move번째 인덱스가 된다.
# result의 시작을 기점으로 a의 성분을 index 오름차순으로 추가하면 rotated array가 완성된다.

def rotLeft(a, d):
    # Write your code here
    n = len(a)
    move = d % n
    result = []
    for i in range(0, n):
        if i + move >= n:
            result.append(a[i + move - n])
        else:
            result.append(a[i + move])

    return result
