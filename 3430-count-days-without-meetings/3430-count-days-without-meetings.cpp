#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.empty()) {
            return days; // If there are no meetings, all days are available
        }

        // Sort meetings by start day
        sort(meetings.begin(), meetings.end());

        int availableDays = 0;
        int lastEnd = 0;

        for(const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            // Count the gap between the last meeting end and the current meeting start
            if (start > lastEnd + 1) {
                availableDays += (start - lastEnd - 1);
            }

            // Update lastEnd to the farthest end day
            lastEnd = max(lastEnd, end);
        }

        // Count the days after the last meeting ends
        if (lastEnd < days) {
            availableDays += (days - lastEnd);
        }

        return availableDays;
    }
};
