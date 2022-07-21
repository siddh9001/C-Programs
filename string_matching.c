// You have a string A = A1A2...An consisting of lowercase English letters only.
// You are allowed to choose any two indices i and j such that 1 ≤ i ≤ j ≤ n and reverse substring AiAi+1...Aj.
// You can perform this operation atmost once.
// You can choose to not perform this operation at all.
// How many different strings can you obtain?

// INPUT
// Input consists of a single string A

// OUTPUT
// Print the number of different strings you can obtain by reversing any substring in A at most once.

// CONSTRAINTS
// 1 ≤ |A| ≤ 200,000
// A consists of lowercase English characters only.

// Sample Input 0

// aatt
// Sample Output 0

// 5
// Sample Input 1

// xxxxxxxxxx
// Sample Output 1

// 1
// Sample Input 2

// abracadabra
// Sample Output 2

// 44
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[200005];
    int a[26]={0};
    scanf("%s",s);
    int n=strlen(s);
    long c=1;
    for(int i=0;i<n;i++)
    {
        c=c+i-a[s[i]-97];
        a[s[i]-97]++;
    }
    printf("%ld",c);
}