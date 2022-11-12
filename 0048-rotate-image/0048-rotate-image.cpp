class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //Runtime  4 ms
        
        
//         //transpose 
        
//         for(int i=0;i<matrix.size();i++){
//             for(int j=i+1;j<matrix.size();j++){
//                 swap(matrix[i][j],matrix[j][i]);
//             }
//         }
        
//         // interchanging row and columns
//         for(int j = 0; j < matrix.size()/2; j++) {
//             for(int i = 0; i < matrix.size(); i++) {
//                 swap(matrix[i][j], matrix[i][matrix.size() - j - 1]);
//             }
//         }
        
        
        // Runtime 0 ms
        
        
         // First step to transpose(swap)
        for(int i = 0 ; i < matrix.size() ; i++) {
            for(int j = 0 ; j < i ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //  Second step to reverse the whole rows one by one
        for(int i = 0 ; i < matrix.size() ; i++)
        reverse(matrix[i].begin(), matrix[i].end());
        
        
        // int n=matrix.size();
        // int a=0,b=n-1;
        // while(a<b){
        //     for(int i=0;i<b-a;i++){
        //         swap(matrix[a][a+i],matrix[a+i][b]);
        //         swap(matrix[a][a+i],matrix[b][b-i]);
        //         swap(matrix[a][a+i],matrix[b-i][a]);
        //     }
        //     a++;
        //     b--;
        // }
        // int a = 0, b = matrix.size()-1;
        // while(a < b) {
        //     for(int i = 0 ; i < b-a ; i++){
        //         swap(matrix[a][a+i], matrix[a+i][b]);
        //         swap(matrix[a][a+i], matrix[b][b-i]);
        //         swap(matrix[a][a+i], matrix[b-i][a]);
        //     }
        //     a++;
        //     b--;
        // }
    }
};