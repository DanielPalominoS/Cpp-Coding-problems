#include <iostream>
#include <cmath>
#include <list>
class Solution {
public:
    bool isPalindrome(int x) {
        // A boolean variable to store the answer.
        bool answer = false;

        // Check if the number is greater than 0.
        if (x > 0) {
            // Calculate the number of digits in the number.
            int num_digits = int(log10(x) + 1);
            // A list to store the digits of the number.
            std::list<short> digits;

            // Loop through each digit of the number.
            for (int i = num_digits; i > 0; i--) {
                // Calculate the current digit and its value.
                int digit = x / pow(10, i-1);

                // Add the digit to the list.
                digits.push_back(digit);

                // Subtract the value of the digit multiplied by 10 raised to the power of the digit's position.
                x -= digit * pow(10, i-1);
            }

            // Assume the number is a palindrome.
            answer = true;

            // Compare the first half of the digits with the second half.
            for (int i = 0; i < int(num_digits / 2); i++) {
                // If the first and last digits do not match, the number is not a palindrome.
                if (digits.back() == digits.front()) {
                    // Remove the first and last digits.
                    digits.pop_back();
                    digits.pop_front();
                    
                } else {
                    // If the digits do not match, set the answer to false and break out of the loop.
                    answer = false;
                    break;
                }
            }
        }
        else if(x==0){
            return true;
        }

        // Return the answer.
        return answer;
    }
};

int main(int, char**) {
    std::cout << "Hello, from palyndrome_number!\n";
    Solution mySol;
    std::cout << mySol.isPalindrome(121) << "\n"; // true
    std::cout << mySol.isPalindrome(3443) << "\n"; // true
    std::cout << mySol.isPalindrome(-145) << "\n"; // false
    std::cout << mySol.isPalindrome(0) << "\n"; // true
}