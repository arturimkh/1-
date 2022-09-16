
#include <iostream>
using namespace std;

struct List {
	int data;
	List* next;
	List* prev;
};

/*0*/void Print(List*& head);
/*1*/void add_first(int num, List*& head);
/*1*/void add_last(int num, List*& end);
/*3*/void delete_last(List*& end);
/*4*/void delete_first(List*& head);
/*5*/void add_by_index(int num, List*& head);
/*6*/void get_element_by_index(int num, List*& head);
/*7*/void delete_by_index(int num, List*& head);
/*8*/void get_size(List*& head);
/*9*/void delete_all(List*& head);
/*10*/void zamena_elements(int index, int num, List*& head);
/*11*/void proverka_na_empty(List*& head);
/*19*/void swap_by_index(int index1, int index2, List*& head);
void menu() {
	cout << "выберите что хотите сделать со списком" << endl;
	cout << "1)добавление в конец списка " << endl;
	cout << "2)добавление в начало списка" << endl;
	cout << "3)удаление последнего элемента" << endl;
	cout << "4)удаление первого элемента" << endl;
	cout << "5)добавление элемента по индексу" << endl;
	cout << "6)получение элемента по индексу" << endl;
	cout << "7)удаление элемента по индексу" << endl;
	cout << "8)получение размера списка" << endl;
	cout << "9)удаление всех элементов списка" << endl;
	cout << "10)замена элемента по индексу на передаваемый элемент" << endl;
	cout << "11)проверка на пустоту списка" << endl;
	cout << "12)обмен двух элементов списка по индексам" << endl;
}



int main()
{
	srand(time(0));
	setlocale(LC_ALL,"Russian");

	List* head;
	List* end;
	List* a;
	a = new List;
	a->prev = NULL;
	a->next = NULL;
	a->data =0;

	head = a;
	end = a;
	head->next = NULL;
	head->prev = NULL;

	int kol_vo;
	cout << "Введите кол-во элеметнов ";
	cin >> kol_vo;

	for (int i = 1; i < kol_vo; i++)
	{
		a = new List;
		end->next = a;
		a->data = i;
		a->prev = end;
		a->next = NULL;
		end = a;
	}
	menu();
	int choice;
	while (1) {
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Введите элемент который хотите вставить в начало" << endl;
			int num;
			cin >> num;
			add_first(num, head);
			Print(head);
			break;
		case 2:
			cout << "Введите элемент который хотите вставить в конец" << endl;
			cin >> num;
			add_last(num, end);
			Print(head);
			break;
		case 3:
			cout << "вы удалили последжний элемент" << endl;
			delete_last(end);
			Print(head);
			break;
		case 4:
			cout << "вы удалили первый элемент" << endl;

			delete_first(head);
			Print(head);
			break;
		case 5:
			cout << "Введите элемент перед которым хотите вставить свой элемент" << endl;
			cin >> num;
			add_by_index(num, head);
			Print(head);
			break;
		case 6:
			cout << "Введите элемент который хотите получить" << endl;
			cin >> num;
			get_element_by_index(num, head);
			Print(head);

			break;
		case 7:
			cout << "Введите элемент который хотите удалить" << endl;
			cin >> num;
			delete_by_index(num,head);
			Print(head);
			break;
		case 8:
			cout << "Вы получили размер списка" << endl;
			get_size(head);
			break;
		case 9:
			cout << "Вы удалили все элементы списка" << endl;
			delete_all(head);
			Print(head);
			break;
		case 10:
			cout << "Введите число и индекс который хотите заменить" << endl;
			int index;
			cin >> num;
			cin >> index;
			zamena_elements(index, num,head);
			Print(head);
			break;
		case 11:
			cout << "вы проверили на пустоту список" << endl;
			proverka_na_empty(head);
			Print(head);
			break;
		case 12:
			cin >> num;
			cin >> index;
			cout << "Введите 2 индекса которых хотите заменить" << endl;
			swap_by_index(num,index,head);
			break;

		}
		menu();
	}
	add_first(-128, head);
	Print(head);
	cout << "Добавление элемента в конец" << endl;
	add_last(145, end);
	Print(head);
	
}
void Print(List*& head) {
	List* a = new List;
	a = head;
	cout << "----------" << endl;
	while (a != NULL)
	{
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
}
void add_first(int num, List*& head) {
	List* a = new List;
	head->prev = a;
	a->prev = NULL;
	a->data = num;
	a->next = head;
	head = a;
}
void add_last(int num, List*& end) {
	List* a = new List;
	a->data = num;
	a->prev = end;
	a->next = NULL;
	end->next = a;
	end = a;
}
void delete_last(List*& end) {
	List* temp = new List;
	temp = end;
	end = end->prev;
	end->next = NULL;
	delete temp;



}
void delete_first(List*& head) {
	List* temp = new List;
	temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
}
void add_by_index(int num, List*& head) {
	List* a = new List;
	List* temp = new List;
	List* temp2 = new List;
	a = head;
	for (int i = 0; i < num - 1; i++) {
		a = a->next;
	}
	temp->data = rand();
	temp2 = a->next->next;

	a->next = temp;
	temp->prev = a;
	temp->next = temp2;
	temp2->prev = temp;

}

void get_element_by_index(int num, List*& head) {
	List* a = new List;
	a = head;
	for (int i = 0; i < num; i++) {
		a = a->next;
	}
	cout << a->data << endl;
}
void delete_by_index(int num, List*& head) {
	List* a = new List;
	List* temp = new List;
	List* temp2 = new List;
	a = head;
	for (int i = 0; i < num - 1; i++) {
		a = a->next;
	}
	temp = a->next;
	temp2 = a->next->next;
	delete temp;
	a->next = temp2;
	temp2->prev = a;
}
void get_size(List*& head) {
	List* a = new List;
	a = head;
	int cnt = 0;
	while (a != NULL)
	{
		cnt++;
		a = a->next;
	}
	cout << "Список размером " << cnt << endl;
}
void delete_all(List*& head) {
	List* a = new List;
	a = head;
	while (a != NULL)
	{
		a->data = 0;
		a = a->next;
	}
}
void zamena_elements(int index, int num, List*& head) {
	List* a = new List;
	a = head;
	for (int i = 0; i < index; i++) {
		a = a->next;
	}
	a->data = num;
}
void proverka_na_empty(List*& head) {
	List* a = new List;
	a = head;
	bool flag = false;
	while ((a != NULL) && (flag == false))
	{
		if (a->data != 0) { flag = true; }
		else {
			a = a->next;
		}
	}
	if (flag) {
		cout << "Список не пустой" << endl;
	}
	else {
		cout << "Список пустой" << endl;
	}
}
void swap_by_index(int index1, int index2, List*& head) {
	List* a = new List;
	List* b = new List;
	a = head;
	b = head;
	for (int i = 0; i < index1; i++) {
		a = a->next;
	}
	int elem1 = a->data;
	for (int i = 0; i < index2; i++) {
		b = b->next;
	}
	int elem2 = b->data;
	a->data = elem2;
	b->data = elem1;
}

