
#ifndef _GLIBCXX_VECTOR
#include<vector>
#endif
#ifndef _LIBLHY_MATRIX_
	#define _LIBLHY_MATRIX_ 1
	template<class type>
	class matrix
	{
		private:
			int X;
			int Y;
			vector< vector< type > > mat;
		public:
			void PrintFormat()
			{
				#ifndef _GLIBCXX_IOSTREAM
					#include<iostream>
				#endif
				for(int i=0;i<X;i++)
				{
					for(int j=0;j<Y;j++)
						j!=Y?std::cout<<mat[i][j]<<" ":std::cout<<mat[i][j];
					std::cout<<std::endl;
				}
			}
			void PutArray(type **Array,int Row,int Column)
			{
				for(int i=0;i<Row;i++)
					for(int j=0;j<Column;j++)
					{
						mat[i][j]=*((int*)Array + Column*i + j);
//						mat[i][j]=arr[i][j];
					}
				
			}
			int size(void)
			{
				return this->X *this->Y;
			}
			void PutElement(type Data,int Row,int Column)
			{
				mat[Row][Column]=Data;
			}
			type GetElement(int Row,int Column)
			{
				return mat[Row][Column];
			}
			type GetRowLength(void)
			{return X;}
			type GetColumnLength(void)
			{return Y;}
			matrix(int Row,int Column)
			{
				mat.resize(Row); 
				for(int i=0;i<row;i++)
         			mat[i].resize(Column);
         		X=Row;
         		Y=Column;
				
			}
//			type** getNomal
	};
#endif
matrix<int> operator+ (matrix<int> A,matrix<int> B)
{
	matrix<int> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
	{
		for(int i=0;i<A.GetColumnLength() ;i++)
			for(int j=0;j<A.GetColumnLength() ;j++)
				{
					C.PutElement(A.GetElement(i,j)+B.GetElement(i,j),i,j); 
				}
		return C;
	}
	else
	{
		std::cout<<std::endl<<"Error : The matrix being manipulated is not a matrix of the same type."<<std::endl<<std::endl;
		throw 0x3f;
	}
}

