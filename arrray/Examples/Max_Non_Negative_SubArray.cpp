/*
Idea:
- Tu prefix sum của mảng A
    + Neu gap con A[i] < 0 ==> sum dang tinh nen xet ve 0, update lai start va end va count
    + Neu A[i] >= 0:
        + update sum
        + kiem tra xem sum > maxSum khong:
            + true ===> cap nhat lai fstart, fend, maxSum
            + false --> check neu sum == maxSum, check do dai mang
                + neu do dai mang lon hon:
                    cap nhat do dai maxCount, fstart, fend
                + neu khong --> giuw nguyen
- Neu fstart == -1 va fend == -1 ===> mang chua toan so am ==> tra ve mang rong
Do phuc tap:
- Khong gian: O(n)
- Thoi gian: O(n)
*/
vector<int> Solution::maxset(vector<int> &A)
{
    vector<int> result;
    int n = A.size();
    int start = 0, end = -1, fstart = -1, fend = -1;
    int count = 0, maxCount = 0, i = 0;
    long long sum = 0, maxSum = 0;

    while (i < n)
    {
        if (A[i] >= 0)
        {
            sum += A[i];
            count++;
            end++;
        }

        if (sum > maxSum)
        {
            maxSum = sum;
            fstart = start;
            fend = end;
        }
        else if (sum == maxSum && count > maxCount)
        {
            maxCount = count;
            fstart = start;
            fend = end;
        }

        if (A[i] < 0)
        {
            sum = 0;
            count = 0;
            start = i + 1;
            end = i;
        }

        ++i;
    }

    if (fstart != -1 && fend != -1)
    {
        for (int j = fstart; j <= fend; j++)
            result.push_back(A[j]);
    }

    return result;
}
