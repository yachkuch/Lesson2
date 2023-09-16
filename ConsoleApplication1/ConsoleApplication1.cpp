#include <iostream>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <vector>


#include "ipAdress.h"


std::filesystem::path path( std::filesystem::current_path().append("ip_filter.tsv"));
std::filesystem::path dir_path_write( std::filesystem::current_path().append("ip_filter.tsv"));

int write_from_file(std::vector<ipAdress> allAdress);
std::vector<ipAdress>  filter_values_by_bytse(const std::vector<ipAdress>& Alladress, int numberBytesUouneed, int first = 0, int second = 0, int third = 0, int fouth =0);
void print(std::vector<ipAdress> allAdress);

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<ipAdress> allAdress;
    std::fstream readable_file(path);
    if (readable_file.is_open()) {
        std::string line_buffer;
        while (std::getline(readable_file,line_buffer))
        {
            line_buffer = line_buffer.substr(0, line_buffer.find("\t"));
            allAdress.push_back(std::move(line_buffer));
        }
        readable_file.close();
        std::cout << "Завершено считывние файла" << std::endl;
        std::sort(allAdress.begin(),allAdress.end());
        write_from_file(allAdress);
        std::cout << "Завершена запись файла" << std::endl;
        print(filter_values_by_bytse(allAdress,1,1));
        print(filter_values_by_bytse(allAdress,2,46,70));
        print(filter_values_by_bytse(allAdress,3,46,46,46,46));
        std::cout << "finisg" << std::endl;
    }
    else {
        std::cout << "Файл не был найден" << std::endl;
    }
    system("pause");
}

int write_from_file(std::vector<ipAdress> allAdress) {
    std::ofstream out(dir_path_write);
    if (out.is_open()) {
        for (ipAdress adr : allAdress) {
            out.write(adr.get_string_adress().c_str(), adr.get_string_adress().size());
            out << std::endl;
        }
        out.close();
    }
    else {
        std::cout << "Файл для записи результата не был открыт" << std::endl;
    }
    
    return 0;
}

std::vector<ipAdress>  filter_values_by_bytse(const std::vector<ipAdress>& Alladress, int numberBytesUouneed, int first, int second, int third, int fouth)
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

void print(std::vector<ipAdress> allAdress) {
    for (ipAdress ad : allAdress) {
        ad.printAsdress();
    }
}