/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1. 1 <= S.length <= 200
2. 1 <= T.length <= 200
3. S and T only contain lowercase letters and '#' characters.

Follow up:
Can you solve it in O(N) time and O(1) space?

*/

//Solution 1 Time : O(N+M)  space: O(N+M)

class Solution
{
public:
  bool backspaceCompare (string S, string T)
  {

    deque < char >q;

    for (int i = 0; i < S.size (); i++)
      {
	if (S[i] != '#')
	  {
	    q.push_back (S[i]);
	  }
	else if (!q.empty ())
	  {
	    q.pop_back ();
	  }
      }

    S = "";
    while (!q.empty ())
      {
	S += q.front ();
	q.pop_front ();
      }
    for (int i = 0; i < T.size (); i++)
      {

	if (T[i] != '#')
	  {
	    q.push_back (T[i]);
	  }
	else if (!q.empty ())
	  {
	    q.pop_back ();
	  }
      }

  T = "";
    while (!q.empty ())
      {
	T += q.front ();
	q.pop_front ();
      }
    q.clear ();
    if (S == T)
      return true;
    else
      return false;
  }
};


//solution 2 Time : O(M+N)  space: O(1)

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int i = S.length() - 1, j = T.length() - 1;
		int s_back = 0, t_back = 0;
		while (i >= 0 && j >= 0) {
			if (S[i] != '#' && T[j] != '#') {
				if (S[i] != T[j])
					return false;
				--i;
				--j;
			}
			else {
				if (S[i] == '#') {
					s_back = 1;
					--i;
					while (s_back > 0 && i >= 0) {
						if (S[i] == '#')
							++s_back;
						else
							--s_back;
						--i;
					}
				}
				if (T[j] == '#') {
					t_back = 1;
					--j;
					while (t_back > 0 && j >= 0) {
						if (T[j] == '#')
							++t_back;
						else
							--t_back;
						--j;
					}
				}
			}
		}
		while (i >= 0 && S[i] == '#') {
			s_back = 1;
			--i;
			while (s_back > 0 && i >= 0) {
				if (S[i] == '#')
					++s_back;
				else
					--s_back;
				--i;
			}
		}
		while (j >= 0 && T[j] == '#') {
			t_back = 1;
			--j;
			while (t_back > 0 && j >= 0) {
				if (T[j] == '#')
					++t_back;
				else
					--t_back;
				--j;
			}
		}
		if (i >= 0 || j >= 0)
			return false;
		return true;
	}
};
