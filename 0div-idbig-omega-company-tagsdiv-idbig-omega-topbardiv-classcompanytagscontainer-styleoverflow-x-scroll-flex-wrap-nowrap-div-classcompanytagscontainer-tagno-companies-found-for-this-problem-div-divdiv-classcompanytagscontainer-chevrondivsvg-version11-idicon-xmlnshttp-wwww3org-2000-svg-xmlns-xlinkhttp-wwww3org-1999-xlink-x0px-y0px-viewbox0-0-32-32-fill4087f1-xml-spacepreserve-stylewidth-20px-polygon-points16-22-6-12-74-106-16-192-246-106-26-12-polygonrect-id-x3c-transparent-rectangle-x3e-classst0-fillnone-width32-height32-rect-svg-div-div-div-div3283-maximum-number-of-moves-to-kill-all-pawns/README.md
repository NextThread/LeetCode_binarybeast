<h2><a href="https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3283. Maximum Number of Moves to Kill All Pawns</a></h2><h3>Hard</h3><hr><div><p>There is a <code>50 x 50</code> chessboard with <strong>one</strong> knight and some pawns on it. You are given two integers <code>kx</code> and <code>ky</code> where <code>(kx, ky)</code> denotes the position of the knight, and a 2D array <code>positions</code> where <code>positions[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> denotes the position of the pawns on the chessboard.</p>

<p>Alice and Bob play a <em>turn-based</em> game, where Alice goes first. In each player's turn:</p>

<ul>
	<li>The player <em>selects </em>a pawn that still exists on the board and captures it with the knight in the <strong>fewest</strong> possible <strong>moves</strong>. <strong>Note</strong> that the player can select <strong>any</strong> pawn, it <strong>might not</strong> be one that can be captured in the <strong>least</strong> number of moves.</li>
	<li><span>In the process of capturing the <em>selected</em> pawn, the knight <strong>may</strong> pass other pawns <strong>without</strong> capturing them</span>. <strong>Only</strong> the <em>selected</em> pawn can be captured in <em>this</em> turn.</li>
</ul>

<p>Alice is trying to <strong>maximize</strong> the <strong>sum</strong> of the number of moves made by <em>both</em> players until there are no more pawns on the board, whereas Bob tries to <strong>minimize</strong> them.</p>

<p>Return the <strong>maximum</strong> <em>total</em> number of moves made during the game that Alice can achieve, assuming both players play <strong>optimally</strong>.</p>

<p>Note that in one <strong>move, </strong>a chess knight has eight possible positions it can move to, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.</p>

<p><img src="https://assets.leetcode.com/uploads/2024/08/01/chess_knight.jpg" style="width: 275px; height: 273px;"></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">kx = 1, ky = 1, positions = [[0,0]]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/08/16/gif3.gif" style="width: 275px; height: 275px;"></p>

<p>The knight takes 4 moves to reach the pawn at <code>(0, 0)</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">8</span></p>

<p><strong>Explanation:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/08/16/gif4.gif" style="width: 320px; height: 320px;"></strong></p>

<ul>
	<li>Alice picks the pawn at <code>(2, 2)</code> and captures it in two moves: <code>(0, 2) -&gt; (1, 4) -&gt; (2, 2)</code>.</li>
	<li>Bob picks the pawn at <code>(3, 3)</code> and captures it in two moves: <code>(2, 2) -&gt; (4, 1) -&gt; (3, 3)</code>.</li>
	<li>Alice picks the pawn at <code>(1, 1)</code> and captures it in four moves: <code>(3, 3) -&gt; (4, 1) -&gt; (2, 2) -&gt; (0, 3) -&gt; (1, 1)</code>.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">kx = 0, ky = 0, positions = [[1,2],[2,4]]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Alice picks the pawn at <code>(2, 4)</code> and captures it in two moves: <code>(0, 0) -&gt; (1, 2) -&gt; (2, 4)</code>. Note that the pawn at <code>(1, 2)</code> is not captured.</li>
	<li>Bob picks the pawn at <code>(1, 2)</code> and captures it in one move: <code>(2, 4) -&gt; (1, 2)</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= kx, ky &lt;= 49</code></li>
	<li><code>1 &lt;= positions.length &lt;= 15</code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;= positions[i][0], positions[i][1] &lt;= 49</code></li>
	<li>All <code>positions[i]</code> are unique.</li>
	<li>The input is generated such that <code>positions[i] != [kx, ky]</code> for all <code>0 &lt;= i &lt; positions.length</code>.</li>
</ul>
</div>