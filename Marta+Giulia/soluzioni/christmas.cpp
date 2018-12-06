#include <fstream>

using namespace std;

int values[100]; // Upper bound for N is 100
bool subset[101][4001];

// Returns true if there is a subset of set[] with sun equal to given sum 
bool isSubsetSum(int n, int sum) 
{
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
   
     // Fill the subset table in botton up manner 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<values[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         if (j >= values[i-1]) 
           subset[i][j] = subset[i-1][j] ||  
                                 subset[i - 1][j-values[i-1]]; 
       } 
     }
   
     return subset[n][sum]; 
} 

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n,b, sum = 0;
    in >> n >> b;

    for (int i=0; i<n; i++) {
        in >> values[i];
        sum += values[i];
    }
    bool found = false;

    for (int i=b; i < sum && !found; i++) {
        if (isSubsetSum(n,i)) {
            out << i << endl;
            found = true;
        }
    }

    if (!found) {
        out << sum << endl;
    }

    return 0;
}