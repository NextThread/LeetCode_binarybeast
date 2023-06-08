# Permutations of a given string
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string <strong>S</strong>. The task is to print all <strong>unique </strong>permutations of the&nbsp;given string in lexicographically sorted order.</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>ABC</span>
<strong><span style="font-size: 18px;">Output:</span></strong>
<span style="font-size: 18px;">ABC ACB BAC BCA CAB CBA</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">Given string ABC has permutations in 6 </span>
<span style="font-size: 18px;">forms as ABC, ACB, BAC, BCA, CAB and CBA .</span>
</pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>ABSG</span>
<strong><span style="font-size: 18px;">Output:</span></strong>
<span style="font-size: 18px;">ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
</span><span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">Given string ABSG has 24 permutations.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>find_permutaion()&nbsp;</strong>which takes the string S as input parameter and returns a vector of string in lexicographical order.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(n! * n)<br></span><span style="font-size: 18px;"><strong>Expected Space&nbsp;Complexity:&nbsp;</strong>O(n! * n)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= length of string &lt;= 5</span></p></div>