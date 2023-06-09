#include <iostream>
using namespace std;

struct Node {				//Membuat Metode Struct
	int noMhs;
	string name;
	Node* next;
};

Node* START = NULL;

void addNode() {						//membuat void addNode
	int nim;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukkan NIM: ";
	cin >> nim;
	cout << "Masukkan Nama: ";
	cin >> nama;
	nodeBaru->noMhs = nim;
	nodeBaru->name = nama;

	if (START == NULL || nim <= START->noMhs) {			//mebuat kondisi di dalam void addNode
		if (START != NULL && nim == START->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}

		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool searchNode(int nim, Node* current, Node* previous) {				//membuat boolean searchNode
	previous = START;
	current = START;
	while (current != NULL && nim > current->noMhs)						//membuat kondisi didalam bool searchNode
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return false;
	}
	else if (current->noMhs == nim)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool deleteNode(int nim) {						//membuat bool deleteNode
	Node* current = START;
	Node* previous = START;
	if (searchNode(nim, previous, current) == false)		//kondisi 1
		return false;
	previous->next = current->next;
	if (current == START)									//kondisi 2
		START = current->next;
	return true;
}
bool listEmpty() {								//membuat bool listEmpty
	if (START == NULL)							//membuat kondisi didalam bool listEmpty
		return true;
	else
		return false;
}

void traverse() {								//membuat void traverse
	if (listEmpty()) {							//membuat kondisi didalam void traverse
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}


void searchData() {							//membuat void searchData
	if (listEmpty()) {						//membuat kondisi dalam void searchData
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukkan NIM: ";
		cin >> nim;
		Node* currentNode = START;
		while (currentNode != NULL) {
			if (currentNode->noMhs == nim) {
				cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Data tidak ditemukan" << endl;
	}
}

int main() {									//main program
	int pilihan;
	do
	{
		try
		{
			cout << "1. Tambah Data" << endl;
			cout << "2. Hapus Data" << endl;
			cout << "3. Tampilkan Data" << endl;
			cout << "4. Cari Data" << endl;
			cout << "5. Keluar" << endl;
			cout << "Pilihan" << endl;
			cin >> pilihan;
			switch (pilihan)					//membuat statement switch case untuk membuat program pilihan
			{
			case 1:												//case 1 untuk pilihan pertama
				addNode();
				cout << "Data berhasil Ditambahkan" << endl;
				system("pause");
				system("cls");
				break;
			case 2:												//case 2 untuk pilihan kedua
				if (listEmpty())
				{
					cout << "List Kosong" << endl;
					system("pause");
					system("cls");
					break;
				}

				int nim;
				cout << "Masukkan NIM: ";
				cin >> nim;
				if (deleteNode(nim)) {								//membuat kondisi didalam case 2
					cout << "nim: " << nim << "berhasil dihapus" << endl;
					system("pause");
					system("cls");
				}
				else
					cout << "Data tidak ditemukan" << endl;
				break;
			case 3:											//case 3 untuk pilihan ketiga merujuk ke void traverse
				traverse();
				break;
			case 4:											//case 4 untuk pilihan keempat merujuk ke void searchData
				searchData();
			case 5:											//case 5 untuk pilihan kelima merujuk keluar program
				break;
			default:
				cout << "Pilihan Tidak Ada" << endl;
				break;
			}
		}
		catch (exception e)									//membuat catch untuk menghindari program error
		{
			cout << "Terjadi Kesalahan" << endl;
		}
	} while (pilihan != 5);
}