#include <iostream>
#include <regex>

int main() {
    //read each line of input text file
    
    int sum = 0;
    while (std::cin) {
        std::string line;
        std::getline(std::cin, line);
        
        int firstVal = 0;
        int first_index_val = 0;
        // find first value
        for (int i = 0; i < line.length(); i++) {
            // check if its a number and not a character
            if (line[i] >= '0' && line[i] <= '9') {
                first_index_val = i;
                firstVal = line[i] - '0';
                break;
            }
        }

        // find last value
        int secondVal = 0;
        int last_index_val = 0;
        for (int i = line.length() - 1; i >= 0; i--) {
            // check if its a number and not a character
            if (line[i] >= '0' && line[i] <= '9') {
                last_index_val = i;
                secondVal = line[i] - '0';
                break;
            }
        }

        // create an array of all the numbers and their string values
        std::string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        // find the index of the number in the array
        int index = first_index_val;
        bool found = false;
        for (int i = 0; i < 10; i++) {
            int search = line.find(numbers[i]);
            if (search != std::string::npos) {
                if (search <= index) {
                    index = search;
                    found = true;
                    firstVal = i;
                }
            }
        }

        index = last_index_val;
        found = false;
        for (int i = 0; i < 10; i++) {
            int search = line.rfind(numbers[i]);
            if (search != std::string::npos) {
                if (search >= index) {
                    index = search;
                    found = true;
                    secondVal = i;
                }
            }
        }

        
       
        int val = firstVal*10 + secondVal;
        printf("line: %s, val: %d\n", line.c_str(), val);
        sum += val;
    }
    
    std::cout << sum << std::endl;
    return 0;
}
