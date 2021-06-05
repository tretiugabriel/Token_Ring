#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
using namespace std;
void citire_ipuri(vector<string>&ipuri,int &nr)
{    
	cout << "Introduceti numarul de calculatoare: ";
	cin >> nr;
	cout << "Introduceti ip-urile calculatoarelor :";
	for (int index = 0; index < nr; index++)
	{
		string ip;
		cin >> ip;
		ipuri.push_back(ip);
	}
}
void citire_token(Token &t)
{
	int ip1,ip2;
	string mesaj;
	cout << "Introduceti ip-up de plecare: ";
	cin >> ip1;
	t.ip_plecare = ip1;
	cout << "Introduceti ip-up destinatie: ";
	cin >> ip2;
	t.ip_destinatie = ip2;
	cout << "Introduceti mesajul pe care doriti sa il transmiteti: ";
	cin >> mesaj;
	t.mesaj = mesaj;
}
void afisare_normal(Token t, vector<string>calculatoare)
{
	for (int index = t.ip_plecare; index <= calculatoare.size(); index++)
	{
		if (index == t.ip_destinatie)
			t.trimis = "Da";

		
		t.istoric.push_back(to_string(index));
		cout << "Token:{" << t.ip_plecare << ", " << t.ip_destinatie << ", " << t.mesaj << ", " << t.trimis << ", " << t.liber << ", "<<"[";
		for (int index = 0; index < t.istoric.size(); index++)
			cout << t.istoric[index] << " ";
		cout << "] }"<<endl;
		if (index == t.ip_destinatie)
			cout << "Mesaj transmis cu succes=" << t.mesaj<<endl;
	}

	for (int index = 1; index <= t.ip_plecare; index++)
	{

		if (index == t.ip_destinatie)
			t.trimis = "Da";
		t.istoric.push_back(to_string(index));
		cout << "Token:{" << t.ip_plecare << ", " << t.ip_destinatie << ", " << t.mesaj << ", " << t.trimis << ", " << t.liber << ", " << "[";
		for (int index = 0; index < t.istoric.size(); index++)
			cout << t.istoric[index] << " ";
		cout << "] }" << endl;
		if (index == t.ip_destinatie)
			cout << "Mesaj transmis cu succes=" << t.mesaj << endl;
	}

	t.liber = "Da";
	t.mesaj = "";
	cout << "Token:{" << " " << ", " << " " << ", " << " " << ", " << " " << ", " << t.liber << ", " << "[";
	cout << "] }-jetonul a fost golit" << endl;

}
void afisare_invers(Token t, vector<string>calculatoare)
{
	for (int index = t.ip_plecare; index>0; index--)
	{

		if (index == t.ip_destinatie)
			t.trimis = "Da";
		t.istoric.push_back(to_string(index));
		cout << "Token:{" << t.ip_plecare << ", " << t.ip_destinatie << ", " << t.mesaj << ", " << t.trimis << ", " << t.liber << ", " << "[";
		for (int index = 0; index < t.istoric.size(); index++)
			cout << t.istoric[index] << " ";
		cout << "] }" << endl;
		if (index == t.ip_destinatie)
			cout << "Mesaj transmis cu succes=" << t.mesaj << endl;
	}
	for (int index = calculatoare.size(); index>=t.ip_plecare; index--)
	{
		if (index == t.ip_destinatie)
			t.trimis = "Da";


		t.istoric.push_back(to_string(index));
		cout << "Token:{" << t.ip_plecare << ", " << t.ip_destinatie << ", " << t.mesaj << ", " << t.trimis << ", " << t.liber << ", " << "[";
		for (int index = 0; index < t.istoric.size(); index++)
			cout << t.istoric[index] << " ";
		cout << "] }" << endl;
		if (index == t.ip_destinatie)
			cout << "Mesaj transmis cu succes=" << t.mesaj << endl;
	}

	
	t.liber = "Da";
	t.mesaj = "";
	cout << "Token:{" << " " << ", " << " " << ", " << " " << ", " << " " << ", " << t.liber << ", " << "[";
	cout << "] }-jetonul a fost golit" << endl;
}
int main()
{
	Token token;
	vector<string>calculatoare;
	int nr_calculatoare;
	cout << "Optiunile dumneavoasta sunt:" << std::endl;
	cout << "1 Oprire program." << std::endl;
	cout << "2 Sens acelor de ceasornic." << std::endl;
	cout << "3 Sens invers acelor de ceasornic." << std::endl;
	cout << "Alegeti optiunea:";
	int optiune;
	cin >> optiune;
	citire_ipuri(calculatoare, nr_calculatoare);
	while (optiune != 1)
	{
		if (optiune == 2)
		{
			
			citire_token(token);
			afisare_normal(token, calculatoare);

		}
		if (optiune == 3)
		{
			
			citire_token(token);
			afisare_invers(token, calculatoare);
		}
		cout << "Alegeti optiunea:";
		cin >> optiune;
	}
	
}
