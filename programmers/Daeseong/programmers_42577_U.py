def solution(phone_book):
    for idx, answer in enumerate(phone_book):
        for idx_1, answer_1 in enumerate(phone_book):
            Sstr = str(answer)
            Sstr_1 = str(answer_1)
            if len(Sstr) > len(Sstr_1):
                continue
            elif idx == idx_1:
                continue
            elif Sstr == Sstr_1[:len(Sstr)]:
                return False

    return True