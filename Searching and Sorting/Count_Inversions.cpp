
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

long long int inv = 0;

void merge(long long arr[], long long start, long long mid, long long end)
{
    long long i,j,k;
    long long temp[end-start+1];
    i = start;
    j = mid+1;
    k = 0;
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            inv = inv + (mid-i+1);
            j++;
            k++;
        }
    }
    if(i<=mid)
    {   
        while(i<=mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    else if(j<=end)
    {
        while(j<=end)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    k = 0;
    for(i=start; i<=end; i++)
    {
        arr[i] = temp[i-start];
    }
}

void sort(long long arr[],long long start, long long end)
{
    if(start<end)
    {
        long long mid = (start+end)/2;
        sort(arr,start,mid);
        sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    inv = 0;
        sort(arr,0,N-1);
    return inv;
}
