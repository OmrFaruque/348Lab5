#include <stdio.h>

int main() {
  int score;
  
  printf("Enter 0 or 1 to STOP\n");
  
  // Keep prompting until score <= 1
  do {
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    
    if(score <= 1)
      break;
    
    // Calculate all combinations
    printf("\nPossible combinations of scoring plays:\n");
    
    for(int td=0; td*6 <= score; td++) {
      for(int td_fg=0; td*7 + td_fg*1 <= score; td_fg++) {
        for(int td_2pt=0; td*8 + td_2pt*2 <= score; td_2pt++) {
          int remaining = score - (td*6 + td_fg + td_2pt*2);
          if(remaining % 3 == 0) {
            int fg = remaining / 3;
            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
              td_2pt, td_fg, td, fg, remaining-fg*3); 
          }
        }
      }
    }
    
    printf("\n");
    
  } while(score > 1);
  
  return 0;
}