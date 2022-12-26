#pragma once
#pragma pack(8)
#include "Date.h"

class Product
{
public:
    int Id = -1;
    char Name[20] = "";
    float Weight;
    float Price;  
    int Num;
    Date EndDate;
    bool Sale;

    Product(){}
    Product(char name[20], float weight, float price, int num, Date endDate, bool sale)
    {
        strncpy_s(Name, name, 20);
        Weight = weight;
        Price = price;
        Num = num;
        EndDate = endDate;
        Sale = sale;
    }

    void Print() {
        setlocale(LC_ALL, "");
        cout << Id << "\t" << Name << "\t\t\t" << Weight << "\t" << Price << "\t" << Num << "\t\t" << EndDate.ToString() << "\t\t\t\t" << Sale;
    }

    bool Compare(Product other)
    {
        if ((strcmp(Name, other.Name) == 0) && (Weight == other.Weight) && (Price == other.Price) && (EndDate == other.EndDate) && (Sale == other.Sale))
            return true;
        return false;
    }
};