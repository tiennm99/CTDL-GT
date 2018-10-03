#include <iostream>
#include <iomanip>
using namespace std;
class candidate
{
public:
	int id;
	char* name;
private:
	float math, physics, chemistry;
public:
	candidate(int id, char* name, float math, float physics, float chemistry)
	{
		this->id = id;
		this->name = name;
		this->math = math;
		this->physics = physics;
		this->chemistry = chemistry;
	}
	~candidate()
	{
		id = 0;
		delete[] name;
		name = NULL;
		math = 0;
		physics = 0;
		chemistry = 0;
	}
	float total_grade()
	{
		return (math + physics + chemistry);
	}
};
int main()
{
	candidate *t;
	float tongdiem;
	int id;
	char *name = new char[256];
	float math, physics, chemistry;
	cout << "Nhap id: " << endl;
	cin >> id;
	cout << "Nhap ten: " << endl;
	cin.clear();
	cin.ignore(999, '\n');
	cin.getline(name, 256);
	cout << "Nhap diem Toan: " << endl;
	cin >> math;
	cout << "Nhap diem Ly: " << endl;
	cin >> physics;
	cout << "Nhap diem Hoa: " << endl;
	cin >> chemistry;
	t = new candidate(id, name, math, physics, chemistry);
	tongdiem = t->total_grade();
	cout << "Tong diem: " << setprecision(4) << tongdiem << endl;
	delete t;
	t = NULL;
	system("pause");
	return 0;
}