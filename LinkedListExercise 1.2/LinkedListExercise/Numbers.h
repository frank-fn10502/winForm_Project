#pragma once

class Numbers
{
private:
	class Number
	{
	private:
		friend class Numbers;

		Number* preNum;
		Number* nextNum;
		int		num;

	public:
		Number(void);
	};

	Number* head;
	int	 count;
	bool forward;

public:
	Numbers(void);
	~Numbers(void);

	void setForward(bool forward){ this->forward = forward; }

	int  getCount()	 { return count;   }
	bool getForward(){ return forward; }

	void insertLink(int ,int);//��m ,���e
	void deleteLink(int);//��m
	void editLinkByPos(int ,int);//��m ,���e
	bool editLinkByContent(int ,int);//���e ,��諸���e
	int  queryLinkByPos(int);//��m
	array<int>^  queryLinkByContent(int);//���e

	array<int>^ forwardList();
	array<int>^ backwardList();
};
