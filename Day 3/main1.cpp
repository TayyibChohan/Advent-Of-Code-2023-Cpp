#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() {
    
    //Create list of strings to store input
    std::vector<std::string> input;
    //create a list of (x,y) coordinates of symbols
    std::vector<std::pair<int, int>> coordinates;

    int x = 0;
    while (std::cin) {
        std::string line;
        std::getline(std::cin, line);
        if (line == "") {
            break;
        }

        for (int i = 0; i < line.length(); i++) {
            if (line[i] != '.' && (line[i] > '9' || line[i] < '0')) {
                coordinates.push_back(std::make_pair(x, i));
            }
        }
        input.push_back(line);
        std::cout << line << std::endl;
        x++;
    }
    std::cout << "Input size: " << input.size() << " x " << input[0].length() << std::endl;
    std::cout << "Number of symbols: " << coordinates.size() << std::endl;

    //total numbers
    int total = 0;
    //create a set of visited coordinates
    std::set<std::pair<int, int>> visited;
    
    //breadth first search each symbol 1 layer deep to look for numbers
    for (int i = 0; i < coordinates.size(); i++) {
        int x = coordinates[i].first;
        int y = coordinates[i].second;
        int num = 0;
        // Directional vectors
        std::vector<int> xDir = {0, 0, 1, -1, 1, -1, 1, -1};
        std::vector<int> yDir = {1, -1, 0, 0, 1, -1, -1, 1};
        for (int j = 0; j < xDir.size(); j++) {
            int newX = x + xDir[j];
            int newY = y + yDir[j];
            if (newX >= 0 && newX < input.size() && newY >= 0 && newY < input[0].length()) {
                // std::cout << "Checking: " << newX << ", " << newY << " |Symbol: " << input[x][y] << std::endl;
                if (input[newX][newY] >= '0' && input[newX][newY] <= '9') {
                    // find entire number by checking left and right of line
                    int left = newY;
                    int right = newY;
                    while (left >= 0 && input[newX][left] >= '0' && input[newX][left] <= '9') {
                        left--;
                    }
                    while (right < input[0].length() && input[newX][right] >= '0' && input[newX][right] <= '9') {
                        right++;
                    }
                    // check if number has been visited
                    if (visited.find(std::make_pair(newX, left)) == visited.end()) {
                        // add number to total
                        total += std::stoi(input[newX].substr(left + 1, right - left - 1));
                        // std::cout << "Found number: " << std::stoi(input[newX].substr(left + 1, right - left - 1)) << std::endl;
                        // add number to visited
                        visited.insert(std::make_pair(newX, left));
                    }
                    else{
                        // std::cout << "Already visited: " << std::stoi(input[newX].substr(left + 1, right - left - 1)) << std::endl;
                    }
                }
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
