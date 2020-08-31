# 일감호에 다리 놓기

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| :-------- | :---------- | :--- | :--- | :-------- | :-------- |
| 2 초      | 256 MB      | 603  | 118  | 82        | 18.807%   |

## 문제

학교의 홍보대사를 맡게 된 건덕이는 건국대학교의 모든 강의동을 신입생들에게 소개해야 한다.

건국대학교 중앙에 위치한 일감호를 따라 한 바퀴를 돌며 모든 강의동을 소개하는 것이 그의 일이지만, 몇몇 구간들이 공사 중이어서 그 구간을 통해서는 갈 수 없는 상황이다. 급한대로 건덕이는 호수에 돌을 던져 징검다리를 놓아 길을 만들어보려고 한다.

강의동은 일감호의 둘레에 따라 원형으로 배치돼 있으며, 강의동 양 옆의 강의동은 서로 이웃한다. 또, 원형으로 배치돼 있기 때문에 *N*개의 강의동이 있다면 *N*번째 강의동과 1번째 강의동은 서로 이웃한다.

일감호 안에는 와우도라는 섬이 있다. 건덕이는 한 강의실에서 다른 모든 강의실로 이동할 수 있도록 강의동에서 와우도까지 징검다리를 놓기로 했다. 하지만 건덕이의 눈에는 *K*개의 돌밖에 보이지 않는다. 건덕이는 주어진 돌을 활용해서 징검다리를 완성할 수 있을까?

## 입력

첫째 줄에 강의동의 수 *N*, 공사구간의 수 *M*, 건덕이가 가진 돌의 수 *K*가 공백으로 구분돼 주어진다. 강의동은 1동부터 N동까지 존재한다.

다음 줄에는 강의동에서 와우도까지 놓아야하는 돌의 개수 S1, S2, ..., SN이 공백으로 구분돼 주어진다. 이는 *T*번째 강의동에서 와우도까지 ST개의 돌을 놓아야 함을 의미한다. 이어서 *M*개의 줄에 i, j가 주어진다. 이는 i번째 강의동에서 j번째 강의동까지 가는 길이 공사중임을 의미한다. 이 때 입력되는 i, j번째 건물은 이웃한 강의동이다. 공사중인 구역은 한 번만 주어진다.

## 출력

건덕이가 가지고 있는 돌을 놓아 모든 강의동을 연결할 수 있으면 `YES`를, 그렇지 않으면 `NO`를 출력한다.

## 제한

- 3 ≤ *N* ≤ 1,000,000
- 0 ≤ *M* ≤ *N*
- 1 ≤ *i*, *j* ≤ *N* 
- 1 ≤ *T* ≤ *N*인 모든 정수 *T*에 대해 1 ≤ *ST* ≤ 1,000,000
- 0 ≤ *K* ≤ 5,000,000,000

## 예제 입력 1 복사

```
5 3 9
2 1 3 2 5
2 3
4 5
5 1
```

## 예제 출력 1 복사

```
YES
```

![img](https://upload.acmicpc.net/0149c640-fc15-4e60-8042-d98514ea889e/-/preview/)

2번, 4번, 5번 강의동과 와우도를 연결하면 가지고 있는 돌 내에서 징검다리를 완성할 수 있다. 이 때, 어떤 한 강의동에서 다른 모든 강의동으로 가는 길이 존재한다.

## 예제 입력 2 복사

```
5 3 7
2 1 3 2 5
2 3
4 5
5 1
```

## 예제 출력 2 복사

```
NO
```

## 출처

[University ](https://www.acmicpc.net/category/5)> [건국대학교 ](https://www.acmicpc.net/category/454)> [2019 건국대학교 동아리 알프스 프로그래밍 경진대회 (KAPC)](https://www.acmicpc.net/category/detail/2061) D번

- 문제를 만든 사람: [aru0504](https://www.acmicpc.net/user/aru0504)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/17490#)