#include <iostream>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <vector>


#include "ipAdress.h"
#include "function_for_sort.cpp"


std::filesystem::path path( std::filesystem::current_path().append("ip_filter.tsv"));
std::filesystem::path dir_path_write( std::filesystem::current_path().append("ip_filter.tsv"));

int write_from_file(std::vector<ipAdress> allAdress);
//std::vector<ipAdress>  filter_values_by_bytse(const std::vector<ipAdress>& Alladress, int numberBytesUouneed, int first = 0, int second = 0, int third = 0, int fouth =0);
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
        std::cout << "Finish reading file" << std::endl;
        std::sort(allAdress.begin(),allAdress.end());
        write_from_file(allAdress);
        std::cout << "Finish writing on file" << std::endl;
        print(filter_values_by_bytse(allAdress,1,1));
        print(filter_values_by_bytse(allAdress,2,46,70));
        print(filter_values_by_bytse(allAdress,3,46,46,46,46));
        std::cout << "finisg" << std::endl;
    }
    else {
        std::cout << "File doesnt search" << std::endl;
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
        std::cout << "File for writing data doesnt search" << std::endl;
    }
    
    return 0;
}
void print(std::vector<ipAdress> allAdress) {
    for (ipAdress ad : allAdress) {
        ad.printAsdress();
    }
}