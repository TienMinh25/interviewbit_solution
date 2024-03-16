/*
- Idea:
C1: (Cách này ko pass đâu : )))
    + Ta dùng duyệt trâu 3 vòng for để tìm các cặp i, j, k thoả mãn
C2: Cách này oke này
    + Ta sẽ coi phần tử nào cx là phần tử ở giữa trong cặp (i, j, k)
    ---> tức là coi phần tử đó luôn là j
    ===> lúc này ta chỉ việc tìm bên trái và bên phải số A[i] < A[j] và số A[k] > A[j] mà lớn nhất
        trong dãy đó
        - Với bên trái: ta dùng set để duy trì thứ tự, thì ta chỉ việc tìm số >= số đang xét ==> trừ
        đi 1 của address operator thì ta sẽ tìm được số lớn nhất mà bé hơn A[i] đang xét
        ==> nếu không tìm thấy thì nó là it.end();
        - Với bên phải: ta chỉ việc duy trì 1 mảng right duyệt từ phải qua trái để lưu trữ được
        phần tử right[i+1] luôn là phần tử lớn nhất bên phải khi đang xét từ A[i], lúc này ta chỉ việc
        so sánh right[i+1] và A[i].
    ===> Nếu thoả mãn điều kiện cả thì cập nhật lại ans
*/
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    set<int> left;
    vector<int> right(n + 1, 0);
    int ans = INT_MIN;
    bool check_exist_triplet = false;

    left.insert(A[0]);
    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = max(right[i + 1], A[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        // xem i luon la phan tu giua
        auto it = left.lower_bound(A[i]);
        it--;

        if (right[i + 1] > A[i])
        {
            check_exist_triplet = true;
            ans = max(ans, *it + A[i] + right[i + 1]);
        }

        left.insert(A[i]);
    }

    if (!check_exist_triplet)
        return 0;

    return ans;
}
