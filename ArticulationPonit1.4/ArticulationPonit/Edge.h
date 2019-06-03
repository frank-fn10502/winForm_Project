#pragma once

ref class Edge
{
protected:
	array<int,2>^ relation;

public:
	Edge(int num)
	{
		relation = gcnew array<int,2>(num,num);
		for(int i = 0 ; i < num ; i++ )
		{
			for(int j = 0 ; j < num ; j++ )
			{
				relation[i ,j] = 0;
			}
		}
	}

	void setRelation(array<int,2>^% relation) { this->relation = relation; }
	void setRelation(int row,int column,int n){ relation[row ,column] = n; }

	int  getRelation(int row ,int column)	  { return relation[row ,column]; }
	array<int,2>^  getAllRelation()			  { return relation; }
};
