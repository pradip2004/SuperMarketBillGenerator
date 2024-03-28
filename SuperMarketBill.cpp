#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class BillGenarate
{
private:
      string item;
      int rate, quantity;
public:
      BillGenarate():item(""), rate(0), quantity(0) {} // default constructor
      void setItem(string item){
            this->item = item;
      }
      void setRate(int rate){
            this->rate = rate;
      }
      void setQuantity(int qty){
            this->quantity = qty;
      }

      string getItem(){
            return item;
      }

      int getRate(){
            return rate;
      }

      int getQuantity(){
            return quantity;
      }
};

void addItem(BillGenarate b){
      bool close = false;
      while(!close){
            int choice;
            cout<<"\t1.Add."<<endl;
            cout<<"\t2.Close."<<endl;
            cout<<"\tEnter choice: ";
            cin>>choice;
            if(choice == 1){
                  system("cls");
                  string item;
                  int rate, quant;

                  cout<<"\tEnter Item Name: ";
                  cin>>item;
                  b.setItem(item);

                  cout<<"\tEnter Rate: ";
                  cin>>rate;
                  b.setRate(rate);

                  cout<<"\tEnter Quantity: ";
                  cin>>quant;
                  b.setQuantity(quant);

                  ofstream out("./Bill.txt", ios::app);
                  if(!out){
                        cout<<"\tError in opening file."<<endl;
                  }else{
                        out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuantity()<<endl<<endl;
                  }
                  out.close();
                  cout<<"\tItem Added Successfuly"<<endl;
                  Sleep(3000);
            }else if(choice == 2){
                  system("cls");
                  close = true;
                  cout<<"\t Back To Main Menu!"<<endl;
                  Sleep(2000);
            }

      }
}


void printBill(BillGenarate b){
      system("cls");
      int count = 0;
      bool close = false;
      while(!close){
            system("cls");
            int choice;
            cout<<"\t1.Add Bill"<<endl;
            cout<<"\t2. Close Session."<<endl;
            cout<<"\tEnter choice: ";
            cin>>choice;
            if(choice == 1){
                  string item;
                  int quant;
                  cout<<"\tEnter Item Name: ";
                  cin>>item;
                  cout<<"\tEnter Quantity: ";
                  cin>>quant;

                  ifstream in("./Bill.txt");
                  ofstream out("./Bill_temp.txt");

                  string line;
                  bool found = false;
                  while(getline(in, line)){
                        stringstream ss;
                        ss<<line;
                        string itemName;
                        int itemRate, itemQuant;
                        char delimiter;
                        ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;

                        if(item == itemName){
                              found = true;
                              if(quant <= itemQuant){
                                    int amount = itemRate * quant;
                                    cout<<"\t Item | Rate | Quantity | Amount"<<endl;
                                    cout<<"\t "<<itemName<<"\t "<<itemRate<<"\t "<<quant<<"\t "<<amount<<endl;
                                    
                              }
                        }else{

                        }

                  }
            }
      }
}


int main(){
      BillGenarate bill;
      bool exit = false;
      while(!exit){
            system("cls");
            int val;
            cout<<"\tWelcome Super Market Billing System"<<endl;
            cout<<"\t************************************"<<endl;
            cout<<"\t\t1. Add Item."<<endl;
            cout<<"\t\t2. Print Bill."<<endl;
            cout<<"\t\t3. Exit."<<endl;
            cout<<"\t\tEnter your choice: ";
            cin>>val;
            if(val == 1){
                  system("cls");
                  addItem(bill);
                  Sleep(2000);
            }else if(val == 2){

            }

      }
      return 0;
}