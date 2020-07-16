<h1> Algorithms study</h1>

-	**스터디명** - 알리고즘

-	**팀원** - 김석기, 남영우, 오시환

-	**요일** - 월, 목 1:00 PM

-	**장소** - 할리스 커피 당산역점

-	**목표** - ICPC 입상

-	**스터디 방법**

	-	**월요일** - 전 주에 스터디서 다룬 개념 복습, 새로운 알고리즘 개념 공부
	-	**목요일** - 해당 알고리즘 개념 관련 문제 리뷰, 응용 문제 같이 풀기

-	**주차별 커리큘럼**

	-	1주차

-	**Repository 관리 방법 (매스터디 헤어지기 전에 해야함)**

	-	매스터디 백준 그룹에 문제를 선정해두고 최소한도로 풀 양과 벌금을 결정
	-	github 에 주차별로 폴더 관리 (ex: week1, week2)
	-	각 문제별로 폴더를 파서 관리 (문제 번호와 명칭을 대략 영어로 요약)
	-	각각 작성하는 파일명은 **[문제번호]\_[제목요약]\_[이름].cpp** 으로 관리
	-	각 주차 내에서 개념으로 분류할만한 것은 개념폴더로 만들어서 관리  

<details open><summary><b>폴더구조</b></summary>

```
~/Desktop/Computer/Algorithm/aligothm youngwoo*

❯ tree
.
├── README.md
└── week1
    ├── 1111_PrintStar
    │   ├── PrintStar_kim.cpp
    │   ├── PrintStar_nam.cpp
    │   └── PrintStar_oh.cpp
    └── 1234_fibonacci
        ├── fibonacci_kim.cpp
        ├── fibonacci_nam.cpp
        └── fibonacci_oh.cpp

3 directories, 7 files
```

</details>

-	<b>GIT</b>

	##### 마스터브랜치로 푸쉬 하는것은 스터디하는 요일에 다같이 작업할 것

	<details open><summary><b>git command</b></summary>

	###### 각자의 리모트 브랜치로 파일 올리는 방법

	```
	$ git add .
	$ git commit -m "커밋 메세지"
	$ git push origin [현재 브랜치]
	```

	**!!** remote에 push 하는 경우, 카톡방에 **"[브랜치명] 푸쉬했습니다."** 알려주기</details>

	<details open><summary><b>branch 삭제 방법</b></summary>

	###### 마스터 브랜치로 옮겨가기 (이미 마스터 브랜치라면 생략)

	```
	$ git checkout master
	```

	###### 브랜치 로컬에서 삭제하기

	```
	$ git branch -d [삭제하려는 브랜치명]
	```

	###### 브랜치 삭제를 remote 에도 적용하기

	```
	$ git push origin :[삭제한 브랜치명]
	```

	</details>

	<details open><summary><b>branch 생성하기</b></summary>

	###### 로컬에 branch 생성하기

	```
	$ git branch [생성하려는 브랜치명]
	```

	###### 해당 브랜치로 옮겨가기

	```
	$ git checkout [생성한 브랜치명]
	```

	###### 생성한 브랜치 remote 로 올리기

	```
	$ git push —set-upstream origin [생성한 브랜치명]
	```

	</details>

	<details open><summary><b>현재 브랜치 확인하기</b></summary>

	###### 브랜치 리스트 보기

	```
	$ git branch
	```

	###### 브랜치 리스트에서 별표시가 있는 친구가 현재 브랜치

	```
	~/Desktop/Computer/Algorithm/aligothm youngwoo* // 에서 youngwoo*
	```

	</details>

-	**스터디 룰**

	-	못푼 문제 : 문제 별 1000원(심의 가능)
	-	지각비 : 5000원(심의 가능)
	-	무단결석 : 밥사기
	-	결석 : 10000원(심의 가능)
