//
// Created by ghisl on 11/08/2024.
//

#include <iostream>
#include <string>

bool isPalindrome(int number) {
    std::string strnum = std::to_string(number);
    std::string revstr = "";
    for(char c : strnum) {
        revstr = c + revstr;
    }
    return strnum == revstr;
}
