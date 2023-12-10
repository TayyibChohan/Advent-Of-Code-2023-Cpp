#include <iostream>
const int MAX_RED_IN_ROUND = 12;
const int MAX_BLUE_IN_ROUND = 14;
const int MAX_GREEN_IN_ROUND = 13;


int main() {
    //set number of red, blue, and green to max int
    int numRed, numBlue, numGreen;
    int gameSum = 0;

     while (std::cin) {
        std::string line;
        std::getline(std::cin, line);
        if (line == "") {
            break;
        }
        bool validGame = true;

        //find first space and ; to determine gameID
        size_t space = line.find(" ");
        size_t semicolon = line.find(":");
        std::string gameIDString = line.substr(space+1, semicolon-space-1);
        int gameID = std::stoi(gameIDString);
        printf("Game ID: %d\n", gameID);
        //Parse input in the form Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
        std::string games = line.substr(semicolon+2);

        //Create array of rounds in game using ; delimiter
        std::string delimiter = ";";
        std::string rounds[100];
        int roundCount = 0;
        
        size_t pos = 0;
        std::string token;
        while ((pos = games.find(delimiter)) != std::string::npos) {
            token = games.substr(0, pos);
            rounds[roundCount] = token;
            roundCount+=1;
            games.erase(0, pos + delimiter.length());
        }
        token = games.substr(0, pos);
        rounds[roundCount] = token;
        roundCount+=1;     
        
        numRed = 1;
        numBlue = 1;
        numGreen = 1;

        //Parse each round using , delimiter
        for (int i = 0; i < roundCount; i++) {
            // std::cout << rounds[i] << std::endl;        

            std::string round = rounds[i];

            //Create array of rounds in game using ; delimiter
            std::string delimiter = ",";
            std::string rolls[100];
            int rollCount = 0;
            
            size_t pos = 0;
            std::string token;
            while ((pos = round.find(delimiter)) != std::string::npos) {
                token = round.substr(0, pos);
                rolls[rollCount] = token;

                rollCount++;
                round.erase(0, pos + delimiter.length());
            }
            token = round.substr(0, pos);
            rolls[rollCount] = token;
            rollCount++;

            for (int j = 0; j < rollCount; j++) {
                //trim whitespace
                std::string roll = rolls[j];
                roll.erase(0, roll.find_first_not_of(' '));
                //find space to determine color and number
                size_t space = roll.find(" ");
                std::string number = roll.substr(0, space);
                std::string color = roll.substr(space+1);

                int num = std::stoi(number);
                if (color == "red") {
                    numRed = std::max(numRed, num);
                } else if (color == "blue") {
                    numBlue = std::max(numBlue, num);
                } else if (color == "green") {
                    numGreen = std::max(numGreen, num);
                } else {
                    std::cout << "Invalid color: " << color << std::endl;
                    validGame = false;
                    break;
                }
            }
        }
        std::cout << "sum: " << numRed * numBlue * numGreen << std::endl;
        gameSum += numRed * numBlue * numGreen;
        
    }
    std::cout << "GameSum: " << gameSum << std::endl;
    return 0;
}
