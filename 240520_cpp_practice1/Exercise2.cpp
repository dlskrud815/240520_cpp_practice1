#include <iostream>

using namespace std;

class Person
{
public:
	virtual void intro()
	{
		cout << "����Դϴ�~" << endl;
	}
};

class Student : public Person
{
	string name;

public:
	Student(string name)
	{
		this->name = name;
	}

	void intro()
	{
		cout << name << "�л��Դϴ�." << endl;
	}

	void learn()
	{
		cout << "���ϴ�." << endl;
	}
};

class Teacher : public Person
{
	string name;
	
public:
	Teacher(string name)
	{
		this->name = name;
	}

	void intro()
	{
		cout << name << "�����Դϴ�." << endl;
	}

	void teach()
	{
		cout << "����Ĩ�ϴ�." << endl;
	}
};
int main()
{
	Person* pList[3];
	string names[3];

	cout << "3���� �̸��� �Է����ּ���. ex) ������, �л�, �л�" << endl;
	cin >> names[0] >> names[1] >> names[2];

	cout << endl;

	//names �迭 �̿� �� Ŭ���� ����
	Person* teacher = new Teacher(names[0]);
	Person* student1 = new Student(names[1]);
	Person* student2 = new Student(names[2]);

	//pList�� �Ҵ�
	pList[0] = teacher;
	pList[1] = student1;
	pList[2] = student2;

	for (auto p : pList)
	{
		p->intro();
	}
	
	cout << endl;

	//�� Ŭ������ ���� �Լ� ����
	((Teacher*)pList[0])->teach();
	((Student*)pList[1])->learn();
	((Student*)pList[2])->learn();

	delete teacher;
	delete student1;
	delete student2;

	return 0;
}