/*
- Phân tích bài toán:
    + Bài này muốn ta trả về 1 nếu tồn tại số p sao cho số lượng số lớn hơn p chính bằng p
    ==> ta thấy rằng bài toán này nên sắp xếp và tìm kiếm theo upper_bound (giá trị nhỏ nhất, đầu tiên (x)
    lớn hơn p từ trái qua phải)
    ==> sau đó ta chỉ việc kiểm tra A.end() - pos == A[i] hay không (pos là iterator trỏ đến giá trị x)
- Độ phức tạp
    Thời gian: O(nlogn)
    Không gian: O(1)

* Lưu ý: Trường hợp đặc biệt: nếu có số 0 ở cuối dãy (tức 0 là số lớn nhất)
thì ko có số nào lớn hơn 0 cũng là 1 đáp án thoả mãn.
Vì không có số nào lớn hơn 0 = 0
*/
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    // sap xep mang A
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++)
    {
        auto posGreaterThanCurrent = upper_bound(A.begin(), A.end(), A[i]);
        if (A.end() - posGreaterThanCurrent == A[i])
            return 1;
    }
    return -1;
}
