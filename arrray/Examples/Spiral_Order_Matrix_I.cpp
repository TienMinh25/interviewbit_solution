/*
Idea: Gan giong ki thuat 2 con tro (do o day la mang 2 chieu nen ta dung 4 con tro)
    - Tao 4 bien top, bottom, left, right
    - Sau do duyet qua mang 2 chieu bang cac bien do, push vao mang ket qua va tra ve.
Example:
// [
//     [1, 2],
//     [3, 4],
//     [5, 6]
// ]
// t = 1, b = 2, r = 0, l = 0

// 1, 2 ===> t = 1
// 4, 6 ===> r = 0
// 5 ===> b = 1
// d = 4 A.get(b).get(i)
//  i = b; i>=t; i--

Time: O(M*N)
Space: O(M*N)
*/
vector<int> Solution::spiralOrder(const vector<vector<int>> &A)
{
    int top = 0, bottom = A.size();
    int left = 0, right = A[0].size();

    vector<int> result;

    while (top < bottom && left < right)
    {
        for (int i = left; i < right; i++)
            result.push_back(A[top][i]);

        ++top;

        for (int i = top; i < bottom; i++)
            result.push_back(A[i][right - 1]);

        --right;

        // phong truong hop array 2 chieu chi co 1 hang
        if (!(top < bottom && left < right))
            break;

        for (int i = right - 1; i >= left; --i)
            result.push_back(A[bottom - 1][i]);

        --bottom;

        for (int i = bottom - 1; i >= top; --i)
            result.push_back(A[i][left]);

        ++left;
    }

    return result;
}
