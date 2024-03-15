/*
* Idea:
    - TH1: Nhận thấy nếu B == A.size() thì mảng sau khi rotate sẽ như mảng ban đầu
    - TH2:
        + Nếu n < B ==> phân tích và đưa B về 1 số k < n
        + Nếu n > B ==> giữ nguyên B
            + Sau đó thì rotate mảng
===> Do phuc tap cua thuat toan:
Space: O(n)
Time: O(n)
*/
vector<int> Solution::rotateArray(vector<int> &A, int B)
{
    vector<int> ret;

    int n = A.size();

    if (n == B)
        return A;

    if (n < B)
        B = B % n;

    for (int i = B; i < n; i++)
        ret.push_back(A[i]);
    for (int i = 0; i < B; i++)
        ret.push_back(A[i]);

    return ret;
}
