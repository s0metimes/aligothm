## DP 풀때
* 점화식중 , 0번째나 1번째 같이 초기화 해줘야 할때, **main문 안에서** 초기화합니다.
* 혹 종료조건이 필요하다면, **for문 상단**에 조건문을 넣어줍니다.


## 대소비교 시, if문안에 조건
* 기준이 되는 값을 오른쪽에 두도록 합니다.
~~~
if(nums[mid] < value) start = mid+1;
else if(nums[mid] > value) end = mid-1;
~~~

## binarySearch
* 변수명은 <**start**, **mid**, **end**>를 사용합니다.
* 문제 푸는 방식은 재귀함수 보다는 **while**을 선호합니다.
~~~
int binary_search(int value, int start, int end) {
    int mid;
    while(start <= end) {
        mid = (start+end)/2;
        if(nums[mid] < value) start = mid+1;
        else if(nums[mid] > value) end = mid-1;
        else return 1;
    } 
    return 0;
}
~~~