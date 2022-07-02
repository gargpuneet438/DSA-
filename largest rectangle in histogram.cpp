int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int i,j,n=heights.size();
     stack<int> st;
     int area=0;
     for(i=0;i<=n;i++){
         while(!st.empty() && (i==n || heights[st.top()]>=heights[i] )){
             int h=heights[st.top()];
             st.pop();
             int w;
             if(st.empty())
                  w=i;
             else
                 w=i-st.top()-1;
             area=max(area,w*h);
         }st.push(i);
         
     }return area;
     
 }
