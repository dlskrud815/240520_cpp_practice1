#include <iostream>
#include <vector>

using namespace std;

class Snack
{
protected:
	static int snackCount;

public:
	Snack() { snackCount++; }
	virtual ~Snack() { snackCount--; }

	virtual void printSnack() {}
	static int getSnackCount() { return snackCount; }
};

class Candy : public Snack
{
private:
	string flavor;

public:
	Candy(string input)
	{
		this->flavor = input;
	}

	void printSnack() override
	{
		cout << this->flavor << "�� ����" << endl;
	}
};

class Chocolate : public Snack
{
private:
	string shape;

public:
	Chocolate(string input)
	{
		this->shape = input;
	}

	void printSnack() override
	{
		cout << this->shape << "��� ���ݸ�" << endl;
	}
};

int Snack::snackCount = 0;

int main()
{
	int option;
	string input;
	vector<Snack*> snackBasket;

	while (1)
	{
		cout << endl << "���� �ٱ��Ͽ� �߰��� ������ ���ÿ�.( 1: ����, 2: ���ݸ�, 0: ����) : ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "���� �Է��ϼ���. : ";
			cin >> input;
			snackBasket.push_back(new Candy(input));
			break;
		case 2:
			cout << "����� �Է��ϼ���. : ";
			cin >> input;
			snackBasket.push_back(new Chocolate(input));
			break;
		case 0:
			cout << endl << "���� �ٱ��Ͽ� ��� ������ ������ " << Snack::getSnackCount() << "�� �Դϴ�." << endl << endl;
			cout << "���� �ٱ��Ͽ� ��� ���� Ȯ���ϱ�!" << endl;

			for (auto snack : snackBasket)
			{
				snack->printSnack();
			}

			return 0;
		default:
			cout << "0~2 ������ ���ڸ� �Է��ϼ���." << endl;
			break;
		}
	}
}