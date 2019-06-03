#pragma once

ref class Vertex
{
protected:
	static int vertexNum = 0;
	int name;
	int dfn;
	int low;

public:
	Vertex(){}
	Vertex(int name ,int dfn ,int low)
	{
		setVertex(name ,dfn ,low);
	}

	void setVertex(int name ,int dfn ,int low)
	{
		setName(name);
		setDfn(dfn);
		setLow(low);
	}

	static void setVertexNum(int num ) { vertexNum = num; }
	virtual void setName(int name)	   { this->name = name; }
	virtual void setDfn(int dfn)	   { this->dfn = dfn; }
	virtual void setLow(int low)	   { this->low = low; }

	static int getVertexNum() { return vertexNum; }
	int getName()		      { return name; }	
	int getDfn()			  { return dfn;  }
	int getLow()			  { return low;  }
};
