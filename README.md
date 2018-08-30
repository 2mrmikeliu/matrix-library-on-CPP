# matrix-library-on-CPP version 0.1

# 手册
1. 类
	1. matrix类
		成员
		
		函数void PrintFormat()	以矩阵的标准形式输出
		
		函数void PutArray(type **Array,int Row,int Column)	将Row行Column列的数组Array转化为矩阵，并且存放在矩阵中
		
		函数int size()	求得矩阵的大小
		
		函数void PutElement(type Data,int Row,int Column)	将Row行Column列的数变为Data
		
		函数type GetElement(int Row,int Column)	得到Row行Column列的数据
		
		函数type GetRowLength()	得到矩阵的行数
		
		函数type GetColumnLength(void)	得到矩阵的列数
		
		析构函数matrix(int row,int column)	定义矩阵大小是Row行Column列
	2.函数matrix<int> operator+ (matrix<int> A,matrix<int> B)	将矩阵A和矩阵B相加（如不是同型矩阵，会抛出异常0x3f）