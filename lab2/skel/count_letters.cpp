#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    map<char, int> letters;
    vector<string> words;

    for (int i = 32; i < 128; i++) {
        letters[(char)i] = 0;
    }

    double start_time = omp_get_wtime();

    for (int i = 1; i <= 100; i++) {
        string filename = "files/f" + to_string(i);
        char content[10000];
        FILE *file;

        file = fopen(filename.c_str(),"r");
        while (fgets(content, sizeof(content), file) != NULL)
        
        string temp(content);
        words.push_back(string(content));
        fclose(file);
    }

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            letters[words[i][j]]++;
        }
    }

    double end_time = omp_get_wtime();

    for (int i = 32; i < 128; i++) {
        cout << (char)i << ": " << letters[char(i)] << endl;
    }

    cout << "------------------------------------------" << endl;
    cout << "Timp de executie (serial): " << end_time - start_time << " secunde" << endl;
    
    return 0;
}