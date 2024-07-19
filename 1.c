#include<stdio.h>


//冒泡排序
void maopao(int * a,int num)
{
	printf("进行冒泡排序%d个数据\n",num);
	int i = 0,j = 0,temp = a[0];
	
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	/*
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
		
	}
	printf("\n");
	*/
}



//选择排序
void select(int * a,int num)
{
	printf("进行选择排序%d个数据\n",num);
	//选择最大的放在最后面
	int max = 0;//max表示最大值的下标
	int i,j,temp = 0;
	for(j=0;j<num-1;j++)
	{
		for(i=0;i<num-j;i++)
		{
			if(a[i]>a[max])
			{
				max = i;
			}
		}
		temp = a[max];
		a[max] = a[num-1];
		a[num-1] = temp;
		j++;

	}

	/*
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
		
	}
	printf("\n");
	*/


}


//插入排序
void Insert(int * a,int num)
{
	printf("进行插入排序%d个数据\n",num);
	int i,j;
	for(i=1;i<num-1;i++);
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>a[i])
			{
				a[j+1] = a[j];
			}
			else
			{
				a[j+1] = a[i];
				break;
			}
		}
		if(j==-1)
		{
			a[j+1] = a[i];
		}

	}

	/*
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
		
	}
	printf("\n");
	*/
}


//快速排序
void fast(int * a,int left,int right)
{
	
	int start,end,p;
	start = left; 
	end = right;
	p = a[left];
	if(left < right)
	{
		while(a[right]>p)
		{
			right--;
		}
		a[left] = a[right];
		while(a[left]<p)
		{
			left++;
		}
		a[right] = a[left];
	}
	else
	{
		return ;
	}
	a[left] = p;
	//递归左边从start到left-1
	fast(a,start,left-1);

	//递归右边从left+1到end
	fast(a,left+1,end);
	
}



int main()
{
	//先给出一个大小为10的数组
	int a[100] = {0};
	//读取键盘区的数据为数组赋值
	int i=0,num=0;
	printf("请在键盘区输入100个以内的数据，以空格隔开，以0结尾\n");
	
	while(1)
	{
		scanf("%d",&a[i++]);
		if(a[i-1]==0 | i==100)
		{
			break;
		}
		num++;
	}
	printf("数据输入完毕\n");
	
	maopao(a,num);
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
		
	}
	printf("\n");

	select(a,num);
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
		
	}
	printf("\n");

	Insert(a,num);
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
		
	}
	printf("\n");

	printf("进行快速排序%d个数据\n",num);
	fast(a,0,num-1);
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
		
	}
	printf("\n");

	
}





