class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Define the possible directions the robot can face
        // directions[0]: North, directions[1]: East, directions[2]: South, directions[3]: West
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Use an unordered_set to store obstacles as strings in the format "x,y"
        unordered_set<string> obs;
        for (auto& obstacle : obstacles) {
            obs.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }
        
        // Initialize the robot's starting position (x, y) and its initial direction (North)
        int x = 0, y = 0, dir = 0, maxDistSquare = 0;

        // Process each command in the commands vector
        for (auto c : commands) {
            if (c == -1) { 
                // Turn right (clockwise): update direction by incrementing and using modulo 4
                dir = (dir + 1) % 4;
            } else if (c == -2) { 
                // Turn left (counterclockwise): update direction by decrementing and using modulo 4
                dir = (dir + 3) % 4;
            } else { 
                // Move forward 'c' steps in the current direction
                while (c--) {
                    int nx = x + directions[dir][0]; // Calculate the next x position
                    int ny = y + directions[dir][1]; // Calculate the next y position
                    
                    // Check if the next position is an obstacle
                    if (obs.find(to_string(nx) + "," + to_string(ny)) != obs.end())
                        break; // Stop moving if there's an obstacle
                    
                    // Update the robot's position
                    x = nx;
                    y = ny;
                    
                    // Update the maximum distance squared from the origin
                    maxDistSquare = max(maxDistSquare, x * x + y * y);
                }
            }
        }
        
        // Return the maximum distance squared from the origin after processing all commands
        return maxDistSquare;
    }
};
