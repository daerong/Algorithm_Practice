def solution(participant, completion):
    participant = list(participant)
    completion = list(completion)

    participant.sort()
    completion.sort()

    num = 0
    size = len(participant)

    while True:
        if num == size - 1:
            return participant[num]
        elif participant[num] != completion[num]:
            return participant[num]
        else:
            num += 1