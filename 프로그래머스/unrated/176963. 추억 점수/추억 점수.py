def solution(name, yearning, photo):
    answer = []
    data = dict()

    # map 형식으로 정리 (이름, 값)
    for i in range(len(name)):
        data[name[i]] = yearning[i]

    for people in photo:
        score = 0
        for person in people:
            if(person in data):
                score += data[person]
        answer.append(score)

    return answer

