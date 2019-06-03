#pragma once
#include "Vertexentity.h"

ref class DFSTreeVertexEntity : public VertexEntity
{
private:
	static bool someFocus = false;
	static bool updating = false;

	Label^ vertexLabel;
	Panel^ detail;
	Label^ vertexDfn;
	Label^ vertexLow;
	Label^ slash;
	bool showDetail;

public:
	DFSTreeVertexEntity(int name ,int dfn ,int low,int num);

	static bool	isUpDating()   { return updating; }
	static bool	isSomeFocus()  { return someFocus; }
	static void	reSeteSomeFocus(){ someFocus = false; }

	virtual Label^ getEntity() override{ return vertexLabel; }
	Panel^ getDatailEntity(){ return detail; }
	virtual Point getCenterPoint() override;

	virtual void setName(int name) override
	{ 
		this->name = name; 
		vertexLabel->Text = name.ToString(); 
	}
	virtual void setDfn(int dfn) override
	{ 
		this->dfn = dfn; 
		vertexDfn->Text = dfn.ToString(); 
	}
	virtual void setLow(int low) override  
	{ 
		this->low = low; 
		vertexLow->Text = low.ToString();
	}
	virtual void setOriginalPos(int ,int ) override;
	virtual void setPos(int ,int ) override;

	virtual void beginningStatus() override;

	void detailVisible(bool vis){ detail->Visible = vis; }

private:
	System::Void label_MouseEnter(Object^  sender ,EventArgs^  e);
	System::Void label_MouseLeave(Object^  sender ,EventArgs^  e);
	System::Void label_MouseDown(Object^  sender ,MouseEventArgs^  e);
	System::Void label_MouseUp(Object^  sender, MouseEventArgs^  e)  ;
	System::Void label_MouseMove(Object^  sender ,MouseEventArgs^  e);
	void setVertexLabel(int name ,int);
	void setDetail(int);
	void setVertexDfn(int);
	void setVertexLow(int);
	void setSlash(int);
};
