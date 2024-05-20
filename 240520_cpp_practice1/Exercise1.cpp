#include <iostream>
#define SNACK_BASKET_SIZE 4

using namespace std;

class Snack
{
public:
	Snack() {}

protected:
	int cost = 0;
	string name;
	string manufacturer;
};

class Candy : public Snack
{
private:
	string flavor;

public:
	Candy()
	{
		//Candy ������
		cout << endl << "- ��, ����, ��ǰ��, ������ �Է�" << endl
			<< "ex) ���� 500 ���Į��� ���Į���" << endl << endl;
		cin >> this->flavor >> this->cost >> this->name >> this->manufacturer;
	}

	void printSnack()
	{
		cout << "Candy ������: " << this->manufacturer << endl;
	}
};

class Chocolate : public Snack
{
private:
	string shape;
	
public:
	Chocolate()
	{
		//Chocolate ������
		cout << endl << "- ���, ����, ��ǰ��, ������ �Է�" << endl
			<< "ex) ȯ 2500 �䷹�ην� �䷹��" << endl << endl;
		cin >> this->shape >> this->cost >> this->name >> this->manufacturer;
	}

	void printSnack()
	{
		cout << "Chocolate ������: " << this->manufacturer << endl;
	}
};

int main()
{
	cout << "* SnackBasket ��ĳ����/�ٿ�ĳ���� �ǽ� *" << endl;

	//��ĳ����
	Snack* candy1 = new Candy();
	Snack* candy2 = new Candy();

	Snack* chocolate1 = new Chocolate();
	Snack* chocolate2 = new Chocolate();

	cout << endl;

	Snack* snackBasket[SNACK_BASKET_SIZE] = { candy1, candy2, chocolate1, chocolate2 };

	for (int i = 0; i < sizeof(snackBasket) / sizeof(snackBasket[0]); i++)
	{
		//�ٿ�ĳ����
		if (i < 2)
		{
			((Candy*)snackBasket[i])->printSnack();
		}
		else
		{
			((Chocolate*)snackBasket[i])->printSnack();
		}
	}

	return 0;
}