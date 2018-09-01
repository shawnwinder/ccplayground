// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * [902] Minimum Number of Refueling Stops
 *
 * https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
 *
 * algorithms
 * Hard (26.00%)
 * Total Accepted:    3.3K
 * Total Submissions: 12.6K
 * Testcase Example:  '1\n1\n[]'
 *
 * A car travels from a starting position to a destination which is target
 * miles east of the starting position.
 *
 * Along the way, there are gas stations.  Each station[i] represents a gas
 * station that is station[i][0] miles east of the starting position, and has
 * station[i][1] liters of gas.
 *
 * The car starts with an infinite tank of gas, which initially has startFuel
 * liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.
 *
 * When the car reaches a gas station, it may stop and refuel, transferring all
 * the gas from the station into the car.
 *
 * What is the least number of refueling stops the car must make in order to
 * reach its destination?  If it cannot reach the destination, return -1.
 *
 * Note that if the car reaches a gas station with 0 fuel left, the car can
 * still refuel there.  If the car reaches the destination with 0 fuel left, it
 * is still considered to have arrived.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 1, startFuel = 1, stations = []
 * Output: 0
 * Explanation: We can reach the target without refueling.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: target = 100, startFuel = 1, stations = [[10,100]]
 * Output: -1
 * Explanation: We can't reach the target (or even the first gas station).
 *
 *
 *
 * Example 3:
 *
 *
 * Input: target = 100, startFuel = 10, stations =
 * [[10,60],[20,30],[30,30],[60,40]]
 * Output: 2
 * Explanation:
 * We start with 10 liters of fuel.
 * We drive to position 10, expending 10 liters of fuel.  We refuel from 0
 * liters to  liters of gas.
 * Then, we drive from position 10 to position  (expending 50 liters of
 * fuel),
 * and refuel from 10 liters to 50 liters of gas.  We then drive to and reach
 * the target.
 * We made 2 refueling stops along the way, so we return 2.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= target, startFuel, stations[i][1] <= 10^9
 * 0 <= stations.length <= 500
 * 0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] <
 * target
 *
 */
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int nowpos = startFuel;
        int counter = 0, p = 0;
        priority_queue<int> pq;
        while (1) {
            if (nowpos >= target)
                return counter;
            while (p < (int)stations.size() && stations[p][0] <= nowpos) {
                pq.push(stations[p][1]);
                p++;
            }
            if (pq.empty())
                return -1;
            nowpos += pq.top();
            pq.pop();
            counter++;
        }
    }
};

int mymain(int argc, char* argv[]) {
    vector<vector<int>> stations = { { 13, 21 }, { 26, 115 }, { 100, 47 }, { 225, 99 },
        { 299, 141 }, { 444, 198 }, { 608, 190 }, { 636, 157 }, { 647, 255 }, { 841, 123 } };
    Solution s;
    cout << s.minRefuelStops(1000, 299, stations);
    return 0;
}
