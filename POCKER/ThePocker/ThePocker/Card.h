#pragma once

ref class Card
{
private:
	int suit;
	int rank;
public:
	Card(void);

	void setCard(int ,int);
	void setSuit(int);
	void setRank(int);

	int getSuit();
	int getRank();
};
