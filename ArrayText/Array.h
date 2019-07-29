
// Array.h

#ifndef ARRAY_H
#define ARRAY_H
#include<cassert>

//数组模板定义
template<class T>
class Array{
	private:
		T *list;  // T类型指针,用于存放动态分配的数组的首地址
		int size; // 数组的大小
	public:
		Array(int sz=50);            //构造函数
		Array(const Array<T> &a);    //拷贝构造函数
		~Array();                    //析构函数
		Array<T> & operator=(const Array<T> &rhs); //重载"="
		T & operator[](int i)const;  // 重载"[]",使Array对象起到c++普通数组的作用
		const T & operator[](int i)const;  // 针对const的重载
		operator T*();  //重载T*类型的转化
		operator const T*()const;  //重载T*类型的转化
		int getSize() const; //取数组的大小
		void resize(int sz); //修改数组大小
}
//构造函数
template<class T>
Array<T>::Array(int sz=50){
	assert(sz>=0);
	size = sz;
	list = new T[size];
}
//析构函数
template<class T>
Array<T>::~Array()
{
	delete[] list;
}
