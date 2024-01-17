<h2><a href="https://leetcode.com/problems/execute-asynchronous-functions-in-parallel/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2721. Execute Asynchronous Functions in Parallel</a></h2><h3>Medium</h3><hr><div><p>Given an array of&nbsp;asynchronous functions&nbsp;<code>functions</code>, return a new promise <code>promise</code>. Each function in the array accepts no arguments&nbsp;and returns a promise. All the promises should be executed in parallel.</p>

<p><code>promise</code> resolves:</p>

<ul>
	<li>When all the promises returned from&nbsp;<code>functions</code>&nbsp;were resolved successfully in parallel.&nbsp;The resolved&nbsp;value of&nbsp;<code>promise</code> should be an array of all the resolved values of promises in the same order as they were in the&nbsp;<code>functions</code>. The <code>promise</code> should resolve when all the asynchronous functions in the array have completed execution in parallel.</li>
</ul>

<p><code>promise</code> rejects:</p>

<ul>
	<li>When any&nbsp;of the promises&nbsp;returned from&nbsp;<code>functions</code>&nbsp;were rejected.&nbsp;<code>promise</code> should also&nbsp;reject&nbsp;with the reason of the first rejection.</li>
</ul>

<p>Please solve it without using the built-in&nbsp;<code>Promise.all</code>&nbsp;function.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> functions = [
&nbsp; () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(5), 200))
]
<strong>Output:</strong> {"t": 200, "resolved": [5]}
<strong>Explanation:</strong> 
promiseAll(functions).then(console.log); // [5]

The single function was resolved at 200ms with a value of 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> functions = [
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(1), 200)), 
    () =&gt; new Promise((resolve, reject) =&gt; setTimeout(() =&gt; reject("Error"), 100))
]
<strong>Output:</strong> {"t": 100, "rejected": "Error"}
<strong>Explanation:</strong> Since one of the promises rejected, the returned promise also rejected with the same error at the same time.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> functions = [
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(4), 50)), 
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(10), 150)), 
    () =&gt; new Promise(resolve =&gt; setTimeout(() =&gt; resolve(16), 100))
]
<strong>Output:</strong> {"t": 150, "resolved": [4, 10, 16]}
<strong>Explanation:</strong> All the promises resolved with a value. The returned promise resolved when the last promise resolved.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>functions</code>&nbsp;is an array of functions that returns promises</li>
	<li><code>1 &lt;= functions.length &lt;= 10</code></li>
</ul>
</div>