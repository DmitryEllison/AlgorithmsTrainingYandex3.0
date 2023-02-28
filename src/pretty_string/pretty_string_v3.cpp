
#include <cstdio>
#include <string>
#include <iostream>

int ma_test() {
    int K, temp_K;
    int max = 0, temp_max = 0;
    std::string str;

    scanf("%d\n", &K);

    /// read file
    std::getline(std::cin, str);

    int left, right;
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        left = 0, right = 0, temp_K = K;;

        while (right != str.size()) {
            if (str.at(right) != letter) temp_K--;

            if (temp_K == 0 || right == str.size() - 1 ) { // К равен нулю --> обновить ИЛИ right достиг конца строки
                temp_max = right - left + 1;
                max = temp_max > max ? temp_max : max;
                temp_K = K;
                ++left;
                if (right == str.size() - 1)
                    break;
            }

            ++right;
        }

        //TODO: move compact [left, right] in str
    }
}

int main() {
    printf("%d", ma_test());
}