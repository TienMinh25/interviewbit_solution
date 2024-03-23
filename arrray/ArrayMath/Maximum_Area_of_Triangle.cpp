/*
- Đề bài:
    Cho mảng 2 chiều N x M, mỗi phần tử chứa 1 trong 3 kí tự sau:
        'r' - red, 'g' - green, 'b' - blue
    ==> Hãy tìm tam giác có diện tích lớn nhất sao cho có 1 cạnh song song với trục Oy
    và 3 đỉnh là khác màu nhau.
- Phân tích bài toán:
    - Ta nhận thấy vì tam giác có 1 đỉnh song song với trục Oy ==> ta dùng công thức tính tam giác
    S = 1/2*a*h
    - Ta sẽ duyệt ờ mỗi cột để tìm ra chiều dài lớn nhất của đáy và 2 đỉnh tạo nên đáy sẽ khác màu nhau
    - Ở đây ta sẽ lưu lại theo hàng của col với 0 là r, 1 là g, 2 là b ---> để lấy được vị trí col
    - bài này ý tưởng sẽ là ko cần biết 3 màu ở 3 đỉnh là gì, chỉ cần biết nó maximum
Constraint:
    2 <= N, M <= 10^3
Độ phức tạp:
    Thời gian: O(M*N+M*M) -- giả sử N >= M ==> O(N*N)
    Không gian: O(3M)
*/
int calculate(int base, int curr_col, vector<int> col)
{
    int height;
    int M = col.size();
    int max_area = INT_MIN, curr_area;

    for (int j = 0; j < M; j++)
        if (col[j] && j != curr_col)
        {
            height = abs(j - curr_col) + 1;
            curr_area = ceil(height * base / double(2));
            max_area = max(max_area, curr_area);
        }
    return max_area;
}
int Solution::solve(vector<string> &A) {
    int N = A.size(), M = A[0].size();
    
    // vector lưu trữ các màu theo cột :)) nghĩa là màu nào có thì cột đó có col[k][j] tương ứng với cột j
    // với k = 0 - red, k = 1 - green, k = 2 - blue
    vector<vector<int> > col(3, vector<int> (M, 0));
    int max_global_area = 0, max_local_area;

    for (int j = 0; j < M; j++)
        for (int i = 0; i < N; i++)
        {
            if (A[i][j] == 'r')
                col[0][j] = 1;
            if (A[i][j] == 'g')
                col[1][j] = 1;
            if (A[i][j] == 'b')
                col[2][j] = 1;      
        }

    for (int j = 0; j < M; j++)
    {
        // điểm đầu của r,g,b với đánh dấu 0,1,2 tương ứng các màu 
        vector<int> first_rgb(3, -1);
        // điểm cuối của r,g,b với đánh dấu 0,1,2 tương ứng các màu 
        vector<int> last_rgb(3, -1);
        for (int i = 0; i < N; i++)
        {
            if (A[i][j] == 'r' && first_rgb[0] == -1)
                first_rgb[0] = i;
            if (A[i][j] == 'r')
                last_rgb[0] = i;
            if (A[i][j] == 'g' && first_rgb[1] == -1)
            {
                first_rgb[1] = i;
            }
            if (A[i][j] == 'g')
                last_rgb[1] = i;
            if (A[i][j] == 'b' && first_rgb[2] == -1)
            {
                first_rgb[2] = i;
            }
            if (A[i][j] == 'b')
                last_rgb[2] = i;
        }

        int curr_base;
        for (int i = 0; i < 3; i++)
            if (first_rgb[i] != -1)
                for (int k = 0; k < 3; k++)
                    if (k != i && last_rgb[k] != -1)
                    {
                        curr_base = abs(last_rgb[k] - first_rgb[i]) + 1;
                        max_local_area = calculate(curr_base, j, col[3 - i - k]);
                        max_global_area = max(max_local_area, max_global_area);
                    }
    }
    if (!max_global_area)
        return 0;
    return max_global_area;
}
