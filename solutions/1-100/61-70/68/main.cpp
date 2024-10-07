#include <iostream>
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include "solutions/1-100/11-20/18/18.h"

int main() {
    std::vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int64_t largest = 0;
    int smallestSum = INT_MAX;

    while(std::ranges::next_permutation(nums).found) {

        int sum = nums[0] + nums[1] + nums[2];
        if(nums[2] + nums[3] + nums[4] == sum) {
            if(nums[4] + nums[5] + nums[6] == sum) {
                if(nums[6] + nums[7] + nums[8] == sum) {
                    if(nums[8] + nums[9] + nums[1] == sum) {
                        if(sum < smallestSum) {
                            smallestSum = sum;
                            largest = 0;
                        }
                        if(sum == smallestSum) {
                            std::string concat;
                            concat += std::to_string(nums[0]) + std::to_string(nums[1]) + std::to_string(nums[2]);
                            concat += std::to_string(nums[3]) + std::to_string(nums[2]) + std::to_string(nums[4]);
                            concat += std::to_string(nums[5]) + std::to_string(nums[4]) + std::to_string(nums[6]);
                            concat += std::to_string(nums[7]) + std::to_string(nums[6]) + std::to_string(nums[8]);
                            concat += std::to_string(nums[9]) + std::to_string(nums[8]) + std::to_string(nums[1]);
                            if(concat.size() == 16) {
                                largest = std::max(largest, std::stoll(concat));
                            }
                        }
                    }
                }
            }

        }
    }

    std::cout << "Largest 16-digit string: " << largest << std::endl;

    return 0;
}
