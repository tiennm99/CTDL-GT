#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct ProductCategory
{
	string ID;
	string name;
	ProductCategory *next;
};

struct Product
{
	string ID;
	string name;
	int selling_price;
	int importing_price;
	double quantity;
	ProductCategory *product_category;
	Product *next;
};

void releaseCategory(ProductCategory* &category_head)
{
	if (category_head != NULL)
	{
		ProductCategory* temp = category_head;
		category_head = category_head->next;
		delete temp;
		releaseCategory(category_head);
	}
}

void releaseProduct(Product* &head)
{
	if (head != NULL)
	{
		Product* temp = head;
		head = head->next;
		delete temp;
		releaseProduct(head);
	}
}

void appendCategory(ProductCategory* &category_head, ProductCategory* newcategory)
{
	if (category_head == NULL)
	{
		category_head = newcategory;
		return;
	}
	ProductCategory *temp = category_head;
	while (temp->next != NULL) temp = temp->next;
	temp->next = newcategory;
}

void appendProduct(Product* &head, Product* new_product)
{
	if (head == NULL)
	{
		head = new_product;
		return;
	}
	Product *temp = head;
	while (temp->next != NULL) temp = temp->next;
	temp->next = new_product;
}

void findProductCategory(ProductCategory* category_head, string ID, ProductCategory* &result)
{
	result = category_head;
	while (result != NULL)
	{
		if (result->ID == ID)
			return;
		result = result->next;
	}
}

void readFromFile(string filename, Product* &head, ProductCategory* &category_head)
{
	releaseCategory(category_head);
	releaseProduct(head);
	ifstream ifs;
	ifs.open(filename, ifstream::in);
	if (!ifs.is_open())
	{
		cout << "Loi doc file!" << endl;
		return;
	}
	string line;
	while (getline(ifs, line))
	{
		replace(line.begin(), line.end(), ',', ' ');
		Product *new_product = new Product;
		string ID, name;
		istringstream iss;
		iss.str(line);
		iss >> new_product->ID
			>> new_product->name
			>> new_product->selling_price
			>> new_product->importing_price
			>> new_product->quantity
			>> ID
			>> name;
		new_product->next = NULL;
		findProductCategory(category_head, ID, new_product->product_category);
		if (new_product->product_category == NULL)
		{
			ProductCategory *new_category = new ProductCategory;
			new_category->ID = ID;
			new_category->name = name;
			new_category->next = NULL;
			appendCategory(category_head, new_category);
			new_product->product_category = new_category;
		}
		appendProduct(head, new_product);
	}
	ifs.close();
}

void writeProductToFile(string filename, Product* head)
{
	ofstream ofs;
	ofs.open(filename, ofstream::out);
	Product* temp = head;
	while (temp != NULL)
	{
		ofs << setprecision(10)
			<< temp->ID << ","
			<< temp->name << ","
			<< temp->selling_price << ","
			<< temp->importing_price << ","
			<< temp->quantity << ","
			<< temp->product_category->ID << ","
			<< temp->product_category->name
			<< endl;
		temp = temp->next;
	}
	ofs.close();
}

void printAllCategories(Product* head)
{
	int cnt = 0;
	ProductCategory *category_head = NULL;
	Product *temp = head;
	while (temp != NULL)
	{
		ProductCategory *result = NULL;
		findProductCategory(category_head, temp->product_category->ID, result);
		if (result == NULL)
		{
			result = new ProductCategory;
			result->ID = temp->product_category->ID;
			result->name = temp->product_category->name;
			result->next = NULL;
			appendCategory(category_head, result);
			++cnt;
		}
		temp = temp->next;
	}
	cout << cnt;
	if (cnt > 1) cout << " categories";
	else cout << " category";
	cout << endl;
	ProductCategory *tmp = category_head;
	while (tmp != NULL)
	{
		cout << "----------------" << endl;
		cout << "ID: " << tmp->ID << endl;
		cout << "Name: " << tmp->name << endl;
		tmp = tmp->next;
	}
	releaseCategory(category_head);
}

bool deleteProducts(Product* &head, double quantity)
{
	int cnt = 0;
	Product *temp, *tmp;
	while (head != NULL)
	{
		if (head->quantity < quantity)
		{
			tmp = head;
			head = head->next;
			delete tmp;
			++cnt;
		}
		else break;
	}
	if (head != NULL)
	{
		temp = head;
		while (temp->next != NULL)
		{
			if (temp->next->quantity < quantity)
			{
				tmp = temp->next;
				temp->next = tmp->next;
				delete tmp;
				++cnt;
				continue;
			}
			temp = temp->next;
		}
	}
	return (cnt > 0);
}

double sellingFromFile(Product* &head, string filename)
{
	ifstream ifs;
	double price = 0;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "Loi doc file" << endl;
		return price;
	}
	string line;
	while (getline(ifs, line))
	{
		replace(line.begin(), line.end(), ',', ' ');
		istringstream iss;
		string ID;
		double quantity;
		iss.str(line);
		iss >> ID >> quantity;
		Product *temp = head;
		while (temp != NULL)
		{
			if (temp->ID == ID)
			{
				if (temp->quantity > quantity)
				{
					price += quantity * temp->selling_price;
					temp->quantity -= quantity;
				}
				else
				{
					price += temp->quantity * temp->selling_price;
					temp->quantity = 0;
				}
				break;
			}
			temp = temp->next;
		}
	}
	ifs.close();
	return price;
}

int main()
{
	Product *head = NULL;
	ProductCategory *category_head = NULL;
	readFromFile("ProductIn.csv", head, category_head);
	double m = sellingFromFile(head, "SellingProduct.csv");
	cout << "Tong so tien: " << m << endl;
	printAllCategories(head);
	bool b = deleteProducts(head, 5);
	if (b)
		cout << "Delete thanh cong!" << endl;
	else
		cout << "Delete khong thanh cong!" << endl;
	writeProductToFile("ProductOut.csv", head);
	system("pause");
	return 0;
}