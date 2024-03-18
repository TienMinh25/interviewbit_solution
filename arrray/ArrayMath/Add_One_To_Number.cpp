/*
Phân tích:
    - Bài toán này cho ra 1 số không âm dưới dạng mảng
    và yêu cầu trả về 1 mảng mới sau khi thêm 1
Idea:
    - Cũng ná ná ý tưởng giống bài n!
    - Ta sẽ lật ngược việc cộng 2 mảng lại ( 1 mảng A và 1 mảng 1)
    Ví dụ:
        [1, 2, 4]
    +
               1
    ===> [4, 2, 1]
          1
    Sau khi cộng xong thì ta lật ngược mảng kết quả là được
    ==> tuy nhiên để ý rằng việc có bao nhiêu số 0 ở đầu để là valid input
    ==> khi đảo ngược mảng, ta sẽ push phần từ trong mảng vừa cộng sao
    cho đó là phần tử đầu tiên khác 0
Do phuc tap
    Thoi gian: O(n)
    Khong gian: O(n)
*/
vector<int> Solution::plusOne(vector<int> &A)
{
    int n = A.size();
    vector<int> B;
    int k = 0;

    while (A[k] == 0)
        k++;

    // xu li cho truong hop mang A toan 0
    if (k == n)
    {
        B.push_back(1);
        return B;
    }

    for (int i = n - 1; i >= k; i--)
        B.push_back(A[i]);

    int carry = 0;
    int n1 = B.size();
    int res;
    for (int i = 0; i < n1; i++)
    {
        if (i == 0)
        {
            res = B[i] + 1;
            B[i] = res % 10;
            carry = res / 10;
        }
        else
        {
            res = B[i] + carry;
            B[i] = res % 10;
            carry = res / 10;
        }
    }

    // neu carry >= 10
    while (carry)
    {
        B.push_back(carry % 10);
        carry /= 10;
    }

    reverse(B.begin(), B.end());
    return B;
}
