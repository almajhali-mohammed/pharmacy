class Sales
{
	Inventory* inventory;
	Treasury* treasury;
	Report* report;

public:
	Sales(map<Product*, int> products) {
		this->inventory = Inventory::getInstance();
		this->treasury = Treasury::getInstance();
		this->report = new Report(products);
	}

	bool Sale() {
		string status = inventory->withdrawFromInventory(products);
		if (status == "success") {
			treasury->deposit(report->getTotalPrice());
			report->showDetails();
			return true;
		}
		else {
			cout << status << endl;
			return false;
		}
	}

	~Sales(){
		delete inventory;
		delete treasury;
		delete report;
	}


};