/*
- Phân tích:
    + f(i, j) = |A[i] - A[j]| + |i - j|
    Ta thấy có 4 trường hợp:
     (A[i] + i) - (A[j] + j)  (1)
    -(A[i] - i) + (A[j] - j)  (2)
    (A[i] - i) - (A[j] - j)   (3)
    (-A[i] - i) + (A[j] + j)  (4)
Ta thấy (1) ~ (4), (2) ~ (3)
====> Lúc này ta chỉ cần tìm (A[i] - i) max và min
                    tương tự (A[i] + i ) max min
*/

int Solution::maxArr(vector<int> &A)
{
    int n = A.size();

    int minAdd, maxAdd, minMinus, maxMinus;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            minAdd = A[i];
            maxAdd = A[i];
            minMinus = A[i];
            maxMinus = A[i];
        }
        else
        {
            minAdd = min(minAdd, A[i] + i);
            maxAdd = max(maxAdd, A[i] + i);
            minMinus = min(minMinus, A[i] - i);
            maxMinus = max(maxMinus, A[i] - i);
        }
    }

    return max(maxAdd - minAdd, maxMinus - minMinus);
}
