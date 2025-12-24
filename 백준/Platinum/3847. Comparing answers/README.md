# [Platinum II] Comparing answers - 3847 

[문제 링크](https://www.acmicpc.net/problem/3847) 

### 성능 요약

메모리: 9960 KB, 시간: 3488 ms

### 분류

수학, 구현, 선형대수학, 무작위화, 휴리스틱

### 제출 일자

2025년 12월 24일 16:39:39

### 문제 설명

<p>In a place in Southwestern Europe, the name of which I do not wish to recall, not long ago there were n cities connected by unidirectional roads, with possibly more than one road connecting a city to another one, or even to itself. As a homework assignment for your geography class, you need to calculate the number of paths of length exactly two that were between each pair of cities. However, you’ve been too busy celebrating the Spanish victory in the World Cup, so now you are copying the answers from your friend. You would like to make sure his answers are correct before handing in your homework.</p>

### 입력 

 <p>The input consists of several test cases, separated by single blank lines. Each test case begins with a line containing the integer n (1 ≤ n ≤ 1 000). The following n lines contain n elements each, with element j of line i being the number of roads from city i to city j (a number between 0 and 10, inclusive). After that, there will be n lines. Each will contain n elements, with element j of line i being the answer from your friend for the number of length-2 paths from city i to city j; it will be an integer between 0 and 100 000 inclusive.</p>

<p>The test cases will finish with a line containing only the number zero (also preceded by a blank line).</p>

<p>Note: Large input file; use fast I/O routines.</p>

### 출력 

 <p>For each case, your program should output a line. The content of this line should be YES if your classmate’s solution to the assignment is right, and NO otherwise.</p>

