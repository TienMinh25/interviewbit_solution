/*
Idea:
- Nhận thấy rằng bài toán này tính toán khá dễ, nhưng khả năng tràn số rất cao vì
    1 <= A <= 100
    Ví dụ: 50! ===> long long int, long long, int đều không thể chứa ==> overflow
- Bài này ý tưởng là nhân như nhân bằng tay :v
===> Phải tìm 1 container nào đó để chứa số:
- First solution: Chọn string
    String cx giống như mảng, nhưng khi thao tác với số, ta phải convert từ string ra ASCII rồi convert về số
    Ví dụ:
        char x = '3';
        int val = (int)x; ===> trả về số ASCII (giả sử là 52)
        lúc này muốn đưa về giá trị đúng của nó ta phải làm
        int val = (int)(x - '0');
        ===> khá phức tạp ==> sang lựa chọn thứ 2
- Second solution: Chọn array làm container
    ở đây ta cần lưu ý về mỗi khi nhân 1 số với 1 số thì kích thước của số có thay đổi không:
    Ví dụ:
        Khi ta đang tính 5! và đã tính đến 4! = 24
            24
           *
             5
           120
    ===> lúc này size thay đổi ===> ta phải cập nhật size để array có thể chứa
    ===> có 1 biến size trong thuật toán
    nhưng ta để ý rằng: (Nếu ta nhân theo chiều ngược lại). Ví dụ:
    1 * 2 = 2 (để 1 và 2 đều ở bên tay trái) (lấy giấy ra nhân bằng tay sẽ hiểu)
    2 * 3 = 6
    6 * 4 = 42 (lưu ý: nhân kết quả theo phía từ trái qua phải chứ kp từ phải qua trái)
    42 * 5 = 021
    ===> cuối cùng ta reverse lại array ==> 120 ==> vậy kết quả là 120
*/

void mutiple(vector<int> &arr, int &size, int x)
{
    int carry = 0;
    for (int k = 0; k < size; k++)
    {
        int res = arr[k] * x + carry;
        arr[k] = res % 10;
        carry = res / 10;
    }

    // carry > 0 ==> co the carry co 2 chu so ==> vi du truong hop 9 + 2 = 11 chang han
    while (carry > 0)
    {
        // dang le carry phai viet xuoi theo tu dau den duoi
        // nhung vi đang nhân ngược nên là sẽ lấy từ đuôi đến đầu
        arr[size++] = carry % 10;
        carry /= 10;
    }
}

string Solution::solve(int A)
{
    vector<int> arr(10000, 0);

    arr[0] = 1; // thiet lap ban dau so la 1

    int size = 1; // size ban dau cua so se la 1

    // i la so de nhan
    for (int i = 2; i <= A; i++)
    {
        mutiple(arr, size, i);
    }

    string s = "";

    for (int i = size - 1; i >= 0; i--)
    {
        // convert số thành char thì dùng arr[i] + '0'
        // hoặc dùng to_string(arr[i])
        // s += arr[i];
        s += to_string(arr[i]);
    }

    return s;
}
