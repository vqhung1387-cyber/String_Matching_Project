#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include "algorithms.h"


using namespace std;

void readInputFile(string filename, vector<vector<char>> &dict, vector<string> &testCase);

void writeAlgorithmCompTime(string name, int cmp, chrono::duration<double> time, string filename);

void writeOuputRes(string filename, vector<MatchResult> &results, string testName);

extern int cnt;
