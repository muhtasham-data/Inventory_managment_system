#include"/home/muhammadmuhtasham/Inventory_managment_system/include/product.hpp"
#include<iostream>
using std::cout,std::getline,std::cin;Product master_db;
void Product::add_product(){
    while(true){
        cout<<"\t=================================\n";
        cout<<"! You can exit any time by entering Q in name !\n";
        cout<<"\t=================================\n";
        cout<<"Enter Product Name: ";
        getline(cin,name);
        if(name=="q"||name=="Q"){
            break;
        }
        cout<<"Enetr Product Catagory: ";
        getline(cin,catagory);
        cout<<"Enter the Product Quantity in numbers: ";
        cin>>quantity;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Enter the Product Quantity in numbers: ";
            cin>>quantity;
        }
        cout<<"Enter The Product batch Price numbers: ";
        cin>>total_price;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Enter The Product batch Price numbers: ";
            cin>>total_price;
        }
        cin.ignore(1000,'\n');
        per_price=total_price/quantity;
        cout<<"Per piece price you want to Display to a custumer in numbers : ";
        cin>>coustumer_price;
        cin.ignore(1000,'\n');
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Per piece price you want to Display to a custumer in numbers : ";
            cin>>coustumer_price;
            cin.ignore(1000,'\n');
        }
        while(true){
            cout<<"Enter your Product Code or ID: ";
            getline(cin,id);
            if(stock_data.find(id)==stock_data.end()){
                stock_data[id]={id,name,catagory,quantity,total_price,per_price,coustumer_price};
                break;
        }
            else{
                cout<<"Already register try to re-stock or enter new id\n";
                cin.clear();
            }
        }
    } 
}
void Product::search(){
    while (true){
        cout<<"=================================\n";
        cout<<"! You can exit any time by entering Q !\n";
        cout<<"=================================\n";
        cout<<"Enter the product id: ";
        getline(cin,t_id);
        if(t_id=="q"||t_id=="Q"){
            break;
        }
        if(stock_data.find(t_id)!=stock_data.end()){
            cout<<"ID: "<<stock_data[t_id].id<<'\n'<<"Product Name: "<<stock_data[t_id].name<<'\n';
            cout<<"Batch Price: "<<stock_data[t_id].total_price<<'\n'<<"Buy price per unit: "<<stock_data[t_id].per_price<<'\n';
            cout<<"Sell price per unit: "<<stock_data[t_id].coustumer_price<<'\n';
            break;
        }
        else{
            cout<<"ID didn't Exist \n";
        } 
    } 
}
void Product::delete_product(){
    search();
    stock_data.erase(t_id);
    cout<<"=================================\n";
    cout<<"Prouduct Deleted Successfully\n";
    cout<<"=================================\n";
}
void Product::low_stock_warning(){
    cout<<"=================================\n";
    cout<<"Warning Below Products are Low in stock\t\n";
    cout<<"=================================\n";
    for(const auto& x:stock_data){
        const auto& stock=x.second;
        if(stock.quntity<=10){
            cout<<"ID: "<<stock.id<<" ";
            cout<<"|Product Name: "<<stock.name<<" ";
            cout<<"|Batch Price: "<<stock.total_price<<" ";
            cout<<"|Single Price: "<<stock.per_price<<" ";
            cout<<"|Quantity: "<<stock.quntity<<" ";
            cout<<"|Category: "<<stock.catagory<<" ";
            cout<<"|Coustmer Price: "<<stock.coustumer_price<<" \n";
        }
    }   
}
void Product::display(){
    for(const auto& x:stock_data){
        const auto& stock=x.second;
        cout<<"ID: "<<stock.id<<" ";
        cout<<"|Product Name: "<<stock.name<<" ";
        cout<<"|Batch Price: "<<stock.total_price<<" ";
        cout<<"|Single Price: "<<stock.per_price<<" ";
        cout<<"|Quantity: "<<stock.quntity<<" ";
        cout<<"|Category: "<<stock.catagory<<" ";
        cout<<"|Coustmer Price: "<<stock.coustumer_price<<" \n";
    }
    low_stock_warning();
} 
void Product::re_stock(){
    search();
    cout<<"Enter the Quantity you want to Stock: ";
    cin>>re_quantity;
    stock_data[t_id].quntity += re_quantity;
    cout<<"ID: "<<stock_data[t_id].id<<'\n'<<"Product Name: "<<stock_data[t_id].name<<'\n';
    cout<<"Batch Price: "<<stock_data[t_id].total_price<<'\n'<<"Buy price per unit: "<<stock_data[t_id].per_price<<'\n';
    cout<<"Sell price per unit: "<<stock_data[t_id].coustumer_price<<"Quantity: "<<stock_data[t_id].quntity<<'\n';
}
void Product::filter(){
    cout<<"=================================\n";
    cout<<"\tFilter by Category\t\n";
    cout<<"=================================\n";
    cout<<"Enter Catagory name you want search: ";
    getline(cin,t_catagory);
    for(const auto& x:stock_data){
        const auto& stock=x.second;
        if(stock.catagory==t_catagory){
            cout<<"ID: "<<stock.id<<" ";
            cout<<"|Product Name: "<<stock.name<<" ";
            cout<<"|Batch Price: "<<stock.total_price<<" ";
            cout<<"|Single Price: "<<stock.per_price<<" ";
            cout<<"|Quantity: "<<stock.quntity<<" ";
            cout<<"|Category: "<<stock.catagory<<" ";
            cout<<"|Coustmer Price: "<<stock.coustumer_price<<" \n";
        }
    } 
}
void Product::sell_Product(){
    ofstream o;
    while(true){
        search();
        cout<<"=======================================\n";
        cout<<"You can exit any time by entering 0 \n";
        cout<<"=======================================\n";
        cout<<"Quantity you want to buy: ";
        cin>>quantity;
        if(quantity<=0){
            break;
        }
        stock_data[t_id].quntity -= quantity;
        amount=stock_data[t_id].coustumer_price*quantity;
        cout<<amount<<"$";
        float pamount=stock_data[t_id].per_price*quantity;
        float profit=amount-pamount;
        sell.emplace_back(amount);
        sprofit.emplace_back(profit);
        o.open("/home/muhammadmuhtasham/Inventory_managment_system/record/recipt.txt");
        o<<"Sell amountfrom "<<t_id<<" is "<<amount<<"$\n";
        o.close();
        o.open("/home/muhammadmuhtasham/Inventory_managment_system/record/profit.txt");
        o<<"Total Profit from "<<t_id<<" is "<<profit<<"$\n";
    }
    float total_amount=std::accumulate(sell.begin(),sell.end(),0.0f);
    float total_profit=std::accumulate(sprofit.begin(),sprofit.end(),0.0f);
    o.open("/home/muhammadmuhtasham/Inventory_managment_system/record/recipt.txt");
    o<<"Total amount is "<<total_amount<<"$\n";
    o.close();
    o.open("/home/muhammadmuhtasham/Inventory_managment_system/record/profit.txt");
    o<<"Total Profit is "<<total_profit<<"$\n";
    o.close();
}
void Product::sort(){
    std::vector<productDetails>product;
    for(auto& x:stock_data){
        product.emplace_back(x.second);
    }
    std::sort(product.begin(),product.end(),[](const auto& a,const auto& b){
        return a.coustumer_price<b.coustumer_price;
    });
    for(const auto& stock : product){
        cout << "ID: " << stock.id << " "
             << "|Product Name: " << stock.name << " "
             << "|Single Price: " << stock.per_price << " "
             << "|Quantity: " << stock.quntity << " "
             << "|Category: " << stock.catagory << " "
             << "|Customer Price: " << stock.coustumer_price << " \n";
    }
}
