#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#define MEET_DISTANCE 50	//Fix from 10 to 50
#define MEET_TIME 5000		//Fix from 4000 to 5000
using namespace std;
struct Position
{
	double latitude, longitude;
	unsigned long long time;
	Position* next;
	Position()
	{
		latitude = 0;
		longitude = 0;
		time = 0;
		next = NULL;
	}
};
void append(Position* &start, Position* new_position)
{
	if (start == NULL)
	{
		start = new_position;
		return;
	}
	Position* temp = start;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_position;
}
Position* readFromFile(string filename)
{
	fstream file;
	file.open(filename, ios::in);
	if (!file.is_open())
	{
		cout << "Loi doc file!" << endl;
		return NULL;
	}
	string line;
	Position* start, *new_position;
	start = NULL;
	while (getline(file, line))
	{
		replace(line.begin(), line.end(), ',', ' ');
		new_position = new Position;
		stringstream ss;
		ss.str(line);
		double time;
		ss >> new_position->latitude >> new_position->longitude >> time;
		new_position->time = (unsigned long long) time;
		append(start, new_position);
	}
	file.close();
	return start;
}
void writeToFile(string filename, Position* start)
{
	fstream file;
	file.open(filename, ios::out);
	Position* temp = start;
	while (temp != NULL)
	{
		file << setprecision(10) << temp->latitude << "," << temp->longitude << "," << temp->time << endl;
		temp = temp->next;
	}
	file.close();
}
void findMin(Position* start, Position* &preMin, Position* &min)
{
	if (start == NULL)
	{
		preMin = NULL;
		min = NULL;
		return;
	}
	Position* temp = start;
	preMin = NULL;
	min = start;
	while (temp->next != NULL)
	{
		if (temp->next->time < min->time)
		{
			preMin = temp;
			min = preMin->next;
		}
		temp = temp->next;
	}
}
void sortList(Position* &start)
{
	if (start == NULL)
	{
		return;
	}
	if (start->next == NULL)
	{
		return;
	}
	Position *newList, *preMin, *min;
	newList = NULL;
	while (start != NULL)
	{
		findMin(start, preMin, min);
		append(newList, min);
		if (min == start)
		{
			start = min->next;
		}
		else
		{
			preMin->next = min->next;
		}
		min->next = NULL;
	}
	start = newList;
}
double distance(Position* pos_1, Position* pos_2)
{
	return pow(10, 5)*sqrt(pow(pos_1->latitude - pos_2->latitude, 2) + pow(pos_1->longitude - pos_2->longitude, 2));
}
double loopLengthOfPath(Position* start)
{
	if (start == NULL)
	{
		return 0;
	}
	double length = 0;
	Position* temp = start;
	while (temp->next != NULL)
	{
		length += distance(temp, temp->next);
		temp = temp->next;
	}
	return length;
}
double recursionLengthOfPath(Position* start)
{
	if (start == NULL)
	{
		return 0;
	}
	if (start->next == NULL)
	{
		return 0;
	}
	double length = distance(start, start->next);
	return length + recursionLengthOfPath(start->next);
}
bool checkMeeting(Position* start_1, Position* start_2)
{
	if (start_1 == NULL || start_2 == NULL)
	{
		return false;
	}
	Position* temp_1 = start_1;
	Position* temp_2 = start_2;
	while (abs((long long) (temp_1->time - temp_2->time)) > MEET_TIME || distance(temp_1, temp_2) > MEET_DISTANCE)
	{
		if (temp_1->time > temp_2->time)
		{
			temp_2 = temp_2->next;
		}
		else
		{
			temp_1 = temp_1->next;
		}
		if (temp_1 == NULL || temp_2 == NULL)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	Position* start = readFromFile("position.csv");
	Position* start_2 = readFromFile("position_2.csv");
	sortList(start);
	sortList(start_2);
	cout << loopLengthOfPath(start) << endl;
	cout << recursionLengthOfPath(start_2) << endl;
	string out = checkMeeting(start, start_2) ? "YES" : "NO";
	cout << out << endl;
	writeToFile("sorted.csv", start);
	writeToFile("sorted_2.csv", start_2);
	system("pause");
	return 0;
}