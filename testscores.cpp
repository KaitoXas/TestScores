#include <iostream>

//pg. 476, 535

using namespace std;

void selectSort(double *[], int);
void getTestScores(double *[], int);
double getAverage(double *[], int);

int main()
{
    int size;
    
    cout << "Welcome!" << endl;
    cout << "How many test scores do you need to enter?" << endl;
    cin >> size;
    
    double inputTestScores[size];
    
    for (int count = 0; count < size; count++)
    {
        cout << "Please enter test score: " << endl;
        cin >> *(inputTestScores + count);
    }
    
    double* arrPtr[size];
    
    for (int count = 0; count < size; count++)
    {
        *(arrPtr + count) = &inputTestScores[count];
    }
    
    cout << "The grades you entered are: " << endl;;
    
    selectSort(arrPtr, size);
    getTestScores(arrPtr, size);
    getAverage(arrPtr, size);
    
    return 0;
}

void selectSort(double *arr[], int size)
{
    int startScan, minIndex;
    double *minValue;
    
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = arr[startScan];
        
        for (int index = startScan + 1; index < size; index++)
        {
            if (*(arr[index]) < *minValue)
            {
                minValue = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minValue;
    }
}

void getTestScores(double *arr[], int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << *(arr[count]) << " " << endl;
    }
}

double getAverage(double *arr[], int size)
{
    double sum = 0;
    double avg;
    
    for (int count = 0; count < size; count++)
    {
        sum += *(arr[count]);
    }
    
    avg = double(sum) / size;
    
    cout << "The average is: " << avg << endl;
    
    return avg;
}
