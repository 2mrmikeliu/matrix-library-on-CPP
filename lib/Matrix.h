/*****************************************************************************
*                                                                            *
*  @file     Matrix.h                                                        *
*  @brief    ������ĳ�ªʵ��                                                *
*  Details.                                                                  *
*                                                                            *
*  @author   Mike Liu                                                        *
*  @email    mike_server@foxmail.com                                         *
*  @version  1.0.0.0(�汾��)                                                 *
*  @date     2018.8.31                                                       *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : None                                              *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2018/08/31 | 1.0.0.0   | Mike Liu       | Doxygen test ver                *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/
#ifndef _GLIBCXX_VECTOR
#include<vector>
#endif
#ifndef _LIBLHY_MATRIX_
#define _LIBLHY_MATRIX_ 1
template<class type>
/**
* @brief matrix
* ������ļ�ʵ�� 
*/
class matrix
{
	private:
		int X;
		int Y;
		vector< vector< type > > mat;
	public:
	 /** 
    * @brief �������ʽ��� 
    */
		void PrintFormat()
		{
		#ifndef _GLIBCXX_IOSTREAM
			#include<iostream>
		#endif
			for(int i=0; i<X; i++)
				{
					for(int j=0; j<Y; j++)
						j!=Y?std::cout<<mat[i][j]<<" ":std::cout<<mat[i][j];
					std::cout<<std::endl;
				}
		}
	/** 
    * @brief ����ά����ת��Ϊ����
    * @param Array һ����ά�����ָ��
	* @param Row ��ά���������
	* @param Column ��ά��������� 
	* 
    */
		void PutArray(type **Array,int Row,int Column)
		{
			for(int i=0; i<Row; i++)
				for(int j=0; j<Column; j++)
					{
						mat[i][j]=*((int*)Array + Column*i + j);
					}

		}
	    /** 
    * @brief ȡ�����С 
    *
    * @return ����˵��
    *        ���ؾ����СRow*Column 
    */
		int size(void)
		{
			return this->X *this->Y;
		}
	    /** 
    * @brief �������е�һ��Ԫ���滻 
    * @param Data ���������ı��� 
    * @param Row ���������
	* @param Column ��������� 
    */
		void PutElement(type Data,int Row,int Column)
		{
			mat[Row][Column]=Data;
		}
	    /** 
    * @brief �õ������ĳ��Ԫ�� 
    * @param Row �������� 
    * @param Column �������� 
    *
    * @return ����˵��
    *        ����ʱ�׳��쳣0x40 
    *        ����mat��Row��Column��Ԫ�� 
    */
		type GetElement(int Row,int Column)
		{
			if((Row>=X||Column>=Y)||(Row<0||Column<0)) 
				threw 0x40;
			return mat[Row][Column];
		}
	    /** 
    * @brief �õ���������� 
    *
    * @return ����˵��
    *        ���ؾ�������� 
    */
		type GetRowLength(void)
		{
			return X;
		}
	    /** 
    * @brief �õ���������� 
    *
    * @return ����˵��
    *        ���ؾ�������� 
    */
		type GetColumnLength(void)
		{
			return Y;
		}
		    /** 
    * @brief �������� 
    *
    * @param Row ��ʼ����������
	* @param Column ��ʼ���������� 
    */
		matrix(int Row,int Column)
		{
			mat.resize(Row);
			for(int i=0; i<row; i++)
				mat[i].resize(Column);
			X=Row;
			Y=Column;

		}
//			type** getNomal
};
matrix<int> operator+ (matrix<int> A,matrix<int> B)
{
	matrix<int> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
		{
			for(int i=0; i<A.GetColumnLength() ; i++)
				for(int j=0; j<A.GetColumnLength() ; j++)
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
matrix<long> operator+ (matrix<long> A,matrix<long> B)
{
	matrix<long> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
		{
			for(int i=0; i<A.GetColumnLength() ; i++)
				for(int j=0; j<A.GetColumnLength() ; j++)
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
matrix<long long> operator+ (matrix<long> A,matrix<long> B)
{
	matrix<int> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
		{
			for(int i=0; i<A.GetColumnLength() ; i++)
				for(int j=0; j<A.GetColumnLength() ; j++)
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
matrix<unsigned int> operator+ (matrix<unsigned int> A,matrix<unsigned int> B)
{
	matrix<unsigned int> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
		{
			for(int i=0; i<A.GetColumnLength() ; i++)
				for(int j=0; j<A.GetColumnLength() ; j++)
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
matrix<unsigned long long> operator+ (matrix<unsigned long long> A,matrix<unsigned long long> B)
{
	matrix<unsigned long long> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
		{
			for(int i=0; i<A.GetColumnLength() ; i++)
				for(int j=0; j<A.GetColumnLength() ; j++)
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

matrix<float> operator+ (matrix<float> A,matrix<float> B)
{
	matrix<float> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
		{
			for(int i=0; i<A.GetColumnLength() ; i++)
				for(int j=0; j<A.GetColumnLength() ; j++)
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

matrix<double> operator+ (matrix<int> A,matrix<int> B)
{
	matrix<int> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
		{
			for(int i=0; i<A.GetColumnLength() ; i++)
				for(int j=0; j<A.GetColumnLength() ; j++)
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
#endif
