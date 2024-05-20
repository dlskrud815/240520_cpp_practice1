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
		//Candy »ý¼ºÀÚ
		cout << endl << "- ¸À, °¡°Ý, »óÇ°¸í, Á¦Á¶»ç ÀÔ·Â" << endl
			<< "ex) µþ±â 500 ÃòÆÄ®½º ÃòÆÄ®½º" << endl << endl;
		cin >> this->flavor >> this->cost >> this->name >> this->manufacturer;
	}

	void printSnack()
	{
		cout << "Candy Á¦Á¶»ç: " << this->manufacturer << endl;
	}
};

class Chocolate : public Snack
{
private:
	string shape;
	
public:
	Chocolate()
	{
		//Chocolate »ý¼ºÀÚ
		cout << endl << "- ¸ð¾ç, °¡°Ý, »óÇ°¸í, Á¦Á¶»ç ÀÔ·Â" << endl
			<< "ex) È¯ 2500 Æä·¹·Î·Î½¦ Æä·¹·Î" << endl << endl;
		cin >> this->shape >> this->cost >> this->name >> this->manufacturer;
	}

	void printSnack()
	{
		cout << "Chocolate Á¦Á¶»ç: " << this->manufacturer << endl;
	}
};

int main()
{
	cout << "* SnackBasket ¾÷Ä³½ºÆÃ/´Ù¿îÄ³½ºÆÃ ½Ç½À *" << endl;

	//¾÷Ä³½ºÆÃ
	Snack* candy1 = new Candy();
	Snack* candy2 = new Candy();

	Snack* chocolate1 = new Chocolate();
	Snack* chocolate2 = new Chocolate();

	cout << endl;

	Snack* snackBasket[SNACK_BASKET_SIZE] = { candy1, candy2, chocolate1, chocolate2 };

	for (int i = 0; i < sizeof(snackBasket) / sizeof(snackBasket[0]); i++)
	{
		//´Ù¿îÄ³½ºÆÃ
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