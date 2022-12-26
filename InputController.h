#pragma once
#include "List.h"
#include <Windows.h>


class InputCtrl
{
    void gotoxy(int xpos, int ypos)
    {
        COORD scrn;
        HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
        scrn.X = xpos; scrn.Y = ypos;
        SetConsoleCursorPosition(hOuput, scrn);
    }

    template <typename t>
    t InputType(int targetPos) {
        t temp;
        gotoxy(targetPos, 1);
        cin >> temp;
        return temp;
    }

    template <typename t>
        t* InputTypeMas(int targetPos) {
        t temp[20];
        gotoxy(targetPos, 1);
        cin >> temp;
        return temp;
    }

    void insertSym(int targetPos, char sym) {
        gotoxy(targetPos, 1);
        cout << sym;
    }

    void insertManySym(int targetPos, char sym, int num) {
        for (int i = 0; i < num; i++)
        {
        gotoxy(targetPos+i, 1);
        cout << sym;
        }
    }

    template <typename t>
    t CheckInput(int targetPos, int minValue, int maxValue) {
        t field = InputType<t>(targetPos);
        while (field < minValue || field > maxValue) {
            insertManySym(targetPos, ' ', 3);
            field = InputType<t>(targetPos);
        }
        return field;
    }

    template <typename t>
    t CheckInput(int targetPos, int minValue) {
        t field = InputType<t>(targetPos);
        while (field < minValue) {
            insertManySym(targetPos, ' ', 5);
            field = InputType<t>(targetPos);
        }
        return field;
    }

public:
    Product InputProduct()
    {
        char name[20];
        float weight;
        float price;
        int num;
        Date endDate;
        bool sale;
        bool IsWrong = true;
        while (IsWrong) {
            insertManySym(0, ' ', 120);
            strcpy(name, InputTypeMas<char>(0));
            weight = CheckInput<float>(24, 0);
            price = CheckInput<float>(32, 0);
            num = CheckInput<int>(40, 0);
            int day = CheckInput<int>(56, 0, 31);
            insertSym(58, '/');
            int month = CheckInput<int>(59, 0, 12);
            insertSym(61, '/');
            int year = CheckInput<int>(62, 2020, 2030);
            endDate = Date(day, month, year);
            sale = InputType<bool>(88);

            cout << endl << "Проверьте правильность, введите Y для продолжения: ";
            char contKey;
            cin >> contKey;
            if (contKey == 'Y')
                IsWrong = false;
        }
        
        Product p = Product(name, weight, price, num, endDate, sale);
        return p;
    }
};