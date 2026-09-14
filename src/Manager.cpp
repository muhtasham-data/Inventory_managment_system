#include<iostream>
#include "/home/muhammadmuhtasham/Inventory_managment_system/include/Manager.hpp"
using std::cin,std::cout;Manager sys;
void Manager::clear_buffer(){
    cin.ignore(1000,'\n');
}
void Manager::display_menu(){
    while (true){
        cout<<"========================================\n";
    cout<<"\tDisplay Menu\t\n";
    cout<<"========================================\n";
    cout<<"1.Display all Products\n";
    cout<<"2.Display Product By Low Price\n";
    cout<<"3.Display By Category\n";
    cout<<"4.Exit\n";
    cout<<"Enter Your choice in numbers: ";
    cin>>choice;
    while(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Enter Your choice in numbers: ";
        cin>>choice;
    }
    clear_buffer();
    switch(choice){
        case 1:
            display();
            break;
        case 2:
            sort();
            break;
        case 3:
            filter();
            break;
        case 4:
            return;
        default:
            cout<<"Enter your choice 1-3\n";
            break;
        }
    }
}
void Manager::Main_menu(){
    while (true){
    cout<<"========================================\n";
    cout<<"\tMain menu\t\n";
    cout<<"========================================\n";
    cout<<"1.Add Product\n2.Delete Product\n3.Search Product\n4.Display Menu\n";
    cout<<"5.Transation menu\n6.Exit\n";
    cout<<"Enter Your choice in numbers: ";
    cin>>choice;
    while(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Enter Your choice in numbers: ";
        cin>>choice;
    }
    clear_buffer();
    switch (choice){
        case 1:
            add_product();
            break;
        case 2:
            delete_product();
            break;
        case 3:
            search();
            break;
        case 4:
            display_menu();
            break;
        case 5:
            Transation_menu();
            break;
        case 6:
            return;
        default:
            cout<<"Enter your choice 1-6\n";
            break;
        }
        
    }
}
void Manager::Transation_menu(){
    while (true){
       cout<<"========================================\n";
    cout<<"\tTransation Menu\t\n";
    cout<<"========================================\n";
    cout<<"1.Re-stock Produts\n";
    cout<<"2.Sell Products\n";
    cout<<"3.Exit\n";
    cout<<"Enter Your choice in numbers: ";
    cin>>choice;
    while(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Enter Your choice in numbers: ";
        cin>>choice;
    }
    clear_buffer();
    switch (choice){
        case 1:
            re_stock();
            break;
        case 2:
            sell_Product();
            break;
        case 3:
            return;
        default:
            cout<<"Enter your choice 1-3\n";
            break;
        }
    }
}
int main(){
    sys.Main_menu();
}