#pragma once
#include "vertexentity.h"

ref class GraphVertexEntity : public VertexEntity
{
private:
	static bool someFocus = false;
	static bool updating = false;
	Label^ vertexLabel;

public:
	GraphVertexEntity(int name ,int dfn ,int low,int num);


	static bool	isUpDating(){ return updating; }
	static bool	isSomeFocus(){ return someFocus; }
	static void	reSeteSomeFocus(){ someFocus = false; }

	virtual Label^ getEntity() override{ return vertexLabel; }
	virtual Point getCenterPoint() override;

	virtual void setName(int name) override
	{ 
		this->name = name; 
		vertexLabel->Text = name.ToString(); 
	}
	virtual void setOriginalPos(int ,int ) override;
	virtual void setPos(int ,int ) override;

	virtual void beginningStatus() override;

private:
	System::Void label_MouseEnter(Object^  sender ,EventArgs^  e);
	System::Void label_MouseLeave(Object^  sender ,EventArgs^  e);
	System::Void label_MouseDown(Object^  sender ,MouseEventArgs^  e);
	System::Void label_MouseUp(Object^  sender, MouseEventArgs^  e)  ;
	System::Void label_MouseMove(Object^  sender ,MouseEventArgs^  e);
	void setVertexLabel(int name ,int);
};
