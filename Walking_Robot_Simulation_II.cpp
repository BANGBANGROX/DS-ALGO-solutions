#include<bits/stdc++.h>
using namespace std;

class Robot {
public:
    int width, height, currX, currY, count;
    pair<int, int> dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

    bool isValid(int x, int y) {
        return x > -1 && y > -1 && x < width && y < height;
    }

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        currX = 0;
        currY = 0;
        count = 0;
    }

    void move(int num) {
        int perimeter = 2 * (width + height - 2);

        if (num >= perimeter) {
            num %= perimeter;
            if (currX == 0 && currY == 0 && count == 0) count = 3;
        }
        
        while (num) {
            int newX = currX + dir[count].first, newY = currY + dir[count].second;
            if (isValid(newX, newY)) {
                currX = newX;
                currY = newY;
                --num;
            }
            else {
                count = (count + 1) % 4;
            }
        }
    }

    vector<int> getPos() {
        return { currX,currY };
    }

    string getDir() {
        if (count == 0) return "East";
        if (count == 1) return "North";
        if (count == 2) return "West";
        return "South";
    }
};

int main() {
    Robot robot(6, 3); // Initialize the grid and the robot at (0, 0) facing East.
    robot.move(2);  // It moves two steps East to (2, 0), and faces East.
    robot.move(2);  // It moves two steps East to (4, 0), and faces East.
    cout << robot.getPos()[0] << " " << robot.getPos()[1] << endl; // return [4, 0]
    cout << robot.getDir() << endl; // return "East"
    robot.move(2);  // It moves one step East to (5, 0), and faces East.
                    // Moving the next step East would be out of bounds, so it turns and faces North.
                    // Then, it moves one step North to (5, 1), and faces North.
    robot.move(1);  // It moves one step North to (5, 2), and faces North (not West).
    robot.move(4);  // Moving the next step North would be out of bounds, so it turns and faces West.
                    // Then, it moves four steps West to (1, 2), and faces West.
    cout << robot.getPos()[0] << " " << robot.getPos()[1] << endl; // return [1, 2]
    cout << robot.getDir() << endl; // return "West"

    return 0;
}