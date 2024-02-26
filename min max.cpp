#include <iostream>
#include <string>


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);



    std::string text;

    getline(std::cin, text, '^');

    int counter[26]{0};
    int i = 0;

    while (i < text.length()) {
        text[i] = tolower(text[i]);
        if (text[i] >= 'a' && text[i] <= 'z') {
            ++counter[text[i] - 'a'];
        }
        ++i;
    }

    int max = 0;
    int min = counter[0];
    char most_letter = 97;
    char least_letter = 97;

    for (int k = 0; k < 26; k++) {
        if (counter[k] > max) {
            max = counter[k];
            most_letter = k + 'a';
        }
        if (counter[k] > 0 && (counter[k] < min) || min == 0) {
            min = counter[k];
            least_letter = k + 'a';
        }
    }

    std::cout << most_letter << " " << least_letter << std::endl;
    

    return 0;
}
