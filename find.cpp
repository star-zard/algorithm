#include <iostream>
using namespace std;

struct Result
{
	int r_left;
	int r_right;
	int r_sum;
};

struct Result1
{
	int r_left1;
	int r_right1;
	int r_sum1;
};

Result find_max_crossing_subarray(int A[],int low,int mid,int high)
{
	int left_sum=-9999;
	int sum=0;
	int i,j;
	int max_left,max_right;
	for(i=mid;i>=low;i--)
	{
		sum=sum+A[i];
		if(sum>left_sum)
		{
			left_sum=sum;
			max_left=i;
		}
	}
	int right_sum=-9999;
	sum=0;
	for(j=mid+1;j<=high;j++)
	{
		sum=sum+A[j];
		if(sum>right_sum)
		{
			right_sum=sum;
			max_right=j;
		}
	}
	Result ret;
	ret.r_left=max_left;
	ret.r_right=max_right;
	ret.r_sum=left_sum+right_sum;
	return ret;
}

Result find_maximum_subarray(int A[],int low,int high)
{	
	Result ret,ret1,ret2,ret3;
	int left_low,left_high;
	int right_low,right_high;
	int cross_low,cross_high;
	int left_sum,right_sum,cross_sum;
	int mid;
	if(high==low)
	{
		ret3.r_left=low;
		ret3.r_right=high;
		ret3.r_sum=A[low];
		return ret3;
	}
		
	else
	{
		mid=(low+high)/2;
		
		ret1=find_maximum_subarray(A,low,mid);
		left_low=ret1.r_left;left_high=ret1.r_right;left_sum=ret1.r_sum;
		ret2=find_maximum_subarray(A,mid+1,high);
		right_low=ret2.r_left;right_low=ret2.r_right;right_sum=ret2.r_sum;
		ret=find_max_crossing_subarray(A,low,mid,high);
		cross_low=ret.r_left;cross_high=ret.r_right;cross_sum=ret.r_sum;
		
	}
	if(left_sum>=right_sum&&left_sum>=cross_sum)
		return ret1; 
	else if(right_sum>=left_sum&&right_sum>=cross_sum)
		return ret2;
	else 
		return ret ;



}
int main()
{
	int a[]={1,2,5,6,-7,6,3,4};
	int result_low,result_high;
	int result_sum;
	Result result;
	result=find_maximum_subarray(a,0,7);
	cout<<result.r_left<<","<<result.r_right<<","<<result.r_sum;
}