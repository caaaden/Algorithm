# [Gold I] ソフトクリーム (Softcream) - 33175 

[문제 링크](https://www.acmicpc.net/problem/33175) 

### 성능 요약

메모리: 4376 KB, 시간: 108 ms

### 분류

정렬, 게임 이론

### 제출 일자

2025년 7월 14일 23:55:01

### 문제 설명

<p>Alice と Bob はソフトクリーム屋さん JOICE に来ている．この店では，客がフレーバー・コーン・トッピングをそれぞれひとつずつ選ぶことによって，ソフトクリームを注文する．</p>

<ul>
	<li>フレーバーは <var>X</var> 種類あり，値段はそれぞれ <var>A<sub>1</sub>, A<sub>2</sub>, …, A<sub>X</sub></var> である．</li>
	<li>コーンは <var>Y</var> 種類あり，値段はそれぞれ <var>B<sub>1</sub>, B<sub>2</sub>, …, B<sub>Y</sub></var> である．</li>
	<li>トッピングは <var>Z</var> 種類あり，値段はそれぞれ <var>C<sub>1</sub>, C<sub>2</sub>, …, C<sub>Z</sub></var> である．</li>
</ul>

<p>ソフトクリームの値段は選んだフレーバー・コーン・トッピングの値段の合計となる．ここで，与えられた整数 <var>P</var> に対して，ソフトクリームの <strong>スコア</strong> をその値段と <var>P</var> との差の絶対値とする．</p>

<p>Alice と Bob は <var>2</var> 人で <var>1</var> つのソフトクリームを注文しようとしているが，<var>2</var> 人がどんなソフトクリームを注文したいかは真逆である．具体的には，Alice はスコアを最大化することを，Bob はスコアを最小化することを目的としている．そこで，以下の方法で，注文するソフトクリームのフレーバー・コーン・トッピングを選ぶことにした．</p>

<ol>
	<li>最初に，Alice がフレーバーを選ぶ．</li>
	<li>次に，Bob がコーンを選ぶ．</li>
	<li>最後に，Alice がトッピングを選ぶ．</li>
</ol>

<p>フレーバー，コーン，トッピングに関する情報および整数 <var>P</var> が与えられたとき，両者が各選択で最善を尽くした場合に最終的に注文するソフトクリームのスコアを求めるプログラムを作成せよ．</p>

### 입력 

 <p>入力は以下の形式で与えられる．</p>

<pre><var>X</var> <var>Y</var> <var>Z</var> <var>P</var>
<var>A<sub>1</sub></var> <var>A<sub>2</sub></var> <var>…</var> <var>A<sub>X</sub></var>
<var>B<sub>1</sub></var> <var>B<sub>2</sub></var> <var>…</var> <var>B<sub>Y</sub></var>
<var>C<sub>1</sub></var> <var>C<sub>2</sub></var> <var>…</var> <var>C<sub>Z</sub></var></pre>

### 출력 

 <p>最終的に注文するソフトクリームのスコアを <var>1</var> 行で出力せよ．</p>

