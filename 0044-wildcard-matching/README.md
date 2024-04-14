<h2><a href="https://leetcode.com/problems/wildcard-matching">44. Wildcard Matching</a></h2><h3>Hard</h3><hr><p>Given an input string (<code>s</code>) and a pattern (<code>p</code>), implement wildcard pattern matching with support for <code>&#39;?&#39;</code> and <code>&#39;*&#39;</code> where:</p>

<ul>
	<li><code>&#39;?&#39;</code> Matches any single character.</li>
	<li><code>&#39;*&#39;</code> Matches any sequence of characters (including the empty sequence).</li>
</ul>

<p>The matching should cover the <strong>entire</strong> input string (not partial).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aa&quot;, p = &quot;a&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> &quot;a&quot; does not match the entire string &quot;aa&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aa&quot;, p = &quot;*&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;&#39;*&#39; matches any sequence.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cb&quot;, p = &quot;?a&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong>&nbsp;&#39;?&#39; matches &#39;c&#39;, but the second letter is &#39;a&#39;, which does not match &#39;b&#39;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length, p.length &lt;= 2000</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
	<li><code>p</code> contains only lowercase English letters, <code>&#39;?&#39;</code> or <code>&#39;*&#39;</code>.</li>
</ul>
<p> MEMOIZATION
Approach
solve Function: This recursive function is used to check if a substring of str starting from the first character to index i matches a substring of pattern starting from the first character to index j. The function takes the string str, the pattern pattern, the indices i and j, and a memoization table dp as input.

Base Cases: The function first checks for base cases:

If both i and j are less than 0, it means both str and pattern are empty, so it returns true.
If i is greater than or equal to 0 but j is less than 0, it means pattern is empty, so it returns false.
If j is greater than or equal to 0 but i is less than 0, it checks if the remaining characters in pattern (from index 0 to j) are all '*' characters. If yes, it returns true; otherwise, it returns false.
Memoization: Before proceeding with the recursive calls, the function checks if the result for the current i and j has already been computed and stored in the memoization table dp. If so, it directly returns the precomputed value to avoid redundant calculations.

Recursive Calls: If the base cases are not satisfied, the function checks for the following conditions:

If the current characters in str and pattern match (either the same character or '?' in the pattern), it makes a recursive call to solve with indices i-1 and j-1 to check the remaining substrings.
If the current character in pattern is '', it makes two recursive calls to solve:
One with index i-1 and the same index j to check if the '' matches a single character in str.
Another with the same index i and index j-1 to check if the '*' matches a sequence of characters in str.
If none of the above conditions match, it returns false, as the characters do not match.
Memoization Update: After the recursive calls, the function updates the memoization table dp with the result for the current i and j and returns the result.

isMatch Function: This function serves as an interface to call the solve function with the appropriate arguments. It initializes the memoization table dp, calls solve with s.length()-1, p.length()-1, and returns the result.

Complexity
Time complexity:0(N*M)
Space complexity:0(N*M)</p>
