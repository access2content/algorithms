#include<iostream>
using namespace std;

int inputArray[]={ 1, 0, 1, 0, 1, 1, 0, 1, 0, 0 };
int arraySize = sizeof(inputArray)/sizeof(inputArray[0]);

void simpleSort()
{
    int zeroes=0;
    for(int i=0;i<arraySize;i++)
        if(!inputArray[i])
            zeroes++;
    
    for(int i=0;i<arraySize;i++)
    {
        if(i<zeroes)
            inputArray[i]=0;
        else
            inputArray[i]=1;
    }
}

// This code reduces the iteration steps of the loop

void optimizedSort()
{
    int ones=0,extras=0;

    for(int i=0;i<arraySize;i++)
    {
        if(ones>(arraySize-i-1))
        {
            if(inputArray[i])
                extras++;
            else
                inputArray[i]=1;
        }
        else
        {
            if(inputArray[i])
            {
                ones++;
                inputArray[i]=0;
            }
        }
    }

    for(int i=1;i<=extras;i++)
        inputArray[arraySize-ones-i]=1;
}

int main()
{
    optimizedSort();
    for(int i=0;i<arraySize;i++)
        cout<<inputArray[i]<<", ";
    cout<<endl;
    return 0;
}