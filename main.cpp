#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

void readFile();

int main() {
    std::ofstream reading;
    reading.open("Readings.txt");

    double min = 50;
    double max = 90;

    std::default_random_engine generator(time(0));
    std::uniform_real_distribution<double>
            distribution(min, max);

    srand(time(NULL));
    int value = (rand() % 513 + 512);

    for (int i = 0; i <=  value; i++) {
        double my_random = distribution(generator);
        std::cout << i << std::setw(10) << std::fixed << std::setprecision(3) << my_random << std::endl;
        reading << i << std::setw(10) << std::fixed << std::setprecision(3) << my_random << std::endl;
    }

    readFile();
    return 0;
}

void readFile(){
    const int MIN_VALUE = 50;   // Minimum value
    const int MAX_VALUE = 90;
    std::string str;
    std::ifstream book;
    book.open("Readings.txt");

    int count = 0;
    double average;
    double largest = MIN_VALUE;
    double lowest = MAX_VALUE;
    double total;
    double number;
    double median;
    std::vector<double> read;

    while (book >> number) {
        book >> number;
        count++;
        if (number > largest) {
            largest = number;
        } else if (number < lowest) {
            lowest = number;
        }
        total += number;

        read.push_back(number);
        std::sort(read.begin(),read.end());
        unsigned int size = read.size();
        if(size % 2 != 0) {
            median = read[floor(size / 2.0)];
        } else {
            median = (read[size / 2] + read[size / 2 - 1]) / 2;
        }
    }

    average = total / count;

    std::cout << "there are " << count  << " readings in the file" << std::endl;
    std::cout << "the average reading is " << std::fixed << std::setprecision(3) << average << std::endl;
    std::cout << "the highest reading is "  << std::fixed << std::setprecision(3) << largest << std::endl;
    std::cout << "the lowest reading is " << std::fixed << std::setprecision(3) << lowest << std::endl;
    std::cout << "the median reading is " << std::fixed << std::setprecision(3) << median << std::endl;

}