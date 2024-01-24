<h2><a href="https://leetcode.com/problems/decode-xored-permutation/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1734. Decode XORed Permutation</a></h2><h3>Medium</h3><hr><div><p>There is an integer array <code>perm</code> that is a permutation of the first <code>n</code> positive integers, where <code>n</code> is always <strong>odd</strong>.</p>

<p>It was encoded into another integer array <code>encoded</code> of length <code>n - 1</code>, such that <code>encoded[i] = perm[i] XOR perm[i + 1]</code>. For example, if <code>perm = [1,3,2]</code>, then <code>encoded = [2,1]</code>.</p>

<p>Given the <code>encoded</code> array, return <em>the original array</em> <code>perm</code>. It is guaranteed that the answer exists and is unique.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> encoded = [3,1]
<strong>Output:</strong> [1,2,3]
<strong>Explanation:</strong> If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> encoded = [6,5,4,6]
<strong>Output:</strong> [2,4,1,5,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;&nbsp;10<sup>5</sup></code></li>
	<li><code>n</code>&nbsp;is odd.</li>
	<li><code>encoded.length == n - 1</code></li>
</ul>
</div>