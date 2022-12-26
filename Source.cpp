#include<iostream>
#include"MenuCtrl.h"
#include"Product.h"
#include "ListProduct.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	ListProducts listProducts = ListProducts();
	MenuCtrl menu = MenuCtrl();

	menu.StartMenu(listProducts);
}