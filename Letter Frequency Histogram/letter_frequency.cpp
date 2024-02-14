#include "letter_frequency.h"

int main(int argc, char *argv[]) {
    int is_ok = EXIT_FAILURE;

    if (argc < 2) {
        std::cout << "Please select at least one text file!." << std::endl;
        return is_ok;
    }

    for (int i = 1; i < argc; i++) {
        std::cout << "File: " << argv[i] << std::endl;
        std::ifstream fp(argv[i]);

        if (!fp) {
            std::perror("File opening failed");
            fp.close();
            continue;
        }
        std::map<std::string, int> letters;
        std::multimap<int, std::string> multi_letters;

        char character;
        std::string char_found;
        std::string output;

        std::regex alphabet("[a-z]");


        if (fp.is_open()) {
            while (fp.good()) {
                fp.get(character);
                char_found = char(std::tolower(character));
                if (std::regex_match(char_found, alphabet)) {
                    if (auto search = letters.find(char_found); search != letters.end()) {
                        letters[char_found]++;
                    } else {
                        letters.insert({char_found, 1});
                    }
                }
            }
        }


        for (auto &it: letters) {
            multi_letters.insert({it.second, it.first});
        }

        for (const auto &letter: multi_letters) {
            output = letter.second + " " + std::to_string(letter.first) + "\n" + output;
        }

        std::cout << output << std::endl;

        fp.close();
    }

    return 0;
}
