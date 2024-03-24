/*
- Phân tích đề bài:
    + Cho 1 mảng các log (dưới dạng string):
        + Mỗi 1 log có 1 word ở đầu dùng để identify
        + Mỗi log thì đều có space-delimited ở giữa các chữ
    + Có 2 loại logs: (đều trừ phần identifier ra)
        + Letter-logs: các từ đều chứa lowercase Eng
        + Digit-logs: các từ đều chứa digits
    ==> Hãy sắp xếp sao cho:
    + letter_logs đến trước tất cả digit-logs
    + letter-logs thì được sắp xếp tăng dần, nếu 2 phần bằng nhau thì sắp xếp theo identifier
    + The digit-logs thì giữ nguyên vị trí tương đối
- Ta sẽ áp dụng tư tưởng top down vào để giải quyết
    - Nhận thấy ta cần 1 hàm để so sánh cho letter_logs (hàm tuỳ chỉnh)
        + Việc so sánh này thì sẽ so sánh phần substring từ sau "-" đầu tiên
        (Cần tách được - đầu tiên thôi)
    - Ta cần 1 hàm để phân loại được letter_logs và digit_logs
        (Cần kiểm tra char đầu tiên sau "-" đầu tiên là chữ hay số)
        là số => digit_logs
        là chữ => letter_logs
    - Ta cần 1 hàm sắp xếp cho letter_logs (hàm sort thư viện)

Độ phức tạp:
    Thời gian: O(n*n*logn)
    Không gian: O(n)
*/
bool checkDigitLogs(string B)
{
    int i = 0;
    while (B[i] != '-')
        i++;
    if (isdigit(B[i + 1]))
        return true;
    return false;
}

bool comp(string B, string C)
{
    int i = 0, j = 0;
    while (B[i] != '-')
        i++;
    while (C[j] != '-')
        j++;
    string subB = B.substr(i + 1), identifierB = B.substr(0, i);
    string subC = C.substr(j + 1), identifierC = C.substr(0, j);

    if (subB == subC)
        return identifierB <= identifierC;
    return subB <= subC;
}

vector<string> Solution::reorderLogs(vector<string> &A)
{
    vector<string> digit_logs;
    vector<string> letter_logs;
    int n = A.size();

    for (int i = 0; i < n; i++)
        if (checkDigitLogs(A[i]))
            digit_logs.push_back(A[i]);
        else
            letter_logs.push_back(A[i]);

    sort(letter_logs.begin(), letter_logs.end(), comp);

    int k = digit_logs.size();
    for (int i = 0; i < k; i++)
        letter_logs.push_back(digit_logs[i]);

    return letter_logs;
}
