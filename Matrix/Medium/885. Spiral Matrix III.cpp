class Solution {
public:
    static bool inside(int i, int j, int rows, int cols){
        return (i>=0)&&(i<rows)&&(j>=0)&&(j<cols);
    }
    static vector<vector<int>> spiralMatrixIII(int rows, int cols, int r0, int c0) 
    {
        vector<vector<int>> ans(rows*cols);
        ans[0]={{r0, c0}};
        int layer=max({rows-r0, cols-c0, r0+1, c0+1})+1;
        int i=r0, j=c0, k=1;
        for(int m=1; m<layer; m++){
            int di=0, dj=1, step=2*m-1;// rightward
            for(int a=0; a<step; a++){
                i+=di, j+=dj;
                if (inside(i,j, rows, cols)) ans[k++]={{i, j}};
            }
            di=1, dj=0; //downward
            for(int a=0; a<step; a++){
                i+=di, j+=dj;
                if (inside(i,j, rows, cols)) ans[k++]={{i, j}};
            }
            di=0, dj=-1;//leftward
            step++; //increase step
            for(int a=0; a<step; a++){
                i+=di, j+=dj;
                if (inside(i,j, rows, cols)) ans[k++]={{i, j}};
            }
            di=-1, dj=0; //upward
            for(int a=0; a<step; a++){
                i+=di, j+=dj;
                if (inside(i,j, rows, cols)) ans[k++]={{i, j}};
            }
        }
        return ans;
    }
};