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
    ===> ta cần lưu trữ lại độ dài và 2 màu đó là 2 màu gì ==> để tìm được màu còn lại là đỉnh của tam giác (1)
    ---> xử lí bằng cách gán các đỉnh lại bằng 1 số ===> khi tìm đỉnh còn lại trên tam giác thì dễ tìm hơn
    (Ở đây làm sao ta làm được điều này ---> ta sẽ chọn mốc 1 trong 2 đầu để tìm, để tìm sao cho đáy là lớn
    nhất
    để ý ở đây có 1 trường hợp đặc biệt, nếu có 2 cặp mốc thoả mãn điều này, khi này xảy ra trường hợp:
    + Lấy cặp mốc 1: (R,B) --> lỡ ở đỉnh xa nhất ko có G
    + Lấy cặp mốc 2: (G,B) hoặc (G,R) --> ở đỉnh xa nhất có đỉnh còn lại là B hoặc R 
    ===> nếu lấy cặp mốc 1 thì ta sai ==> ta phải cover case này nữa.
    )
    
    - Sau đó thì ta duyệt qua các cột, và tìm đỉnh còn lại ở các cột khác (không trùng với cột đang xét làm 
    đáy). Ở đây chọn đỉnh nào khác màu 2 đỉnh làm đáy đều được --> vì cơ bản h không đổi --> giống nhau:
    
    TH đặc biệt: tất cả các đỉnh đều 1 màu, hoặc không tạo nên được tam giác nào thoả mãn (ví dụ chỉ
    có 2 đỉnh khác, không thoả mãn song song với Oy)
    ---> (1) sẽ xử lí
    
    Ta quy đổi: R - 1
                G - 2
                B - 3
Constraint:
    2 <= N, M <= 10^3
Độ phức tạp:
    Thời gian: O(M*N)
    Không gian: O(3M)
*/
int calculate(int base, int curr_col, vector<int> col)
{
    int height;
    int M = col.size();
    int max_area = INT_MIN, curr_area;

    for (int j = 0; j < M; j++)
        if (col[j])
        {
            height = abs(j - curr_col) + 1;
            curr_area = ceil(height * base / double(2));
            max_area = max(max_area, curr_area);
        }
    return max_area;
}
int Solution::solve(vector<string> &A) {
    int N = A.size(), M = A[0].size();
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
        vector<int> first_rgb(3, -1);
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
