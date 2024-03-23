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
 Tư tưởng gần giống với bài Merge Intervals
 Xem A[0] la newInterval là oke : )
 */
bool comp(Interval a, Interval b){
    return a.start <= b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), comp);
    Interval newInterval = A[0];
    vector<Interval> res;
    int n = A.size(), i = 1;
    
    if (n == 1)
        res.push_back(newInterval);
    else {
        while (i < n){
            // nếu phần tử cuối được merge vào cùng thì lúc ra thì i sẽ là n rồi
            while (newInterval.end >= A[i].start && i < n)
            {
                newInterval.end = max(newInterval.end, A[i].end);
                newInterval.start = min(newInterval.start, A[i].start);
                i++;
            }
            // đẩy vào mảng kết quả con đã được merge 
            res.push_back(newInterval);
            
            // nếu i ra ngoài là n - 1, tức là còn 1 con cuối ==> đẩy vào mảng kết quả luôn
            // vì không còn con nào để merge interval nữa
            if (i == n - 1)
                res.push_back(A[i]);
            else if (i < n - 1) // nếu không thì cập nhật lại newInterval để tiếp tục merge
                newInterval = A[i];
            // tăng i lên 1 để bắt đầu tính merge từ newInterval
            i++;
        }
    }
    
    return res;
}
