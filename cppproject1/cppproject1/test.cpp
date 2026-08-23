#include<iostream>
#include<string>
#include<ctime>
using namespace std;



struct hero
{
	string name;
	int age;
	string gender;
};

/*
void bubble_sort(struct hero arr[], int len)
{
	for (int i = 0;i < len - 1;i++) 
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if (arr[j].age>arr[j+1].age)
			{
				struct hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
*/
void bubble_sort(struct hero* arr, int len)
{
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if ((arr+j)->age > (arr + j+1)->age)
			{
				struct hero temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

void print(struct hero arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << "ÐÕÃû£º " << arr[i].name << "ÐÔ±ð£º " << arr[i].gender << "ÄêÁä£º " << arr[i].age << endl;
	}
}

int main()
{
	struct hero hArray[5] =
	{
		{"Áõ±¸",23,"ÄÐ"},
		{"¹ØÓð",22,"ÄÐ"},
		{"ÕÅ·É",20,"ÄÐ"},
		{"ÕÔÔÆ",21,"ÄÐ"},
		{"õõ²õ",19,"Å®"},
	};
	bubble_sort(hArray, 5);
	print(hArray, 5);
	system("pause");
	
	return 0;

}