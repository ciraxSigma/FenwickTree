#include <iostream>
#include <vector>
#include <chrono>



std::vector<long long int> create(std::vector<long long int> arr){

    std::vector<long long int> BITarr;

    long long int subSum = 0;

    for(int i = 1; i  < arr.size() + 1; ++i){

        for(int j = i - (i & -i) + 1; j <= i; ++j){

            subSum += arr[j - 1];

        }

        BITarr.push_back(subSum);
        subSum = 0;
    }

    return BITarr;

}

long long int calculateSum(int index, std::vector<long long int>& arr){

    long long int sum = 0;

    while(index > 0){

        sum += arr[index - 1];
        index -= index & -index;
    }

    return sum;

}

long long int calculateSumBetween(int startIndex, int endIndex, std::vector<long long int>& BITarr){
    return calculateSum(endIndex, BITarr) - calculateSum(startIndex - 1, BITarr);
}

void update(int index, int value ,std::vector<long long int>& arr){

    while(index <= arr.size()){

        arr[index - 1] += value;

        index += index & -index;
    }

}

int main()
{

    std::vector<long long int> vektor;

    for(int i = 1; i <= 1000000; ++i){
        vektor.push_back(i);
    }

    std::vector<long long int> BIT = create(vektor);

    long long int sum = 0;

    auto start1 = std::chrono::steady_clock::now();


    for(int i = 0; i < 856797; ++i){
        sum += vektor[i];
    }

    auto end1 = std::chrono::steady_clock::now();

    auto diff1 = end1 - start1;


    std::cout << sum << std::endl;
    std::cout << "Time: " << std::chrono::duration <double, std::milli> (diff1).count() << std::endl;
    std::cout << "========" << std::endl;

    auto start2 = std::chrono::steady_clock::now();

    sum = calculateSum(856797, BIT);

    auto end2 = std::chrono::steady_clock::now();

    auto diff2 = end2 - start2;

    std::cout << sum << std::endl;
    std::cout << "Time: " << std::chrono::duration <double, std::milli> (diff2).count() << std::endl;
    std::cout << "========" << std::endl;

    return 0;
}
