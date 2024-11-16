#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;
double calMedian(vector<int>& numbers);

int main() {

    ifstream theFile;
    string fileName;
    string line;

    do {
        cout << "\nPlease, enter the file name: ";
        getline(cin, fileName);
        theFile.open(fileName);

        if (!theFile.is_open()) {
            cout << "\nThere's no file with that name. Try again" << endl;
        }
    } while (!theFile.is_open());

    vector<int> numbers; // Vector to store the integers


    if (getline(theFile, line)) {
        istringstream sstream(line); //allows me to extract data from a string as if it were a stream of data.
        string value;

        while (getline(sstream, value, ',')) {

           numbers.push_back(stoi(value)); // Convert to int and store
        }
    }


    // Calculate and display the median
    double median = calMedian(numbers);
    cout << "The median is: " << median << endl;

    theFile.close(); // Close the file
    return 0;
}
// Function to calculate the median
double calMedian(vector<int>& numbers) {
    int size = numbers.size();
    if (size == 0)
    {
        return 0;
    }
    else if (size % 2 == 0) {
       
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    }
    else {
       
        return numbers[size / 2];
    }
}