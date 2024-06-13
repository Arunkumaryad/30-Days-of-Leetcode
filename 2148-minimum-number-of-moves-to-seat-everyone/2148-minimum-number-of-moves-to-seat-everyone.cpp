class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int n = seats.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            cnt  +=  abs(seats[i]-students[i]);
        }
        return cnt;
    }
};