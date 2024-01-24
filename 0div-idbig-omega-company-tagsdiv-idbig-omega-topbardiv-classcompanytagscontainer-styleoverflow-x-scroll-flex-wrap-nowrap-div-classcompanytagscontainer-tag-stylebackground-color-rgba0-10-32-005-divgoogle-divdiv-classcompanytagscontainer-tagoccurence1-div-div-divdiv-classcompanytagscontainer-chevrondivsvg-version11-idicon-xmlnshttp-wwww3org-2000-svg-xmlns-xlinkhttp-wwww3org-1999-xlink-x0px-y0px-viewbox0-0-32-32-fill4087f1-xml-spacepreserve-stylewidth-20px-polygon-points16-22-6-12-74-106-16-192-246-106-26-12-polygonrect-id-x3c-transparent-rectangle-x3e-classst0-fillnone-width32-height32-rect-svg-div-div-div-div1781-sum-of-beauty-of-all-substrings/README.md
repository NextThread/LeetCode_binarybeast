<h2><a href="https://leetcode.com/problems/sum-of-beauty-of-all-substrings/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Google</div><div class="companyTagsContainer--tagOccurence">1</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1781. Sum of Beauty of All Substrings</a></h2><h3>Medium</h3><hr><div><p>The <strong>beauty</strong> of a string is the difference in frequencies between the most frequent and least frequent characters.</p>

<ul>
	<li>For example, the beauty of <code>"abaacc"</code> is <code>3 - 1 = 2</code>.</li>
</ul>

<p>Given a string <code>s</code>, return <em>the sum of <strong>beauty</strong> of all of its substrings.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aabcb"
<strong>Output:</strong> 5
<strong>Explanation: </strong>The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aabcbaa"
<strong>Output:</strong> 17
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;=<sup> </sup>500</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>
</div>