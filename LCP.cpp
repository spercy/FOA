//time complexity = O(m*n)
//space complexity = O(m*n)

// by subsequence, it means the values must occur in the order of the sequence, but they don't need to be consecutive.

//  Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 

//X and Y be two given sequences
//Initialize a table LCS of dimension X.length * Y.length
//X.label = X
//Y.label = Y
//LCS[0][] = 0
//LCS[][0] = 0
//Start from LCS[1][1]
//Compare X[i] and Y[j]
    //If X[i] = Y[j]
        //LCS[i][j] = 1 + LCS[i-1, j-1]   
        //Point an arrow to LCS[i][j]
    //Else
        //LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])
        //Point an arrow to max(LCS[i-1][j], LCS[i][j-1])

// Returns length of LCS for X[0..m-1], Y[0..n-1]
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size(), m = text2.size();
        
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        //To populate the table, the outer for loop iterates m times and the inner for loop iterates n times. Hence, the complexity of the algorithm is O(m, n), where m and n are the length of two strings.
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};

// asymptotic bound for the time taken by the dynamic programming longest common subsequence algorithm on sequences of length m and n
    // O(m*n)

//worst-case running time of brute force approach would be O(n*2^m)
