/*
- Phân tích:
    + Cho 1 mảng A có N phần tử ( -1000 <= A[i] <= 1000 )
    + Cần tìm 1 mảng con liên tục có tổng nhất lớn 
- Idea:
    + Sử dụng Kadane's algorithm (khá là hay trong mặt ý tưởng)
    + Ta sẽ duyệt mảng:
        + curSum --> nhằm để mô hình hoá việc rút gọn mảng
            nghĩa là sao
            ví dụ:
            4 -1 2 -7 3 4
            Để ý rằng curSum đến chỗ -7 là -2
            thì lúc này ta sẽ ko quan tâm 4 con 4 -1 2 -7 nữa, lúc này ta tưởng tượng mảng như là:
                -2 3 4
            lúc này ta để ý, nếu muốn curSum luôn lớn nhất có thể ===> ta không muốn cộng phần âm vào
            phần đằng sau --> vì nếu như vậy thì kết quả sẽ kém đi
             ==> curSum = max(curSum + A[i], A[i])
        + maxSum --> luôn keep track of kết quả lớn nhất
            maxSum = max(maxSum, curSum);
        --> Kadane's algorithm (O(n))
*/
int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int curSum = 0;
    int maxSum = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        curSum = max(curSum + A[i], A[i]);
        maxSum = max(curSum, maxSum);
    }
    
    return maxSum;
}
