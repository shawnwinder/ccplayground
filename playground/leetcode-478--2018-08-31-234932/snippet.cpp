// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <random>

using namespace std;

/*
 * [915] Generate Random Point in a Circle
 *
 * https://leetcode.com/problems/generate-random-point-in-a-circle/description/
 *
 * algorithms
 * Medium (32.30%)
 * Total Accepted:    1.3K
 * Total Submissions: 4K
 * Testcase Example:  '["Solution", "randPoint", "randPoint", "randPoint"]\n[[1.0, 0.0, 0.0], [],
 * [], []]'
 *
 * Given the radius and x-y positions of the center of a circle, write a
 * function randPoint which generates a uniform random point in the circle.
 *
 * Note:
 *
 *
 * input and output values are in floating-point.
 * radius and x-y position of the center of the circle is passed into the class
 * constructor.
 * a point on the circumference of the circle is considered to be in the
 * circle.
 * randPoint returns a size 2 array containing x-position and y-position of the
 * random point, in that order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","randPoint","randPoint","randPoint"]
 * [[1,0,0],[],[],[]]
 * Output:
 * [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","randPoint","randPoint","randPoint"]
 * [[10,5,-7.5],[],[],[]]
 * Output:
 * [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has three arguments, the radius, x-position of the
 * center, and y-position of the center of the circle. randPoint has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 *
 *
 */
class Solution {
    std::random_device rd;
    std::mt19937 gen1;
    std::mt19937 gen2;
    std::uniform_real_distribution<> r;
    std::uniform_real_distribution<> t;
    double radius_;
    double x_center_;
    double y_center_;

public:
    Solution(double radius, double x_center, double y_center)
        : radius_(radius)
        , x_center_(x_center)
        , y_center_(y_center)
        , gen1(rd())
        , gen2(rd())
        , r(radius)
        , t(M_PI) {}

    vector<double> randPoint() {
        double rs = r(gen1);
        double ts = t(gen2);
        return { x_center_ + radius_ * cos(ts), y_center_ + radius_ * sin(ts) };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */

int mymain(int argc, char* argv[]) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> r;
    for (auto i = 1u; i < 10; ++i) {
        std::cout << sin(M_PI / i) << std::endl;
    }

    return 0;
}


int mymain(int argc, char* argv[]) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> r;
    for (auto i = 1u; i < 10; ++i) {
        std::cout << sin(M_PI / i) << std::endl;
    }

    return 0;
}
