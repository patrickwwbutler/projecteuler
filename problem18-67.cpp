/* This file contains my solution for the maximum path sum problem for
 * The triangles in problems 18 and 67 on projecteuler.net
 *
 */


#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Simple function to parse the triangle from cin
 */
vector<vector<int> > parseTriangle(){
  int input;
  vector<vector<int> > triangle;
  int level = 1;
  while(cin){
    triangle.push_back(vector<int>());
    for(int i = 0; i < level; i++){
      cin >> input;
      triangle[level - 1].push_back(input);
    }
    level++;
  }
  triangle.pop_back();
  return triangle;
}

/* This function uses a modiied version of dijkstra's search algorithm,
 * as this is essentially a search problem in which each number in the triangle
 * is a vertex, and has one way edges to the two numbers below it.
 * We are trying to find the highest cost path from the top vertex to any vertex
 * on the bottom level.
 * The maxSum triangle will include the highest possible sum up to that vertex.
 * At the end, the highest value in maxSum will be the answer.
 */

int maxPathSum(vector<vector<int> >& triangle){
  vector<vector<int> > maxSum(triangle.size());
  for(int i = 0; i < maxSum.size(); i++){
    maxSum[i] = vector<int>(triangle[i].size(), 0);
  }
  maxSum[0][0] = triangle[0][0];
  int maximumPathSum = 0;

  for(int i = 0; i < triangle.size() - 1; i++){
    for(int j = 0; j < triangle[i].size(); j++){

      if(maxSum[i][j] + triangle[i+1][j] > maxSum[i+1][j]){
        maxSum[i+1][j] = maxSum[i][j] + triangle[i+1][j];
        if(maxSum[i+1][j] > maximumPathSum){
          maximumPathSum = maxSum[i+1][j];
        }
      }

      if(maxSum[i][j] + triangle[i+1][j+1] > maxSum[i+1][j+1]){
        maxSum[i+1][j+1] = maxSum[i][j] + triangle[i+1][j+1];
        if(maxSum[i+1][j+1] > maximumPathSum){
          maximumPathSum = maxSum[i+1][j+1];
        }
      }

    }
  }

  return maximumPathSum;
}


int main(){
  cout << "Please enter the triangle followed by a semicolon" << endl;
  vector<vector<int> > triangle = parseTriangle();
  cout << maxPathSum(triangle) << endl;

  return 0;
}
