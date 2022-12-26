#pragma once
#pragma warning(disable : 4996) 
#include "Product.h"
#include "ListProduct.h"
#include "Product.h"
#include "InputController.h"
#include <stdio.h>

class MenuCtrl
{
public:
    void StartMenu(ListProducts& Products)
    {
        products = Products;
        bool IsExit = false;
        State state = startMenu;
        setlocale(LC_ALL, "");
        while (!IsExit)
        {
            system("cls");
            PrintMenu();
            int inpNum = 0;
            cin.clear();
            cin.sync();
            cin >> inpNum;
            
            try
            {
                state = static_cast<State>(inpNum);

            }
            catch(exception e)
            {
                state = startMenu;
            }
            switch (state)
            {
            case startMenu:
                break;

            case addMenu:
                InputProductMenu();
                state = startMenu;
                break;

            case deleteMenu:
                DeleteMenu();
                break;

            case showListMenu:
                ShowList();
                system("pause");
                break;

            case saveMenu:
                SaveMenu();
                break;

            case loadMenu:
                LoadMenu();
                break;

            case exit:
                IsExit = true;
                break;

            case clearList:
                ClearMenu();
                break;

            default:
                break;
            }
        }
    }
private:
    ListProducts products;
    InputCtrl inputCtrl = InputCtrl();

    void PrintMenu()
    {
        cout << "Меню:" << endl
            << "1 - Добавить товар(ы)" << endl
            << "2 - Удалить товар(ы)" << endl
            << "3 - Показать список товаров" << endl
            << "4 - Сохранить список в файл" << endl
            << "5 - Загрузить из файла" << endl
            << "6 - Очистить список товаров" << endl << endl
            << "9 - Выход" << endl;
        cout << ("Действие: ");
    }

    void InputProductMenu()
    {
        system("cls");
        cout << "Название продукта\tВес\tЦена\tКоличество\tДата, когда товар испортится\tЕсть ли скидка(1-есть, 0-нет)" << endl;
        products.AddProduct(inputCtrl.InputProduct());
        cout << endl;
    }

    void DeleteMenu()
    {
        ShowList();
        cout << "(Для отмены вредите несуществующий номер)" << endl
            << "Удаляемый товар с ID:";
        int delID;
        cin >> delID;
        products.DeleteProduct(delID);
    }

    void ShowList()
    {
        products.Print();
    }

    void SaveMenu()
    {
        system("cls");
        FILE* f = fopen("C:\\LabProgr\\Save.date", "wb");
        fwrite(products.Count(), sizeof(int), 1, f);
        for (int i = 0; i < *products.Count(); i++)
        {
            fwrite(products.Get(i), sizeof(Product), 1, f);
        }
        fclose(f);
        cout << "Успешно" << endl;
        system("pause");
    }

    void LoadMenu()
    {
        system("cls");
        products.DeleteAll();
        FILE* f = fopen("C:\\LabProgr\\Save.date", "rb");
        int count;
        fread(&count, sizeof(int), 1, f);
        for (int i = 0; i < count; i++)
        {
            Product p;
            fread(&p, sizeof(Product), 1, f);
            products.AddProduct(p);
        }
        cout << "Загружено элементов: " << count << endl;
        system("pause");
    }
    void ClearMenu() 
    {
        system("cls");
        products.DeleteAll();
        cout << "Список успешно очищен" << endl;
        system("pause");
    }

    enum State : int
    {
        startMenu,
        addMenu,
        deleteMenu,
        showListMenu,
        saveMenu,
        loadMenu,
        clearList,
        exit = 9
    };
};