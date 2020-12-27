#include <string>
#include <iostream>
using namespace std;

typedef int DataType;

class Node
{
public:
	DataType data;
	Node *next;
	Node *prev;
};

class TwoWayLinkList
{
public:
	TwoWayLinkList();
	~TwoWayLinkList();
	int CreateTwoWayLinkList(int size);
	int BYETwoWayLinkList();/*����*/
	int TravalTwoWayLinkList();/*��������*/
	int InsertTwoWayLinklList(Node *data, int n);/*ͷ�崫0/1��β�崫this->size+1*/
	int DeleteTwoWayLinklist(int n);/*ɾ���ڵ�*/

	int GetLen();
	bool IsEmply();

	Node *head;
	int size;
};

TwoWayLinkList::TwoWayLinkList()
{
	head = new Node;
	head->data ;/*����ͷ��㲻�����ݵģ�ֻ��һ������Ŀ�ʼ��Ƕ���*/
	head->next = NULL;
	head->prev = NULL;/*ͷ�ڵ�ûprevָ��*/
	size = 0;
}

TwoWayLinkList::~TwoWayLinkList()
{
	delete head;
}

int TwoWayLinkList::CreateTwoWayLinkList(int size)
{
	if (size < 0) {
		printf("error\n");
		return -1;
	}
	Node *ptemp = NULL;
	Node *pnew = NULL;

	this->size = size;
	ptemp = this->head;
	for (int i = 0; i<size; i++)
	{
		pnew = new Node;
		pnew->next = NULL;
		pnew->prev = NULL;
		cout << "�����" << i + 1 << "���ڵ�ֵ" << endl;
		cin >> pnew->data;
		ptemp->next = pnew;
		pnew->prev = ptemp;
		ptemp = pnew;
	}
	cout << "Create Completion" << endl;
	return 0;
}

int TwoWayLinkList::BYETwoWayLinkList()
{
	Node *ptemp;
	if (this->head == NULL) {
		cout << "The list is empty" << endl;
		return -1;
	}
	while (this->head)
	{
		ptemp = head->next;
		free(head);
		head = ptemp;
	}
	cout << "Destruction List Completion" << endl;
	return 0;
}

int TwoWayLinkList::TravalTwoWayLinkList()
{
	Node *ptemp = this->head->next;
	if (this->head == NULL) {
		cout << "The list is empty" << endl;
		return -1;
	}
	while (ptemp)
	{
		cout << ptemp->data << "->";
		ptemp = ptemp->next;
	}
	cout << "NULL" << endl;
	return 0;
}

int TwoWayLinkList::InsertTwoWayLinklList(Node *data, int n)
{
	Node *ptemp;
	if (this->head == NULL) {
		cout << "The list is empty" << endl;
		return -1;
	}
	if (data == NULL) {
		cout << "The insertion node is NULL" << endl;
		return -1;
	}
/*��ͬ���뷽��*/
	//ͷ��
	if (n<2) {
		Node *pnew = new Node;
		pnew->data = data->data;
		pnew->next = this->head->next;
		pnew->prev = this->head;
		//this->head->next->prev = pnew;
		this->head->next = pnew;
		this->size++;
		return 0;
	}
	//β��
	// if (n > this->size) {
	// 	ptemp = this->head;
	// 	while (ptemp->next != NULL) {
	// 		ptemp = ptemp->next;
	// 	}
	// 	Node *pnew = new Node;
	// 	pnew->data = data->data;
	// 	pnew->next = NULL;
	// 	pnew->prev = ptemp;
	// 	ptemp->next = pnew;
	// 	this->size++;
	// 	return 0;
	// }
	//�м��
	else {
		ptemp = this->head;
		for (int i = 1; i <= n; i++) {
			ptemp = ptemp->next;
		}
		Node *pnew = new Node;
		pnew->data = data->data;
		pnew->next = ptemp->next;
		pnew->prev = ptemp;
	//	ptemp->next->prev = pnew;
		ptemp->next = pnew;
		this->size++;
		return 0;
	}
}

int TwoWayLinkList::DeleteTwoWayLinklist(int n)
{
	Node *ptemp;
	Node *ptemp2;
	if (n > this->size) {
		cout << "The Input size is Go beyond" << endl;
		return -1;
	}
	//ɾͷ�ڵ�
	if (n < 2) {
		ptemp = this->head->next;
		this->head->next = ptemp->next;
		ptemp->next->prev = this->head;
		free(ptemp);
		this->size--;
		return 0;
	}
	//β��ɾ��
	if (n == this->size) {
		ptemp = this->head;
		for (int i = 1; i < this->size; i++) {
			ptemp = ptemp->next;
		}
		ptemp2 = ptemp->next;
		ptemp->next = NULL;
		free(ptemp2);
		this->size--;
		return 0;
	}
	//�м�ɾ��
	else
	{
		ptemp = this->head;
		for (int i = 1; i < n; i++) {
			ptemp = ptemp->next;
		}
		ptemp2 = ptemp->next;
		ptemp->next = ptemp2->next;
		//ptemp2->next->prev = ptemp;
		free(ptemp2);
		this->size--;
		return 0;
	}
}

int TwoWayLinkList::GetLen()
{
	return this->size;
}

bool TwoWayLinkList::IsEmply()
{
	if (this->head->next == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int main(void)
{
	Node temp;
	temp.data = 9;
	temp.next = NULL;
	temp.prev = NULL;

	TwoWayLinkList list;
	TwoWayLinkList *plist = &list;
	plist->CreateTwoWayLinkList(5);
	plist->TravalTwoWayLinkList();
	plist->InsertTwoWayLinklList(&temp, 0);
	plist->TravalTwoWayLinkList();
	plist->InsertTwoWayLinklList(&temp, 3);
	plist->TravalTwoWayLinkList();
	plist->InsertTwoWayLinklList(&temp, plist->size);
	plist->TravalTwoWayLinkList();
	plist->DeleteTwoWayLinklist(0);
	plist->TravalTwoWayLinkList();
	plist->DeleteTwoWayLinklist(3);
	plist->TravalTwoWayLinkList();
	system("pause");
	return 0;
}
