#ifndef csv_h
#define csv_h
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct parsedCsvBarData {
    vector<string> labels;
    vector<int> values;
};
parsedCsvBarData parseCsvBarData(char* filename){
    parsedCsvBarData data;
    std::ifstream file(filename);
    std::vector<std::vector<std::string> > dataList;
    std::string line = "";
    size_t colunms = 2;
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        stringstream s_stream(line);
        string substr;
        // extract label
        getline(s_stream, substr, ',');
        data.labels.push_back(substr);
        if(s_stream.good()){
            getline(s_stream, substr, ',');
            data.values.push_back(stoi(substr));
        }
    }
    // Close the File
    file.close();
    cout<<"parsed csv labels:"<<data.labels.size()<<"\n";
    return data;
}
#endif /* csv_h */
