#pragma once
#include "Product.h"
#include "List.h"

class ListProducts
{

    List<Product> products = List<Product>();
    int tId = 1;


public:
    int* Count() { return &products.Count; }
    Product* Get(int id) { return products.Get(id); }

    void AddProduct(Product product)
    {
        product.Id = tId;
        for (int i = 0; i < products.Count; i++)
        {
            Product prod = *products.Get(i);
            if (prod.Compare(product))
            {
                prod.Num += product.Num;
                return;
            }
        }
        products.Add(product);
        tId++;
    }

    void Print()
    {
        system("cls");
        cout << "ID\tНазвание продукта\tВес\tЦена\tКоличество\tДата, когда товар испортится\tЕсть ли скидка" << endl;
        for (int i = 0; i < products.Count; i++)
        {
            Product prod = *products.Get(i);
            prod.Print();
            cout << endl;
        }
    }

    void DeleteProduct(int id)
    {
        system("cls");
        try
        {
            products.RemoveAt(id - 1);    
            for (int i = id - 1; i < products.Count; i++)
            {
                products.Get(i)->Id--;
            }
            tId--;
            cout << "Удалено" << endl;
            system("pause");
        }
        catch (...)
        {
            cout << "Отменено" << endl;
            system("pause");
        }
    }
    void DeleteAll() {
        products.Clear();
        tId = 1;
    }
};