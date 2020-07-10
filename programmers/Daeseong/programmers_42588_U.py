def solution(heights):
    answer = []

    for idx, height in enumerate(heights):
        for id in range(idx, -1, -1):
            if height < heights[id]:
                answer.append(id+1)
                break
        if len(answer) == idx:
            answer.append(0)


    return answer