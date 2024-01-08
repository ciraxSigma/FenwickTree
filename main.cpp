#include <iostream>
#include <array>


std::array<int, 9> create(std::array<int, 9> arr){

    std::array<int, 9> BITarr;

    int subSum = 0;

    for(int i = 1; i  < arr.size() + 1; ++i){

        for(int j = i - (i & -i) + 1; j <= i; ++j){

            subSum += arr[j - 1];

        }

        BITarr[i - 1] = subSum;
        subSum = 0;
    }

    return BITarr;

}

int calculateSum(int index, std::array<int, 9> arr){

    int sum = 0;

    while(index > 0){

        sum += arr[index - 1];
        index -= index & -index;
    }

    return sum;

}

void update(int index, int value ,std::array<int, 9>& arr){

    while(index <= arr.size()){

        arr[index - 1] += value;

        index += index & -index;
    }

}

int main()
{

    std::array<int, 9>arr = {2, 1, 7, 4, 3, 2, 7, 9, 5};
    std::array<int, 9> BITarr = create(arr);


    std::cout << calculateSum(7, BITarr) - calculateSum(4, BITarr);


    return 0;
}
