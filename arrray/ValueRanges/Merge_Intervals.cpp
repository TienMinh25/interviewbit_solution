/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
Phân tích bài toán:
Bài toán cho 1 mảng chứa các intervals, và cho 1 interval mới
hãy chèn mảng mới đó vào và trả về (merge luôn nếu có thể)
- Gọi interval mới là x
   Gọi interval để đằng trước x là prevX
   Gọi interval đằng sau x là nextX
   Ta thấy:
       (prevStart, prevEnd)   (start, end)     (nextStart, nextEnd)
             prevX                 X               nextX
       Ta luôn xét prevEnd với start
                   end với nextStart
       Còn ở trường hợp prevStart và nextEnd thì chỉ cần lấy
           min ở prevStart, và max ở nextEnd
   Vì sắp xếp thời gian interval tăng dần theo start ===> nếu xét start với prevStart thì chỉ cần xét lần đầu
   tiên.

   - Có trường hợp đặc biệt cần xử lí:
       Nếu mảng không có phần tử nào thì chỉ việc push newInterval vào

Độ phức tạp:
   Thời gian: O(n)
   Không gian: O(n)
*/
vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int i = 0;
    vector<Interval> res;

    // nếu mảng A ko có phần tử nào thì đẩy interval vào
    if (n == 0)
    {
        res.push_back(newInterval);
    }
    else
    {
        // đẩy các interval có A[i].end < newInterval.start
        while (A[i].end < newInterval.start && i < n)
            res.push_back(A[i++]);

        // xử lí cho trường hợp nếu không có interval nào lớn hơn newInterval
        if (i == n)
        {
            res.push_back(newInterval);
            return res;
        }

        // xử lí cho trường hợp sau khi duyệt xong, các interval cần merge với newInterval
        while ((newInterval.start == A[i].end || A[i].start <= newInterval.end) && i < n)
        {
            newInterval.start = min(newInterval.start, A[i].start);
            newInterval.end = max(newInterval.end, A[i].end);
            i++;
        }

        res.push_back(newInterval);

        // các interval có start > end của newInterval được push vào
        while (i < n)
            res.push_back(A[i++]);
    }

    return res;
}
