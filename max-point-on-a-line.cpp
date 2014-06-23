#include "leetcode.h"

struct Point {
    int x;
    int y;
    Point():x(0),y(0){}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        map<double, int> slopeNums;
        double maxSlope = numeric_limits<double>::infinity();

        int maxCount = 0;

        if(points.empty()) {
            return 0;
        } else if(points.size() == 1) {
            return 1;
        }

        for (int i = 0; i < (int)points.size() - 1; i++) {
            slopeNums.clear();
            
            Point x1 = points[i];

            int samePoints = 0;
            
            int cnt = 1;

            for(int j = i + 1; j < (int)points.size(); j++) {
                Point x2 = points[j];

                double slope = maxSlope;

                if(x1.x != x2.x) {
                    slope = (double)(x2.y - x1.y) / (double)(x2.x - x1.x);                    
                } else if(x1.y == x2.y) {
                    samePoints++;
                    continue;
                }
                
                int num = slopeNums[slope];
                if(num == 0) {
                    slopeNums[slope] = 2;
                    num = 2;
                } else {
                    num++;
                    slopeNums[slope] = num;
                }
                if(num > cnt) {
                    cnt = num;
                }
            }
            
            if((cnt + samePoints)> maxCount) {
                maxCount = cnt + samePoints;
            }
        }

        return maxCount;
    }
};

int main() {
    Solution sln;
    vector<Point> points;
    points.push_back(Point(0, 0));
    points.push_back(Point(1, 1));
    points.push_back(Point(0, 0));
    int n = sln.maxPoints(points);
    cout << n << endl;
    return 0;
}