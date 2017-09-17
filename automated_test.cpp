#include "LinkedInException.hpp"
#include "LinkedIn.hpp"

#include <iostream>
/*


create following connection graph
     -------------------------------
    |                               |
    |                               |          
  "John"  -----> "Michael" -----> "Smith" ---> "Ford" --> "Johnson" --> "Coore"
                    |                           |
                    |                           |
                     ---------------------------
*/

void checkResult( std::string source , std::string dest, int expected, int actual ) {
  std::cout << "\n No of hops between " << source << " to " << dest ;
  if (expected == actual ) {
    std::cout << " Passed! Result: " << expected ;
  } else {
    std::cout << " Failed! Expected: " << expected << " Actual: " << actual ;
  }
}

int main() {

  LinkedIn ln;
  ln.addConnection("John");
  ln.addConnection("Michael");
  ln.addConnection("Smith");
  ln.addConnection("Ford");
  ln.addConnection("Johnson");
  ln.addConnection("Coore");

  try {
    ln.addFriend("John", "Michael");
    ln.addFriend("John", "Smith");
    ln.addFriend("Michael", "Smith");
    ln.addFriend("Smith", "Ford");
    ln.addFriend("Ford", "Johnson");
    ln.addFriend("Michael", "Ford");
    ln.addFriend("Johnson", "Coore");
  } catch (LinkedInException ex) {
    std::cout << ex.what();
  }

  try {
    // John - Smith - Ford - Johnson -- Coore ==== 3
    checkResult("John", "Coore", 3,  ln.findHop("John","Coore"));
    // Michael - Ford - Johnson == 1 
    checkResult("Michael", "Johnson", 1, ln.findHop("Michael", "Johnson"));
    // John - Smith == 0
    checkResult("John","Smith", 0, ln.findHop("John","Michael"));
    // Smith - Ford - Johnson - Coore == 2
    checkResult("Smith", "Coore", 2, ln.findHop("Smith", "Coore"));
  } catch (LinkedInException ex) {
     std::cout << ex.what();
  }

  std::cout << "\n";
}
