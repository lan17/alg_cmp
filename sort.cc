#include<iostream>

using namespace std;

template<class T>
inline void swap( T * arr, int a, int b )
{
	T tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

template< class T>
int partition( T * arr, int a, int b, int p )
{
	int ret = a;
	swap(arr,b,p);
	for( int i = a; i < b; ++i )
	{
		if( arr[i] < arr[ret] )
		{
			swap(arr, i, ret );
			++ret;
		}
	}
	swap( arr, ret, b );
	return ret;
}

template <class T>
void qsort( T * arr, int a, int b )
{
	if( a >= b ) return;
	int p = partition(arr, a, b, (a + b) / 2 );
	qsort( arr, a, p);
	qsort( arr, p+1, b );
}

template <class T>
void qsort( T * arr, int size)
{
	qsort( arr, 0, size-1);
}

int main(int argc, char ** argv )
{
	int size = 7;
	int  arr[] = {5,10,6,2,6,1, 7};
	qsort<int>(arr,size);
	for( int i = 0; i < size; ++i )
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}
