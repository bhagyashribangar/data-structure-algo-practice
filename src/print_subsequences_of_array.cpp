// Print non-empty subsequences of array
#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(vector<int>& A, vector<int>& current, int index) 
{
    int n = A.size();

    // Print the current subsequence
    if (!current.empty()) {
        cout << "[";
        for (int i = 0; i < current.size(); i++) {
            cout << current[i];
            if (i < current.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    // Generate subsequences by including elements from starting index to the end of the array
    for (int i = index; i < n; i++) {
        current.push_back(A[i]);
        printSubsequences(A, current, i + 1);
        current.pop_back(); // Backtrack by removing the last element
    }
}

int main() {
    vector<int> A{1,2,3};

    vector<int> currentSubSequence;

    cout << "All subsequences of the array are:" << endl;
    printSubsequences(A, currentSubSequence, 0);

    return 0;
}
