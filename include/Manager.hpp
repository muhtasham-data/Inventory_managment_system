#pragma once
#include "/home/muhammadmuhtasham/Inventory_managment_system/include/product.hpp"
using std::string;
class Manager:public Product{
    public:
        int choice;
        void clear_buffer();
        void display_menu();
        void Transation_menu();
        void Main_menu();
};
extern Manager sys;