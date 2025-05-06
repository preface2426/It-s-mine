#include <iostream>
#include <string>
#include <map>
#include <limits>

int main() {
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text); // 获取一行输入

    // 将字符串转换为小写
    for (char &c : text) {
        c = tolower(c);
    }

    // 使用map来存储每个字母及其出现次数
    std::map<char, int> letterCounts;

    // 统计每个字母的出现次数
    for (char c : text) {
        if (isalpha(c)) { // 检查是否为字母
            ++letterCounts[c];
        }
    }

    // 找出出现次数最多的字母
    char mostFrequentLetter = ' ';
    int maxCount = std::numeric_limits<int>::min();

    for (const auto &pair : letterCounts) {
        if (pair.second > maxCount) {
            mostFrequentLetter = pair.first;
            maxCount = pair.second;
        }
    }

    // 输出结果
    if (mostFrequentLetter != ' ') {
        std::cout << "The most frequent letter is '" << mostFrequentLetter << "' with " << maxCount << " occurrences." << std::endl;
    } else {
        std::cout << "No letters found in the input." << std::endl;
    }

    return 0;
}