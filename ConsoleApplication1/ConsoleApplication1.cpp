#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#include "function_for_sort.cpp"
#include "ipAdress.h"
//! Сценарий получения данных, если true из файла иначе из командной строки
constexpr bool scenary_read_data = false;

std::filesystem::path
    path(std::filesystem::current_path().append("ip_filter.tsv"));
std::filesystem::path
    dir_path_write(std::filesystem::current_path().append("ip_filter.tsv"));

int write_from_file(std::vector<ipAdress> allAdress);
void print(const std::vector<ipAdress> &allAdress);

int main() {
  setlocale(LC_ALL, "Russian");
  std::vector<ipAdress> allAdress;
   if (scenary_read_data) {
    std::fstream readable_file(path);
    if (readable_file.is_open()) {
      std::string line_buffer;
      while (std::getline(readable_file, line_buffer)) {
        line_buffer = line_buffer.substr(0, line_buffer.find("\t"));
        allAdress.push_back(std::move(line_buffer));
      }
    } else {
      std::cout << "File doesnt search" << std::endl;
      return 0;  
    }
    readable_file.close();
    
  } else {
    
    bool spend_insert = true;
        std::cout<<"If you want start sort write go"<<std::endl;
        while(spend_insert){
            std::string val;
            std::cin>>val;
            if(val == "go"){
                spend_insert = false;
                break;
            } else {
                allAdress.push_back(std::move(val));
            }
        }
  }
    
    std::cout << "Full sort" << std::endl;
    std::sort(allAdress.begin(), allAdress.end());
    // write_from_file(allAdress);
    print(allAdress);
    std::cout << "Finish full sort" << std::endl;
    print((filter_values_by_bytse(allAdress, 1, 1)));
    print(filter_values_by_bytse(allAdress, 2, 46, 70));
    print(filter_values_by_bytse(allAdress, 3, 46, 46, 46, 46));
    std::cout << "finisg" << std::endl;
  system("pause");
}

int write_from_file(std::vector<ipAdress> allAdress) {
  std::ofstream out(dir_path_write);
  if (out.is_open()) {
    for (ipAdress adr : allAdress) {
      out.write(adr.get_string_adress().c_str(),
                adr.get_string_adress().size());
      out << std::endl;
    }
    out.close();
  } else {
    std::cout << "File for writing data doesnt search" << std::endl;
  }

  return 0;
}
void print(const std::vector<ipAdress> &allAdress) {
  for (ipAdress ad : allAdress) {
    ad.printAsdress();
  }
}
