# Sum of all divisors from 1 to n
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a positive integer <strong>N</strong>., The task is to find the value of <strong>Σ<sub>i from 1 to N </sub></strong></span><span style="font-size: 18px;"><strong>F(i)</strong> where function </span><em style="font-size: 18px;"><strong>F(i)</strong></em><span style="font-size: 18px;"> for the number </span><strong style="font-size: 18px;">i</strong><span style="font-size: 18px;"> is defined as the sum of all divisors of </span><strong style="font-size: 18px;">i</strong><span style="font-size: 18px;">.</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:
N = 4</span></strong>
<strong><span style="font-size: 18px;">Output:
</span></strong><span style="font-size: 18px;">15</span>
<span style="font-size: 18px;"><strong>Explanation:</strong>
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
ans = F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7
    = 15</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:
</span></strong><span style="font-size: 18px;">N = 5</span>
<strong><span style="font-size: 18px;">Output:
</span></strong><span style="font-size: 18px;">21</span>
<strong><span style="font-size: 18px;">Explanation:
</span></strong><span style="font-size: 18px;">F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
F(5) = 1 + 5 = 6
ans = F(1) + F(2) + F(3) + F(4) + F(5)
    = 1 + 3 + 4 + 7 + 6
    = 21</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>sumOfDivisors()</strong>&nbsp;which takes an integer <strong>N</strong> as an input parameter and returns an integer.<br><br><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>6</sup></span></p></div>