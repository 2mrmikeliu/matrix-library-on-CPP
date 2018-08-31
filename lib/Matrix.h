/*****************************************************************************
*                                                                            *
*  @file     Matrix.h                                                        *
*  @brief    矩阵类的丑陋实现                                                *
*  Details.                                                                  *
*                                                                            *
*  @author   Mike Liu                                                        *
*  @email    mike_server@foxmail.com                                         *
*  @version  1.0LTS                                                          *
*  @date     2018.8.31                                                       *
*  @license  GNU General Public License (GPL)                                *
*  It really works!                                                          *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : None                                                     *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2018/08/31 | 1.0LTS    | Mike Liu       | Long Term Support Version 1     *
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
* 矩阵类的简单实现 
*/
class matrix
{
	private:
		int X;
		int Y;
		vector< vector< type > > mat;
	public:
	 /** 
    * @brief 按矩阵格式输出 
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
    * @brief 将二维数组转化为矩阵
    * @param Array 一个二维数组的指针
	* @param Row 二维数组的行数
	* @param Column 二维数组的列数 
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
    * @brief 取矩阵大小 
    *
    * @return 返回说明
    *        返回矩阵大小Row*Column 
    */
		int size(void)
		{
			return this->X *this->Y;
		}
	    /** 
    * @brief 将矩阵中的一个元素替换 
    * @param Data 欲放入矩阵的变量 
    * @param Row 放入的行数
	* @param Column 放入的列数 
    */
		void PutElement(type Data,int Row,int Column)
		{
			mat[Row][Column]=Data;
		}
	    /** 
    * @brief 得到矩阵的某个元素 
    * @param Row 矩阵行数 
    * @param Column 矩阵列数 
    *
    * @return 返回说明
    *        错误时抛出异常0x40 
    *        返回mat的Row行Column列元素 
    */
		type GetElement(int Row,int Column)
		{
			if((Row>=X||Column>=Y)||(Row<0||Column<0)) 
				threw 0x40;
			return mat[Row][Column];
		}
	    /** 
    * @brief 得到矩阵的行数 
    *
    * @return 返回说明
    *        返回矩阵的行数 
    */
		type GetRowLength(void)
		{
			return X;
		}
	    /** 
    * @brief 得到矩阵的列数 
    *
    * @return 返回说明
    *        返回矩阵的列数 
    */
		type GetColumnLength(void)
		{
			return Y;
		}
		    /** 
    * @brief 析构函数 
    *
    * @param Row 初始化矩阵行数
	* @param Column 初始化矩阵列数 
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
	    /** 
    * @brief 矩阵加法 
    *
    * @param A,B 两个被操作的矩阵 
    * @return 返回说明
    *         错误时抛出异常0x41
    *         返回它们的和 
    */
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
    * @brief 矩阵减法 
    *
    * @param A,B 两个被操作的矩阵 
    * @return 返回说明
    *         错误时抛出异常0x42 
    *         返回它们的差 
    */
matrix<type> operator- (matrix<type> A,matrix<tpye> B)
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

#endif
