#include <iostream>
#include <strings.h>
using namespace std;
class hashtable
{
	int size = 7;
	int arr[7];
	int count = 0;

public:
	void initialArray()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = -9999;
		}
	}
	int hashFunction(int k)
	{
		return k % size;
	}
	void add(int v)
	{
		int x = hashFunction(v);
		if (arr[x] == -9999)
		{
			arr[x] = v;
			count++;
		}
		else
		{
			// Linear Probing due to collision
			for (int i = 0; i < size; i++)
			{
				if (arr[x] != -9999)
				{
					while (arr[x] == -9999)
					{
						x++;
					}
					arr[x] = v;
				}
			}
			count++;
		}
	}
	void Search(int k)
	{
		int x = hashFunction(k);
		if (arr[x] != -9999)
		{
			// Value Found
			cout << "The value is : " << arr[x] << endl;
		}
		else
		{
			// Value Not Found Exception
			cout << "No value Found" << endl;
		}
	}
	void print()
	{
		cout << "Key"<< "  Value "<<endl;
		for (int i = 0; i < size; i++)
		{
			cout << i << "  :  " << arr[i] << "\n";
		}
	}
	void deleteElement(int k)
	{
		int x = hashFunction(k);
		if (arr[x] == -9999)
		{
			cout << "The space is Already Empty . Nothing found ." << endl;
		}
		else
		{
			int y = arr[x];
			arr[x] = -9999;
			cout << "The element \"" << y << "\" is successfully deleted." << endl;
			count--;
		}
	}
};
int main()
{
	hashtable ht;
	ht.initialArray();
	// Adding key value Pair
	ht.add(0);
	ht.add(4);
	ht.add(6);
	ht.add(12);
	ht.add(22);
	ht.add(16);
	ht.print();
	return 0;
}