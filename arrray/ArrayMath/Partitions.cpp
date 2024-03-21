/*
- Phân tích bài toán:
    + Cho mảng 1 chiều B gồm A phần tử
    + Đếm số lượng cách chia mảng này thành 3 phần mà tổng các phần tử bằng nhau
===> nhận thấy rằng việc tính tổng con phải tính khá nhiều ==> có thể giảm độ phức tạp từ O(n) --> O(1)
nhờ dùng prefix sum
===> Main idea:
    - Nhận thấy nếu muốn tìm 2 điểm sao cho 3 tổng của 3 mảng con này bằng nhau:
    ta gọi 3 tổng lần lượt là S1, S2, S3 ===> S1 + S2 + S3 = S (với S là tổng của mảng)
    --> Vậy làm sao tìm break point để thoả mãn bài toán?
    Ta duyệt mảng và tìm điểm break point đầu tiên i (thoả mãn điều kiện S1 = S / 3)
        + sau mỗi lần tìm được break point, duyệt từ i+1 lên để tìm điểm break point thứ 2
        sao cho S1 = S2 là oke.
*/

int Solution::solve(int A, vector<int> &B)
{
    vector<int> prefixSum(A + 1, 0);
    int result = 0, q = 1;

    for (int i = 1; i <= A; i++)
        prefixSum[i] = prefixSum[i - 1] + B[i - 1];

    if (prefixSum[A] % 3 != 0)
        return 0;
    else
        while (q < A)
        {
            int S1 = prefixSum[q];
            int S2 = prefixSum[A] - prefixSum[q];

            if (S1 == 2 * S2)
            {
                int j = 1;
                while (j < q)
                {
                    if (2 * prefixSum[j] == S1)
                        result++;
                    j++;
                }
            }
            q++;
        }
    return result;
}
