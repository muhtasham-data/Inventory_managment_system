#pragma once
#include<map>
#include<string>
#include<fstream>
#include<vector>
#include<numeric>
#include<algorithm>
using std::string,std::ofstream;
class Product{
    public:
    struct productDetails{
        string id,name,catagory;
        int quntity;
        float total_price,per_price,coustumer_price;
    };
    string id,name,t_id,catagory,t_catagory;int quantity,re_quantity;float total_price,per_price,coustumer_price,amount;
    std::map<string,productDetails>stock_data;
    std::vector<float>sell;
    std::vector<float>sprofit;
    void add_product();//done
    void search();//done
    void delete_product();//done
    void display();//done
    void re_stock();//done
    void low_stock_warning();//done
    void sell_Product();//done
    void sort();
    void filter();//done
};
extern Product master_db;