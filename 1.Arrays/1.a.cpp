#include<iostream>
#include<algorithm>
using namespace std;

int inputArray[]={6,7,1,3,2,8,9};
int arraySize=sizeof(inputArray)/sizeof(inputArray[0]);

// Compare each pair and return the first matching pair

void simpleSearch(int sum)
{
    for(int i=0;i<arraySize;i++)
    {
        for(int j=i+1;j<arraySize;j++)
        {
            if(inputArray[i]+inputArray[j]==sum)
            {
                cout<<"Elements found at index: "<<i<<" and "<<j<<endl;
                return;
            }
        }
    }
    cout<<"Elements with the sum not found"<<endl;
}

// Sort and perform operations

void sortSearch(int sum)
{
    sort(inputArray,inputArray+arraySize);
    int start=0,end=arraySize-1;

    while(start<end)
    {
        if(inputArray[start]+inputArray[end]==sum)
        {
            cout<<"Elements found at index: "<<start<<" and "<<end<<endl;
            return;
        }
        (inputArray[start]+inputArray[end]>sum)?end--:start++;
    }
    cout<<"Elements with the sum not found"<<endl;
}

int main()
{
    int sum;
    cout<<"Enter the sum to find: ";
    cin>>sum;

    // simpleSearch(sum);
    sortSearch(sum);
    for(int i=0;i<arraySize;i++)
        cout<<inputArray[i]<<", ";
    cout<<endl;
    return 0;
}