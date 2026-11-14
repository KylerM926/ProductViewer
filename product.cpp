#include <string>
#include <cmath>
#include <stdexcept>
#include "product.h"

using namespace std;

Product::Product(string p_name, double price, int discountPercent){
	name = p_name;
	set_price(price);
	set_discount(discountPercent);
}

void Product::set_price(double p_price){
	if (p_price >= 0.0){
		price = round(p_price * 100) / 100; // round to 2 decimal places if pos number
	} else {
		throw invalid_argument("Price can't be negative!");
	}
}

void Product::set_discount(int p_discount){
	if (p_discount >= 0 && p_discount <= 100){
		discountPercent = p_discount;
	} else {
                throw invalid_argument("Discount must be between 0 and 100!x");
        }

}

double Product::get_discount_amount() const {
	double discountAmt = price * discountPercent / 100;
	return round(discountAmt * 100) / 100;
}

double Product::get_discount_price() const {
	double discountPrice = price - get_discount_amount();
	return round(discountPrice * 100) / 100;
}
