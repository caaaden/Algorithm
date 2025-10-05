# [Platinum III] Compress Words - 27485 

[문제 링크](https://www.acmicpc.net/problem/27485) 

### 성능 요약

메모리: 8048 KB, 시간: 40 ms

### 분류

문자열, KMP

### 제출 일자

2025년 10월 5일 19:53:56

### 문제 설명

<p>Amugae has a sentence consisting of <mjx-container class="MathJax" jax="CHTML" style="font-size: 104.6%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> words. He want to compress this sentence into one word. Amugae doesn’t like repetitions, so when he merges two words into one word, he removes the longest prefix of the second word that coincides with a suffix of the first word. For example, he merges “<code>sample</code>” and “<code>please</code>” into “<code>samplease</code>”.</p>

<p>Amugae will merge his sentence left to right (i.e. first merge the first two words, then merge the result with the third word and so on). Write a program that prints the compressed word after the merging process ends.</p>

### 입력 

 <p>The first line contains an integer <mjx-container class="MathJax" jax="CHTML" style="font-size: 104.6%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 104.6%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>n</mi><mo>≤</mo><msup><mn>10</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\le n\le 10^5$</span></mjx-container>), the number of the words in Amugae’s sentence.</p>

<p>The second line contains <mjx-container class="MathJax" jax="CHTML" style="font-size: 104.6%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> words separated by single space. Each words is non-empty and consists of uppercase and lowercase English letters and digits (‘<code>A</code>’, ‘<code>B</code>’, …, ‘<code>Z</code>’, ‘<code>a</code>’, ‘<code>b</code>’, …, ‘<code>z</code>’, ‘<code>0</code>’, ‘<code>1</code>’, …, ‘<code>9</code>’). The total length of the words does not exceed <mjx-container class="MathJax" jax="CHTML" style="font-size: 104.6%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>6</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^6$</span></mjx-container>.</p>

### 출력 

 <p>In the only line output the compressed word after the merging process ends as described in the problem.</p>

