/*
- Idea:
    - Phân tích bài toán thấy rằng:
        + Tại một vị trí sẽ di chuyển được 8 hướng
        + Mỗi lần đi chỉ đc chọn 1 trong 8 hướng
        + Vì bài toán này cần tìm min steps để đi qua được hết các điểm đã liệt kê
    ===> Bài toán này sẽ luôn đi đường chéo từ điểm đang xét bất kì cho đến khi
        x[i+1] = x[i] + k (1) hoặc y[i+1] = y[i] + k (2)
        Sau đó chỉ việc di chuyển thẳng thêm c đơn vị sao cho:
        + nếu (1) xảy ra ===> sao cho y[i+1] = y[i] + k + c
        + nếu (2) xảy ra ===> sao cho x[i+1] = x[i] + k + c
    ===> Ta nhận thấy rằng nếu khoảng cách của x xa hơn thì tổng bước đi từ điểm A đến B
    sẽ bằng chính x[i+1] - x[i] = k + c (k + c là bước đi từ điểm A đến điểm B)
    điều này tương tự so với y
    ===> Từ phân tích:
    khởi tạo 1 biến rs
    lặp qua mảng A và B
        ở mỗi lần lặp, kiểm tra xem A[i+1] - A[i] >= B[i+1] - B[i] hay không
            đúng: rs = rs + A[i+1] - A[i];
            sai: rs = rs + B[i+1] - B[i];
        vì sao lại như thế thì nhưu trên đã phân tích

Chú ý rằng: Vì số bước đi luôn dương nhưng toạ độ trừ đi nhau có thể âm ==> phải dùng trị tuyệt đối
*/
int Solution::coverPoints(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int rs = 0;

    for (int i = 0; i < n - 1; i++)
    {
        // vi so buoc di luon duong nen phai lay tri tuyet doi cua khoang cach 2 toa do
        if (abs(A[i + 1] - A[i]) >= abs(B[i + 1] - B[i]))
            rs += abs(A[i + 1] - A[i]);
        else
            rs += abs(B[i + 1] - B[i]);
    }
    return rs;
}
