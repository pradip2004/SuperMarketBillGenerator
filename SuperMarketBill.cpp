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
      BillGenarate() : item(""), rate(0), quantity(0) {} // default constructor
      void setItem(string item)
      {
            this->item = item;
      }
      void setRate(int rate)
      {
            this->rate = rate;
      }
      void setQuantity(int qty)
      {
            this->quantity = qty;
      }

      string getItem()
      {
            return item;
      }

      int getRate()
      {
            return rate;
      }

      int getQuantity()
      {
            return quantity;
      }
};

void addItem(BillGenarate b)
{
      bool close = false;
      while (!close)
      {
            int choice;
            cout << "\t1.Add." << endl;
            cout << "\t2.Close." << endl;
            cout << "\tEnter choice: ";
            cin >> choice;
            if (choice == 1)
            {
                  system("cls");
                  string item;
                  int rate, quant;

                  cout << "\tEnter Item Name: ";
                  cin >> item;
                  b.setItem(item);

                  cout << "\tEnter Rate: ";
                  cin >> rate;
                  b.setRate(rate);

                  cout << "\tEnter Quantity: ";
                  cin >> quant;
                  b.setQuantity(quant);

                  ofstream out("./Bill.txt", ios::app);
                  if (!out)
                  {
                        cout << "\tError in opening file." << endl;
                  }
                  else
                  {
                        out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl;
                  }
                  out.close();
                  cout << "\tItem Added Successfuly" << endl;
                  Sleep(3000);
            }
            else if (choice == 2)
            {
                  system("cls");
                  close = true;
                  cout << "\t Back To Main Menu!" << endl;
                  Sleep(2000);
            }
      }
}

void printBill()
{
      system("cls");
      int count = 0;
      bool close = false;
      while (!close)
      {
            system("cls");
            int choice;
            cout << "\t1.Add Bill." << endl;
            cout << "\t2.Close Session." << endl;
            cout << "\tEnter Choice: ";
            cin >> choice;

            if (choice == 1)
            {
                  string item;
                  int quant;
                  cout << "\tEnter Item: ";
                  cin >> item;
                  cout << "\tEnter Quantity: ";
                  cin >> quant;

                  ifstream in("./Bill.txt");
                  ofstream out("./Bill Temp.txt");

                  string line;
                  bool found = false;

                  while (getline(in, line))
                  {
                        stringstream ss;
                        ss << line;
                        string itemName;
                        int itemRate, itemQuant;
                        char delimiter;
                        ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                        if (item == itemName)
                        {
                              found = true;
                              if (quant <= itemQuant)
                              {
                                    int amount = itemRate * quant;
                                    cout << "\t Item | Rate | Quantity | Amount" << endl;
                                    cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
                                    int newQuant = itemQuant - quant;
                                    itemQuant = newQuant;
                                    count += amount;

                                    out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl;
                              }
                              else
                              {
                                    cout << "\tSorry, " << item << " Ended!" << endl;
                              }
                        }
                        else
                        {
                              out << line << endl;
                        }
                  }
                  if (!found)
                  {
                        cout << "\tItem Not Available!" << endl;
                  }
                  out.close();
                  in.close();
                  remove("./Bill.txt");
                  rename("./Bill Temp.txt", "./Bill.txt");
            }
            else if (choice == 2)
            {
                  close = true;
                  cout << "\tCounting Total Bill" << endl;
            }
            Sleep(3000);
      }
      system("cls");
      cout << endl
           << endl;
      cout << "\t Total Bill ----------------- : " << count << endl
           << endl;
      cout << "\tThanks For Shopping!" << endl;
      Sleep(5000);
}

int main()
{
      BillGenarate bill;
      bool exit = false;
      while (!exit)
      {
            system("cls");
            int val;
            cout << "\tWelcome Super Market Billing System" << endl;
            cout << "\t************************************" << endl;
            cout << "\t\t1. Add Item." << endl;
            cout << "\t\t2. Print Bill." << endl;
            cout << "\t\t3. Exit." << endl;
            cout << "\t\tEnter your choice: ";
            cin >> val;
            if (val == 1)
            {
                  system("cls");
                  addItem(bill);
                  Sleep(2000);
            }
            else if (val == 2)
            {
                  printBill();
            }
            else if (val == 3)
            {
                  system("cls");
                  exit = true;
                  cout << "\t Exiting..." << endl;
                  Sleep(2000);
            }
      }
      return 0;
}