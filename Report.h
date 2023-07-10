#include <iostream>
#include <map>


class Report
{
private:
	string releaseDate;
	string pharmacyName;
	string address;
	string pharmacyPhone;
	float totalPrice;
	map<Product*, int> products;
	map<Product*, int>::iterator it;
public:
	Report(map<Product*, int> products) {
		this->products = products;
		it = this->products.begin();
		releaseDate = DateTime().getDateTime();
	}
	
	float getTotalPrice() {
		float sum = 0;
		while (it != products.end()) {
			sum += (it->first)->price * it->second;
			it++;
		}
		it = this->products.begin();
		totalPrice = sum;
		return totalPrice;
	}

	void showDetails(){
		cout << "Pharmacy :" << pharmacyName << "Phone: " << pharmacyPhone << "\n Date: " << releaseDate << endl;
		cout << " Product \t Quantity \t Price \t Total Price\n";
		while (it != products.end()) {
			cout << (it->first)->name << "\t" << it->second << "\t" << (it->first)->price << "\t" << (it->first)->price * it->second << endl;
			it++;
		}
		it = this->products.begin();
		cout << "Total Price: " << getTotalPrice()<<endl;
	}

	void modify(map<Product*, int> products){
		this->products = products;
	}

	~Report() {
		while (it != products.end()) {
			delete it->first;
			it++;
		}
			
	}
};