// A certain bug's home is on the x-axis at position x. Help them get there from position 0.

// The bug jumps according to the following rules:

//     It can jump exactly a positions forward (to the right).
//     It can jump exactly b positions backward (to the left).
//     It cannot jump backward twice in a row.
//     It cannot jump to any forbidden positions.

// The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

// Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no possible sequence of jumps that lands the bug on position x, return -1.

  unordered_set<int> fob;

    int dp[7001][2];
    int solver(int pos, int &home, int &a, int &b, bool left)
    {
        if(pos == home)return 0;
        if(pos < 0 || pos > 7000 || fob.find(pos) != fob.end())return 1e9;
        if(dp[pos][left] != -1) return dp[pos][left];
        
        dp[pos][left] = 1 + solver(pos + a, home, a, b, false);
        if(!left)
        {
            dp[pos][left] = min(dp[pos][left], 1 + solver(pos - b, home, a, b, true));
        }
        return dp[pos][left];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto i: forbidden)fob.insert(i);
        memset(dp, -1, sizeof(dp));
        int ans = solver(0, x, a, b, false);
        return (ans >= 1e9)? -1: ans;
    }
