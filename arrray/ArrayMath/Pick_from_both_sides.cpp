/*
Idea:
- Nhận thấy bài toán sẽ cần so sánh các tổng con gồm B phần tử
    - Các tổng con này sẽ được lấy từ:
        B - k phần tử bên trái, k phần tử bên phải (0 <= k <= B)
    - Nếu ta so sánh bằng cách mỗi lần pick k phần tử bên phải và B - k phần tử bên trái
        rồi mới tính tổng thì ta thấy:
            1 vòng lặp duyệt k từ 0 đến B
                và 2 vòng lặp bên trong để tính tổng của 2 tập con (vì 2 tập con này có tổng lại là B phần tử)
                    ==> lặp lại O(B)
            ===> O(B*B) ==> vì B <= N ==> worst case: O(N*N)
===> ta dùng mảng cộng dồn để có thể xử lí câu chuyện tổng các mảng con
===> vì operator - là không đáng kể ==> O(1)
===> tính mảng cộng dồn ===> O(B)

===> Thời gian thuật toán: O(2B) (cả tính mảng cộng dồn lẫn việc duyệt tìm tổng con lớn nhất)
===> Space: O(2B)
*/
int Solution::solve(vector<int> &A, int B)
{
    vector<int> prefixSum(B + 1, 0), suffixSum(B + 1, 0);
    int N = A.size();
    int rs = INT_MIN;
    // tính mảng cộng dồn
    for (int i = 0; i < B; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + A[i];
        suffixSum[i + 1] = suffixSum[i] + A[N - 1 - i];
    }

    // tìm tổng con lớn nhất
    for (int i = 0; i < B; i++)
    {
        rs = max(rs, prefixSum[i] + suffixSum[B - i]);
    }

    return rs;
}
