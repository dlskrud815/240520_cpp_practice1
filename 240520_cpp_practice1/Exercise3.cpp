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
		cout << this->flavor << "맛 사탕" << endl;
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
		cout << this->shape << "모양 초콜릿" << endl;
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
		cout << endl << "과자 바구니에 추가할 간식을 고르시오.( 1: 사탕, 2: 초콜릿, 0: 종료) : ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "맛을 입력하세요. : ";
			cin >> input;
			snackBasket.push_back(new Candy(input));
			break;
		case 2:
			cout << "모양을 입력하세요. : ";
			cin >> input;
			snackBasket.push_back(new Chocolate(input));
			break;
		case 0:
			cout << endl << "과자 바구니에 담긴 간식의 개수는 " << Snack::getSnackCount() << "개 입니다." << endl << endl;
			cout << "과자 바구니에 담긴 간식 확인하기!" << endl;

			for (auto snack : snackBasket)
			{
				snack->printSnack();
			}

			return 0;
		default:
			cout << "0~2 사이의 숫자를 입력하세요." << endl;
			break;
		}
	}
}