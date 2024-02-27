#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

void openTxt() {
	string currentDir = filesystem::current_path().string();

	for (const auto& entry : filesystem::directory_iterator(currentDir)) {
		if (filesystem::is_regular_file(entry) && entry.path().extension() == ".txt") {
			ifstream file(entry.path());
			if (file.is_open()) {
				cout << "Содержание файла по адресу: " << entry.path() << ":" << endl;
				string line;
				while (getline(file, line)) {
					cout << line << endl;
				}
				file.close();
			}
			else {
				cerr << "Ошибка в получении файла: " << entry.path() << endl;
			}
		}
	}
}


void saveText() {
	string filename;

	cout << "Введите название файла: ";
	cin >> filename;

	ofstream file(filename);

	if (file.is_open()) {
		string line;

		while (true) {

			getline(cin, line);

			if (line == "000") {
				break;
			}


			file << line << endl;
		}

		cout << "Текст сохранен в файле: " << filename << endl;
		file.close();
	}
	else {
		cerr << "Ошибка" << endl;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	while (true) {
		cout << "---Organiser by n3ver---" << endl;
		cout << "Список файлов органайзера:" << endl;
		openTxt();
		saveText();
		system("cls");
	}
	
	
}
