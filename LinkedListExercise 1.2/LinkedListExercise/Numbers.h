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

	void insertLink(int ,int);//位置 ,內容
	void deleteLink(int);//位置
	void editLinkByPos(int ,int);//位置 ,內容
	bool editLinkByContent(int ,int);//內容 ,更改的內容
	int  queryLinkByPos(int);//位置
	array<int>^  queryLinkByContent(int);//內容

	array<int>^ forwardList();
	array<int>^ backwardList();
};
