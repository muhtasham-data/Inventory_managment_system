#pragma once
#include<map>
#include<string>
using std::string;
class Product{
    public:
    struct productDetails{
        string id,name,catagory;
        int quntity;
        float total_price,per_price,coustumer_price;
    };
    string id,name,t_id,catagory;int quantity,re_quantity;float total_price,per_price,coustumer_price;
    std::map<string,productDetails>stock_data;
    void add_product();//done
    void search();//done
    void delete_product();//done
    void display();//done
    void re_stock();
    void low_stock_warning();//done
    void sell_Product();
};
extern Product master_db;