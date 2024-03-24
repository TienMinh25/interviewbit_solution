/*
- Idea:
Nhận thấy rằng việc phải sắp xếp lại mảng A sao cho có dạng wave
==> Mà nếu có nhiều kết quả khác nhau thì ta nên trả về kết quả có thứ tự nhỏ nhất
    - Ta sẽ sắp xếp mảng tăng dần
    - Lúc này nhận thấy rằng, việc đổi chỗ muốn ra kết quả nhỏ nhất thì sẽ là đổi chỗ
    2 số gần nhất với nhau (vì chúng là nhỏ nhất để đưa ra kết quả nhỏ nhất) (1)
    - Ta không cần quan tâm đến việc a2 <= a3 hay a3 >= a4 hay a4 <= a5 nữa hay không,
    vì dãy đã sắp xếp, hiển nhiên:
        + Trước và sau khi đổi thì a3, a4 <= a5
        + trước khi đổi: a4 >= a3 nên khi đổi xong thì a3 >= a4
        (2)
    - Từ (1) và (2) ta thấy rằng hướng đi đã giải quyết được 2 vấn đề chính mà ta đã chia nhỏ.
- Độ phức tạp:
    Thời gian: O(nlogn)
    Không gian: O(1)
*/
vector<int> Solution::wave(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    for (int i = 0; i < n - 1; i += 2)
        swap(A[i], A[i + 1]);

    return A;
}
