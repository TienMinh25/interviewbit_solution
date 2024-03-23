/*
- Idea: Đưa về bài toán tìm số 0 nhiều nhất ~ tìm tổng con lớn nhất 
cách đưa bài toán này về 1 dạng khá là hay, nên áp dụng cái Kadane's algo này nhiều 
hơn cho mấy bài bắt tìm 1 dãy con nào đó thoả mãn một tính chất nào đó=)))
    Sử dụng Kadane's algorithm
    Nếu gặp 0 thì ta + 1, gặp 1 thì ta -1
    Ta sẽ thực thi gồm 4 biến chính:
        curSum, maxSum, curLeft, rsLeft = 1, rsRight = 1;
        if (curSum > maxSum) --> cập nhật lại rsRight, và cập nhật maxSum
        if (curSum < 0) ---> cập lại lại curLeft và curSum = 0
Độ phức tạp thời gian: O(n)
Độ phức tạp không gian: O(1)
*/
vector<int> Solution::flip(string A) {
    int n = A.size();
    int curSum = 0, maxSum = 0, rsLeft = -1, rsRight = -1, curLeft = 0;
    for (int i = 0; i < n; i++)
    {
        curSum += (A[i] == '0' ? 1 : -1);
        if (curSum > maxSum)
        {
            maxSum = curSum;
            rsLeft = curLeft;
            rsRight = i;
        }
        if (curSum < 0)
        {
            curLeft = i + 1;
            curSum = 0;
        }
    }
    
    return maxSum == 0 ? vector<int>() : vector<int>{rsLeft + 1, rsRight + 1};
}
