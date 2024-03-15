/*
Idea:
C1: - Bài này ý tưởng là dùng hash table
===> Mình sẽ biến A[i] thành index trong array mới - array này có độ lớn là O(maxSize)
    newArray[maxSize]
    Duyệt qua mảng ban đầu
        ==> Cập nhật newArray[A[i]]++ mỗi khi đi qua value A[i]
    Sau khi cập nhật xong, ta chỉ việc duyệt qua mảng newArray này
    và push các giá trị lớn hơn 0 vào mảng kết quả (rs)
    rồi trả về

    - Cách này thành công vì constraint dữ liệu trong mảng đều là các số nguyên >= 1
    Nhưng cách này sẽ bị runtime error vì index tạo ra quá lớn cho bộ nhớ
    vì max sẽ là tạo 1e9 + 3
C2: Cũng làm giống cách trên, nhưng thay vì dùng array, ta dùng map : ))
    Mục đich dùng map: vì nó sắp xếp theo key, và ta lấy value của array làm key
    rất phù hợp để xử lí việc cần in ra mảng số lần lặp theo chiều tăng dần của value
    ===> với map khi sắp xếp mỗi lần thêm: Độ phức tạp: O(log n)
    Và vì duyệt qua từng phần tử của A để thêm vào map
    ====> O(nlogn)
Độ phức tạp giải thuật: O(nlogn)
Độ phức tạp về không gian: O(2n)
*/
vector<int> Solution::findOccurences(vector<int> &A)
{
    vector<int> rs;

    map<int, int> hashTable;

    for (auto x : A)
        hashTable[x]++;

    for (map<int, int>::iterator x = hashTable.begin(); x != hashTable.end(); x++)
        rs.push_back(x->second);

    return rs;
}
