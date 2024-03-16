/*
- Idea:
    - Phân tích bài toán ta thấy:
        + Ta có 1 mảng gồm n bóng đèn, bóng đèn ở vị trí thứ i có A[i] = 1 -> đèn bình thường
                                                                  A[i] = 0 -> đèn hỏng không sáng được
        + Mỗi đèn đều có công suất B ---> 1 đèn sẽ chiếu sáng được [X-B+1, X+B-1] với X là vị trí của đèn
        ===> nó có thể chiếu là 2B-1 khu vực bao gồm chính nó nằm giữa
        ===> Cần tìm số bóng đèn tối thiểu để sáng hết con đường n này
    - Ta thấy rằng, đối với mỗi đèn hoạt động khi xét, ta xét đến khoảng sáng bên trái và bên phải:
        + Nhận thấy ở bóng đầu tiên cần tìm:
            + Ta cần tìm bóng phải nhất từ vị trí B-1 đổ về sao cho i - B + 1 <= 0
        + Xét để lấy bóng cần bật tiếp theo:
            + Nhận thấy rằng để cả con đường sáng, thì ta cần tìm bóng ở vị trí thứ j bên phải nhất
            sao cho j thuộc từ [i + 1, right + B - 1] với right = i + B - 1;
            vì sao chỗ right + B lại trừ 1 là vì cách đánh index của array là từ 0
            (Vì sao lại như vậy) ==> vì ta cần tìm sự giao nhau giữa 2 khoảng cách của 2 đèn.
*/

int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    // neu ca day A deu bang 0 thi xu li bang left roi
    int right;
    int count = 0;
    int lastIndexOne = -1;

    // tim khoang cach dau
    for (int i = B - 1; i >= 0; i--)
    {
        // truong hop check cho A[i] dau tien co left <= 0
        if (A[i] == 1 && i - B + 1 <= 0)
        {
            lastIndexOne = i;
            right = i + B - 1;
            count++;
            break;
        }
    }

    if (lastIndexOne == -1)
        return -1;

    // nếu phần tử đầu tiên bao gồm được cả đoạn đường thì trả về luôn
    // xử lí cho trường hợp [1,1,1,1] và B = 3
    if (right >= n - 1)
        return count;

    // từ lastIndexOne mong muốn tìm con 1 phải nhất thoả mãn trong đoạn từ lastIndexOne+1 đến right + B - 1
    int temp = lastIndexOne;
    for (int j = lastIndexOne + 1; j < n;)
    {
        while (j <= right + B - 1 && j < n)
        {
            if (A[j] == 1)
            {
                lastIndexOne = j;
            }
            j++;
        }
        if (lastIndexOne == temp)
            return -1;
        else
        {
            count++;
            right = lastIndexOne + B - 1;
            // nếu ở tại vị trí bóng bất kì, mà con right >= n - 1 thì ta trả về luôn
            if (right >= n - 1)
                return count;
        }
    }

    // nếu đến bóng cuối cùng bên phải nhất trong dãy không bao trùm được phần bên phải đường
    // ===> không thể chiếu sáng hết con đường
    if (right < n - 1)
        return -1;

    return count;
}
