# Chess Tournament 

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| :-------- | :---------- | :--- | :--- | :-------- | :-------- |
| 5 초      | 512 MB      | 838  | 286  | 196       | 31.870%   |

## 문제

Your friend is an organizer of the International Chess Playing Championship. He is worried that some of the contestants may be cheating, and he has asked you to help out. The chess players are allowed to report matches to the jury themselves, and this is not checked with the reported opponent. So, it is possible for competitors to make up matches and falsely report themselves as the winners.

Since chess is a game of skill, and not of chance, a player will always beat their opponent if their skill level is higher. A game will result in a draw if and only if the two players’ skills are exactly equal.

However, the skill level of the players is not known. He has therefore asked you to write a program that, given a list of reported matches, determines whether this list is consistent or not. The list is inconsistent if we can determine that at least reported match is falsely reported, otherwise it is consistent.

## 입력

The first line contains two integers N (2 ≤ N ≤ 50 000) and M (1 ≤ M ≤ 250 000), to describe a championship with N players and M reported matches.

The following M lines each consist of an integer K, a symbol which is either ‘=’ or ‘>’, and another integer L. The integers K and L each uniquely identify a player (0 ≤ K, L < N). If the symbol is ‘=’, then the game between K and L was a draw. If the symbol is ‘>’, then K beat L in a match.

You may assume that there is at most one reported match between any given pair of players. Also, each player takes part in at least one reported match.

## 출력

Output a single line containing a single word: “consistent” if the list of recorded matches is consistent, and “inconsistent” if it is not.

## 예제 입력 1 복사

```
3 3
0 > 1
1 = 2
0 = 2
```

## 예제 출력 1 복사

```
inconsistent
```

## 예제 입력 2 복사

```
5 5
0 = 1
1 = 2
3 = 4
0 > 3
1 > 4
```

## 예제 출력 2 복사

```
consistent
```

## 예제 입력 3 복사

```
6 5
0 > 1
1 > 2
3 = 4
4 = 5
5 > 3
```

## 예제 출력 3 복사

```
inconsistent
```

## 출처

[![img](https://licensebuttons.net/l/by-sa/4.0/88x31.png)](https://creativecommons.org/licenses/by-sa/4.0/)

[ICPC ](https://www.acmicpc.net/category/1)> [Regionals ](https://www.acmicpc.net/category/7)> [Europe ](https://www.acmicpc.net/category/10)> [Northwestern European Regional Contest ](https://www.acmicpc.net/category/15)> [Benelux Algorithm Programming Contest ](https://www.acmicpc.net/category/89)> [BAPC 2016 Preliminaries](https://www.acmicpc.net/category/detail/1529) B번

## 알고리즘 분류



- [그래프 이론](https://www.acmicpc.net/problem/tag/7)
- [자료 구조](https://www.acmicpc.net/problem/tag/175)
- [분리 집합](https://www.acmicpc.net/problem/tag/81)
- [위상 정렬](https://www.acmicpc.net/problem/tag/78)