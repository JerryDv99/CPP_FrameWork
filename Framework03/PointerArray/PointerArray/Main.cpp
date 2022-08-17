#include <iostream>

using namespace std;



/*
template <typename T>
class Node
{
public:
	T Value;
};

*/

template <typename T>
class List
{
/*private:
	Node<T> Value;
public:
	void Setter(const T _Value) { Value.Value = _Value; }
	T Getter()	const { return Value.Value; }*/
private:
	T Value;
public:
	void Setter(const T _Value) { Value = _Value; }
	T Getter()	const { return Value; }
};

/*
class TempClass
{
public:
	template <typename T>
	T TemplateClass(T _typeValue)
	{
		return _typeValue;
	}
};
*/

// 데이터 타입을 전달할 수 있게 해준다.
template <typename T>

class vector
{
private:
	T* Value;
	int m_size;	
	int m_capacity;
public:
	void push_back(T _value)
	{
		if (m_size == m_capacity)
		{
			if (m_capacity < 3)
				m_capacity += 1;
			else
				m_capacity += (m_capacity * 0.5f);

			int* Temp = new T[sizeof(T) * m_size];

			for (int i = 0; i < m_size; ++i)
				Temp[i] = Value[i];

			delete Value;

			Value = new T[sizeof(T) * m_capacity];

			for (int i = 0; i < m_size; ++i)
				Value[i] = Temp[i];
		}
		Value[m_size] = _value;
		m_size += 1;
	}
	int size() const { return m_size; }
	int capacity() const { return m_capacity; }

	void Output(int _where)
	{
		if (_where < m_size)
			cout << Value[_where] << endl;
	}
	void front()
	{
		if(m_size != 0)
			cout << "첫 번째 원소 : " << Value[0] << endl;
	}
	void back()
	{
		if (m_size != 0)
			cout << "마지막 원소 : " << Value[m_size - 1] << endl;
	}
	void erase(int _where)
	{
		if (m_size >= _where)
		{
			int* Temp = new T[sizeof(T) * m_size];
			for (int i = _where - 1; i < m_size; ++i)
			{
				Temp[i] = Value[i + 1];
			}
			for (int i = _where - 1; i < m_size; ++i)
				Value[i] = Temp[i];
			Value[m_size - 1] = 0;
		}
	}
	void clear()
	{
		delete Value;
		m_size = 0;
		m_capacity = 0;
	}
	void insert(int _where, int _value)
	{
		if (m_size >= _where)
		{
			int* Temp = new T[sizeof(T) * m_size + 1];
			for (int i = _where - 1; i < m_size; ++i)
				Temp[i + 1] = Value[i];
			Value[_where - 1] = _value;
			if (m_size + 1 >= m_capacity)
			{
				m_capacity += (m_capacity * 0.5f);

				int* Temp1 = new T[sizeof(T) * m_size];

				for (int i = 0; i < m_size; ++i)
					Temp1[i] = Value[i];

				delete Value;

				Value = new T[sizeof(T) * m_capacity];

				for (int i = 0; i < m_size; ++i)
					Value[i] = Temp1[i];
			}
			for (int i = _where; i < m_size + 1; ++i)
				Value[i] = Temp[i];
			m_size += 1;
		}
	}
public:
	vector() 
	{ 
		Value = new T[sizeof(T)]; 
		m_size = 0;
		m_capacity = 0;
	}
};

template <typename T>
class Vector
{
private:
	T* Value;
	int m_size;
	int m_capacity;
public:
	void push_back(T _value)
	{
		if (m_size == m_capacity)
		{
			if (m_capacity < 3)
				m_capacity += 1;
			else
				m_capacity += (m_capacity * 0.5f);

			int* Temp = new T[sizeof(T) * m_size];

			for (int i = 0; i < m_size; ++i)
				Temp[i] = Value[i];

			delete Value;

			Value = new T[sizeof(T) * m_capacity];

			for (int i = 0; i < m_size; ++i)
				Value[i] = Temp[i];			
		}
		Value[m_size] = _value;
			m_size += 1;
	}
	
	int size() const { return m_size; }
	int capacity() const { return m_capacity; }

	void Output(int _where)
	{
		if (_where < m_size)
			cout << Value[_where] << endl;
	}
public:
	Vector() 
	{
		m_size = 0;
		m_capacity = 0;
		Value = new T[m_capacity];
	}
};

int main(void)
{
	/*Vector<int> vecNumbers;

	for (int i = 0; i < 10; ++i)
	{
		vecNumbers.push_back(10 * i + 10);
		cout << "size : " << vecNumbers.size() << endl;
		cout << "capacity : " << vecNumbers.capacity() << endl;
		vecNumbers.Output(i);
	}*/

	vector<int> Numbers;
	for (int i = 0; i < 13; ++i)
	{
		Numbers.push_back(10 * i + 10);
		cout << "size : " << Numbers.size() << endl;
		cout << "capacity : " << Numbers.capacity() << endl;
		Numbers.Output(i);
		cout << endl;
	}

	Numbers.front();// 첫번째 원소 가리키는 함수
	cout << endl;
	Numbers.back();	// 마지막
	cout << endl;

	Numbers.erase(5); //선택 삭제
	//Numbers.clear(); //전체 삭제

	Numbers.insert(3, 25);
	Numbers.insert(10, 95);

	for (int i = 0; i < Numbers.size() - 1; ++i)
	{		
		Numbers.Output(i);
		cout << endl;
	}
	cout << "size : " << Numbers.size() << endl;
	cout << "capacity : " << Numbers.capacity() << endl;

	
	






	/************************************************************
	// template은 class에 사용할 경우 class 이름 뒤에 붙여서 사용
	// class_name<DataType>
	Vector<int> Temp;
	Temp.Setter(10);
	cout << Temp.Getter() << endl;

	/*List<int> liTemp;
	liTemp.Setter(10);
	cout << liTemp.Getter() << endl;*/


	/*
	TempClass TC;
	// template은 함수에 사용할 경우 함수 이름 뒤에 붙여서 사용
	// Fuction_name<DataType>
	cout << TC.TemplateClass<int>(10) << endl;
	*****************************************************/

	return 0;
}