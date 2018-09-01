/*****************************************************************************
*                                                                            *
*  @file     Matrix.h                                                        *
*  @brief    ������ĳ�ªʵ��                                                *
*  Details.                                                                  *
*                                                                            *
*  @author   Mike Liu                                                        *
*  @email    mike_server@foxmail.com                                         *
*  @version  1.0                                                             *
*  @date     2018.8.31                                                       *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : None                                                     *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2018/08/31 | 1.0       | Mike Liu       | ��ɾ����������������ת�ã�    *
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
* @brief ������ģ��ֵ
*/ 
unsigned long long ModValue;
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
		throw 0x40;
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
	for(int i=0; i<Row; i++)
		mat[i].resize(Column);
	X=Row;
	Y=Column;

}
};
template<class type>
type operator^(type A, type B)
{
	int Ans = 1, Base = A;
	while(B > 0)
		{
			if(B & 1)
				Ans *= Base;
			Base *= Base;
			B >>= 1;
		}
	return Ans;
};
/**
* @brief ����ӷ�
*
* @param A,B �����������ľ���
* @return ����˵��
*         ����ʱ�׳��쳣0x41
*         �������ǵĺ�
*/
template<class type>
matrix<type> operator+ (matrix<type> A,matrix<type> B)
{
	matrix<type> C(A.GetRowLength(),A.GetColumnLength());
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
			throw 0x41;
		}
}
/**
* @brief �������
*
* @param A,B �����������ľ���
* @return ����˵��
*         ����ʱ�׳��쳣0x42
*         �������ǵĲ�
*/
template<class type>
matrix<type> operator- (matrix<type> A,matrix<type> B)
{
	matrix<type> C(A.GetRowLength(),A.GetColumnLength());
	if(A.GetColumnLength()==B.GetColumnLength()&&A.GetRowLength()==B.GetRowLength())
		{
			for(int i=0; i<A.GetColumnLength() ; i++)
				for(int j=0; j<A.GetColumnLength() ; j++)
					{
						C.PutElement(A.GetElement(i,j)-B.GetElement(i,j),i,j);
					}
			return C;
		}
	else
		{
			std::cout<<std::endl<<"Error : The matrix being manipulated is not a matrix of the same type."<<std::endl<<std::endl;
			throw 0x42;
		}
}
/**
* @brief ����˷� 
*
* @param A,B �����������ľ���
* @return ����˵��
*         ����ʱ�׳��쳣0x43
*         �������ǵĻ� 
*/
template<class type>
matrix<type> operator* (matrix<type> A,matrix<type> B)
{
	matrix<type> C(A.GetRowLength(),B.GetColumnLength()); 
	for(int m=0;m<A.GetRowLength();m++){  
    	for(int s=0;s<B.GetColumnLength();s++){  
            C.PutElement(0,m,s);
            for(int n=0;n<B.GetColumnLength();n++){  
                C.PutElement(C.GetElement(m,s)+A.GetElement(m,n)*B.GetElement(n,s),m,s);  
            }  
        }  
    }  
    return C;
}
/**
* @brief ��������� 
*
* @param A �������ľ���
* @param B ָ�� 
* @return ����˵��
*         �������ǵĻ� 
*/
template<class type,class p>
matrix<type> operator^ (matrix<type> A,p B)
{
	matrix<type> C(A.GetRowLength(),A.GetColumnLength()); 
	for(int i=0;i<B;i++)
	{
	for(int m=0;m<A.GetRowLength();m++){  
    	for(int s=0;s<A.GetColumnLength();s++){  
            C.PutElement(0,m,s);
            for(int n=0;n<A.GetColumnLength();n++){  
                C.PutElement(C.GetElement(m,s)%A.ModValue+A.GetElement(m,n)%A.ModValue*A.GetElement(n,s)%A.ModValue,m,s);  
            }  
        }  
	}
	A=C;
	}
    return C;
}

#endif
