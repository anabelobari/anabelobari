#include <iostream> 
using namespace std;
 
class new_node {
      
   public:
      
      int x, y; 
      string name; 

      new_node (int x_var, int y_var, string name_var) {
         x = x_var;
         y = y_var;
         name = name_var;
      }
      ~new_node(){};
};