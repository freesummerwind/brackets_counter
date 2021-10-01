#include <iostream>
#include <unordered_map>

enum BracketType{
    Opened,
    Closed
};

bool checkSequence(const std::string& sequence) {
    std::unordered_map<char, std::pair<BracketType, int>> brackets = {};
    brackets['('] = {BracketType::Opened, 1};
    brackets[')'] = {BracketType::Closed, 1};
    brackets['['] = {BracketType::Opened, 2};
    brackets[']'] = {BracketType::Closed, 2};
    brackets['{'] = {BracketType::Opened, 3};
    brackets['}'] = {BracketType::Closed, 3};

    int counter = 0;
    bool result = true;
    for(char i : sequence) {
        std::pair<BracketType, int> current = brackets[i];
        if(current.first == BracketType::Opened) {
            counter <<= 2;
            counter += current.second;
        } else {
            if(!counter) {
                result = false;
                break;
            }
            if((counter & 3) == current.second) {
                counter >>= 2;
            } else {
                result = false;
                break;
            }
        }
    }

    if(counter) result = false;
    return result;
}

int main() {
    std::string sequence;
    std::cout << "input bracket sequence: ";
    std::cin >> sequence;
    std::cout << sequence << " : sequence is " << (checkSequence(sequence) ? "correct" : "incorrect") << std::endl;

    return 0;
}
