#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

//fungsi login
bool login() {
	string username, password, user, pass;

	cout << "Masukkan Username : "; cin >> username;
	cout << "Masukkan Password : "; cin >> password;
	

	ifstream read("./accounts/" + username + ".txt");
	getline(read, user);
	getline(read, pass);

	if (user == username && pass == password) {
		return true;
	}
	else {
		return false;
	}
}

//fungsi utama
int main() {
	int choice;
	cout << "-----=====Pilih metode ======-----\n";
	cout << "1. Login\n";
	cout << "2. Registrasi\n";
	cout << "==================================\n";
	cout << "--->>>> : "; cin >> choice; 

	if (choice == 1) 
	{
		bool status = login();

		if (!status) {
			cout << "Username atau Password Salah !\n";
		}
		else 
		{
			cout << "Berhasil Login !\n";
		}
		system("pause");
		return 0;
	}
	else if (choice == 2) 
	{
		string username, password;
		cout << "Pilih Username : "; cin >> username;
		cout << "Pilih Password : "; cin >> password;

		ofstream file;
		file.open("./accounts/" + username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}


}