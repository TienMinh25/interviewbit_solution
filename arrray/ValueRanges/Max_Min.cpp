/*
Time complexity: O(n)
Space complexity: O(1)
*/
int Solution::solve(vector<int> &A)
{
    int maxElement = INT_MIN, minElement = INT_MAX;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        maxElement = max(maxElement, A[i]);
        minElement = min(minElement, A[i]);
    }

    return maxElement + minElement;
}
