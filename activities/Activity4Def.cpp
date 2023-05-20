// Jay Martinez - Activity4 - 5/19/23
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Activity4Header.hpp"
using namespace std;
const int N = 8;

namespace act4 {
    /*
    pseudocode for file_to_arr2d:

    if (file can be opened) {
        int arr[8][8];
        int row = 0;
        int col = 0;
        string num;
        while (file >> num) {
            num += file.get()
            arr[row][col] = num
            if (row == 8 && col < 8) 
                col++;
                row = 0;
            }
            elif (row == 8 && col == 8)
                break;
            else
                row++;
            }
        }
    }
    */
    vector<vector<double>> file_to_arr2d(string file_name) {
        // see if the file can be opened
        ifstream file(file_name);

        if (!file.is_open()) {
            cout<<"There was a problem opening the file"<<endl;
            exit(1);
        }

        // initialize 2d vector
        vector<vector<double>> arrd;
        vector<double> row;

        // used to help store file data in new array
        double num = 0.0;
        int r = 0;
        int c = 0;

        // puting file data into array
        while(file>>num) {
            row.push_back(num);
            if(r == N) {
                arrd.push_back(row);
                row.clear();
                r = 0;
                c++;
            }
            else if (c == N) 
                break;
            else 
                r++;
        }
        return arrd;
    }

    /*
    pseudocode for arr2d_to_arr3d:

    for i = 0; i < 3; i++
        for j = 0; j < 3; j++
            for k = 0; k < 3; k++
                arr3d[i][j][k] = arr2d[i]k + j*3]
    */
    // returns a 3d array
    vector<vector<vector<double>>> arr2d_to_arr3d(vector<vector<double>> arr2d) {
        vector<vector<vector<double>>> arr3d(3, vector<vector<double>>(3, vector<double>(3)));
        int r = 0;
        int c = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    arr3d[i][j][k] = arr2d[i][k + j * 3];
                    r++;
                }
                r++;
            }
            c++;
            r = 0;
        }
        return arr3d;
    }

    // creates output file containing sum, 2d array, 3d array
    void file_out() {
        ofstream out_file("Activity4Out.txt");
        vector<vector<double>> arr2d = act4::file_to_arr2d("Activity4.txt");
        vector<vector<vector<double>>> arr3d = act4::arr2d_to_arr3d(arr2d);
        double sum = 0.0;

        // prints the sum of the values
        for (const auto& row : arr2d) {
            for (const auto& e : row)
                sum += e;
        }
        out_file<<"The sum of the values in the file is: "<<sum<<endl<<endl;

        // prints the 2d vector
        out_file<<"2D Vector: "<<endl;
        for (const auto& row : arr2d) {
            for (const auto& e : row) {
                out_file<<e<<" ";
            }
            out_file<<endl;
        }
        out_file<<endl;


        // prints the 3d array
        out_file<<"3D Array: "<<endl;
        for (const auto& layer : arr3d) {
            for (const auto& row : layer) {
                for (const auto& value : row) {
                    out_file << value << " ";
                }
                out_file << endl;
            }
            out_file << endl;
        }
    }
}
