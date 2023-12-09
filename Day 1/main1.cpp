#include <iostream>
#include <regex>

int main() {
    //read each line of input text file
    
    int sum = 0;
    while (std::cin) {
        std::string line;
        std::getline(std::cin, line);
        
        int val = 0;
        // find first value
        for (int i = 0; i < line.length(); i++) {
            // check if its a number and not a character
            if (line[i] >= '0' && line[i] <= '9') {
                val = line[i] - '0';
                val *= 10;
                break;
            }
        }
        // find last value
        for (int i = line.length(); i >= 0; i--) {
            // check if its a number and not a character
            if (line[i] >= '0' && line[i] <= '9') {
                val += line[i] - '0';
                break;
            }
        }
        printf("line: %s, val: %d\n", line.c_str(), val);
        sum += val;
    }
    
    std::cout << sum << std::endl;
    return 0;
}
