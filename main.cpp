#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <double> readFile(string name)
{
    vector <double> num;
    double fileNum;
    char comma;
    ifstream f;

    f.open(name);

    if (f.is_open())
    {
        while(f >> fileNum)
    {
        num.push_back(fileNum);
        f >> comma;
    }
    }
    
    else
    {
        cout << "Sorry, the file could not be opened." << endl;
    }

    f.close();

    return num;
}

double median(vector<double> num)
{
    double median;
    size_t size = num.size();

    if (size % 2 != 0) 
    {
        median = num[size/2];
    }

    else
    {
        median = (num[size/2-1]+num[size/2]) / 2.0;
    }

    return median;

}

double mean(vector<double> num)
{
    double mean, total;
    size_t size = num.size();

    for (size_t i = 0; i < size; i++)
    {
        total += num[i];
    }

    mean = total/size;

    return mean;

}

double mode(vector<double> num)
{
    double mode;
    int count = 0;
    int max = 0;
    size_t size = num.size();

    for (size_t i = 0; i < size; i++)
    {
        if(num[i] == num[i - 1])
        {
            ++count;
        }

        else
        {
            if(count > max)
            {
                max = count;
                mode = num[i -1];
            }

            count = 1;
        }
    }
    
    return mode;
}

int main()
{
    vector<double> num;
    string name;
    bool swapped;

    cout << "Enter the filename: ";
    getline(cin, name);
    
    num = readFile(name);
    
    for (size_t i = 0; i < num.size() -1; i++) {
        swapped = false;
        for (size_t j = 0; j < num.size() - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                swapped = true;
            }
        }
 
        if (swapped == false)
            break;
    }

    cout << "\nThe median of the data set is: "<<median(num)<<"."<< endl;
    cout << "The mean of the data set is: " << mean(num) << "." << endl;
    cout << "The mode of the data set is: " << mode(num) << "." << endl;

    //tests
    cout << "\n\nTests" << endl;

    //data1.txt
    cout << "\nWhile using data1.txt" << endl;
    cout << "Expected ans    = calculated ans" << endl;
    cout << "Median:   10    = " << median(num) << endl;
    cout << "Mean:     31.25 = " << mean(num) << endl;
    cout << "Mode:      1    = " << mode(num) << endl;

    //data2.txt
    cout << "\nWhile using data2.txt" << endl;
    cout << "Expected ans    = calculated ans" << endl;
    cout << "Median:   55    = " << median(num) << endl;
    cout << "Mean:     56.75 = " << mean(num) << endl;
    cout << "Mode:     55    = " << mode(num) << endl;

    //data3.txt
    cout << "\nWhile using data3.txt" << endl;
    cout << "Expected ans      = calculated ans" << endl;
    cout << "Median:   45      = " << median(num) << endl;
    cout << "Mean:     36.9333 = " << mean(num) << endl;
    cout << "Mode:     45      = " << mode(num) << endl;
    
}

