#include <bits/stdc++.h>
using namespace std;

int maxSumMatrix(int n, int m, vector<vector<int>> &mat, int val) {
    // Create prefix sum matrix
    vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    // Function to get sum of square with top-left at (r, c) and side length 'side'
    auto getSquareSum = [&](int r, int c, int side) -> long long {
        int r2 = r + side - 1;
        int c2 = c + side - 1;
        return prefix[r2+1][c2+1] - prefix[r][c2+1] - prefix[r2+1][c] + prefix[r][c];
    };
    
    // Function to check if we can find a square of given side length with sum <= val
    auto canFormSquare = [&](int side) -> bool {
        for (int i = 0; i <= n - side; i++) {
            for (int j = 0; j <= m - side; j++) {
                if (getSquareSum(i, j, side) <= val) {
                    return true;
                }
            }
        }
        return false;
    };
    
    // Binary search on the answer
    int left = 0;
    int right = min(n, m);
    int ans = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canFormSquare(mid)) {
            ans = mid;
            left = mid + 1; // try to find larger square
        } else {
            right = mid - 1; // need smaller square
        }
    }
    
    return ans;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        
        int val;
        cin >> val;
        
        cout << maxSumMatrix(n, m, mat, val) << endl;
    }
    
    return 0;
}
