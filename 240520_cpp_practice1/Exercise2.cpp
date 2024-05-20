#include <iostream>

using namespace std;

class Person
{
public:
	virtual void intro()
	{
		cout << "사람입니다~" << endl;
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
		cout << name << "학생입니다." << endl;
	}

	void learn()
	{
		cout << "배웁니다." << endl;
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
		cout << name << "선생입니다." << endl;
	}

	void teach()
	{
		cout << "가르칩니다." << endl;
	}
};
int main()
{
	Person* pList[3];
	string names[3];

	cout << "3명의 이름을 입력해주세요. ex) 선생님, 학생, 학생" << endl;
	cin >> names[0] >> names[1] >> names[2];

	cout << endl;

	//names 배열 이용 각 클래스 생성
	Person* teacher = new Teacher(names[0]);
	Person* student1 = new Student(names[1]);
	Person* student2 = new Student(names[2]);

	//pList에 할당
	pList[0] = teacher;
	pList[1] = student1;
	pList[2] = student2;

	for (auto p : pList)
	{
		p->intro();
	}
	
	cout << endl;

	//각 클래스의 고유 함수 실행
	((Teacher*)pList[0])->teach();
	((Student*)pList[1])->learn();
	((Student*)pList[2])->learn();

	delete teacher;
	delete student1;
	delete student2;

	return 0;
}