# [Gold I] 買い物 2 (Shopping 2) - 31619 

[문제 링크](https://www.acmicpc.net/problem/31619) 

### 성능 요약

메모리: 25380 KB, 시간: 244 ms

### 분류

자료 구조, 세그먼트 트리, 이분 탐색, 누적 합

### 제출 일자

2025년 7월 11일 05:46:05

### 문제 설명

<p>JOI 商店には <var>N</var> 個の商品があり，商品には <var>1</var> から <var>N</var> までの番号が付けられている．</p>

<p>それぞれの商品には，<strong>定価</strong>と<strong>種類</strong>が定められている．商品 <var>i</var> (<var>1 ≦ i ≦ N</var>) の定価は <var>P<sub>i</sub></var> 円である．商品の種類は <var>1</var> 以上 <var>M</var> 以下の整数で表され，商品 <var>i</var> (<var>1 ≦ i ≦ N</var>) の種類は <var>A<sub>i</sub></var> である．</p>

<p>JOI 商店は，セールを行うことにした．セールは <var>M</var> 日間続き，<var>j</var> 日目 (<var>1 ≦ j ≦ M</var>) には種類 <var>j</var> の商品をすべて定価の半額で買うことができる．</p>

<p>セールの期間中に，<var>Q</var> 人の客が JOI 商店を訪れた．客には <var>1</var> から <var>Q</var> までの番号が付けられている．客 <var>k</var> (<var>1 ≦ k ≦ Q</var>) はセールの <var>T<sub>k</sub></var> 日目に JOI 商店を訪れ，商品 <var>L<sub>k</sub>, L<sub>k+1</sub>, …, R<sub>k</sub></var> を <var>1</var> つずつ買った．</p>

<p>セールの効果を調査するため，それぞれの客が商品を買うのにかかった金額を知りたい．</p>

<p>商品の情報と客の情報が与えられたとき，それぞれの客が商品を買うのにかかった金額を求めるプログラムを作成せよ．</p>

### 입력 

 <p>入力は以下の形式で与えられる．</p>

<pre><var>N</var>   <var>M</var>   <var>Q</var>
<var>P<sub>1</sub></var>   <var>A<sub>1</sub></var>
<var>P<sub>2</sub></var>   <var>A<sub>2</sub></var>
<var>︙</var>
<var>P<sub>N</sub></var>   <var>A<sub>N</sub></var>
<var>T<sub>1</sub></var>   <var>L<sub>1</sub></var>   <var>R<sub>1</sub></var>
<var>T<sub>2</sub></var>   <var>L<sub>2</sub></var>   <var>R<sub>2</sub></var>
<var>︙</var>
<var>T<sub>Q</sub></var>   <var>L<sub>Q</sub></var>   <var>R<sub>Q</sub></var></pre>

### 출력 

 <p><var>Q</var> 行出力せよ．<var>k</var> 行目 (<var>1 ≦ k ≦ Q</var>) には，客 <var>k</var> が商品を買うのにかかった金額を，単位 (円) を省いて出力せよ．</p>

