
#include <cstdio>
#include <string>
#include <iostream>

int ma_test() {
    int K, temp_K;
    int max = 0, temp_max = 0;
    std::string str;

    scanf("%d", K);

    std::getline(std::cin, str);

    int left, right;
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        left = 0, right = 0, temp_K = K;;

        while (temp_K > 0) {
            if (str.at(right) != letter) temp_K--;
            ++right;
        }

        temp_max = right - left + 1;
        max = temp_max > max ? temp_max : max;

        while (right != str.size() - 1) {
            //TODO: move compact [left, right] in str
        }
    }
}

int main() {
    printf("%d", ma_test());
}