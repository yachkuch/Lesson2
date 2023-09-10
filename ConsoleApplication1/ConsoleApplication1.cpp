#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#include "ipAdress.h"

#ifdef __unix__                    

#define OS_Windows 0
constexpr auto path_ = "//";
constexpr auto file = "//ip_filter.tsv";


#elif defined(_WIN32) || defined(WIN32)    

#define OS_Windows 1

constexpr auto path_ = "\\";
constexpr auto file = "\\ip_filter.tsv";

#endif

struct comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const {
        return l > r;
    }
};

int write_from_file(std::vector<ipAdress> allAdress);
std::vector<ipAdress>  print_values_by_bytse(std::vector<ipAdress> Alladress, int numberBytesUouneed, int first = 0, int second = 0, int third = 0, int fouth =0);

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string file_path(__FILE__);
#ifdef OS_Windows
    std::string dir_path = file_path.substr(0, file_path.rfind("\\"));
#else 
    std::string dir_path = file_path.substr(0, file_path.rfind("//"));
#endif 
    std::vector<ipAdress> allAdress;
    dir_path.append(file);
    std::fstream readable_file(dir_path);
    if (readable_file.is_open()) {
        std::string line_buffer;
        while (std::getline(readable_file,line_buffer))
        {
            line_buffer = line_buffer.substr(0, line_buffer.find("\t"));
            allAdress.push_back(std::move(line_buffer));
        }
        std::cout << "Завершено считывние файла" << std::endl;
        //std::sort(allAdress.begin(), allAdress.end(), comp());
        write_from_file(allAdress);
        std::cout << "Завершена запись файла" << std::endl;

    }
    else {
        std::cout << "Файл не был найден" << std::endl;
    }
}

int write_from_file(std::vector<ipAdress> allAdress) {
    return 0;
}

std::vector<ipAdress>  print_values_by_bytse(std::vector<ipAdress> Alladress, int numberBytesUouneed, int first, int second, int third, int fouth)
{
    std::vector<ipAdress> print;
    if (numberBytesUouneed == 1) {
        for (ipAdress ad : Alladress) {
            if (ad.get_first() == first) {
                print.push_back(ad);
            }
        }
    }
    else if (numberBytesUouneed == 2) {
        if (first < 0) {
            for (ipAdress ad : Alladress) {
                if (ad.get_second() == second) {
                    print.push_back(ad);
                }
            }
        }
        else {
            for (ipAdress ad : Alladress) {
                if (ad.get_second() == second && ad.get_first() == first) {
                    print.push_back(ad);
                }
            }

        }

    }
    else if (numberBytesUouneed == 3) {
        for (ipAdress ad : Alladress) {
            if (ad.get_second() == second || ad.get_first() == first || ad.get_third() == third || ad.get_fouth() == fouth) {
                print.push_back(ad);
            }
        }

    }
    return print;
}