#import <Cocoa/Cocoa.h>
<<<<<<< Updated upstream
#include "swell.h"
=======
>>>>>>> Stashed changes

int main(int argc, char *argv[])
{
  return NSApplicationMain(argc,  (const char **) argv);
}
<<<<<<< Updated upstream

void CenterWindow(HWND hwnd)
{
  if (!hwnd) return;
  
  id turd=(id)hwnd;
  
  if ([turd isKindOfClass:[NSView class]])
  {
    NSWindow *w = [turd window];
    [w center];
  }
  if ([turd isKindOfClass:[NSWindow class]])
  {
    [turd center];
  }
}

=======
>>>>>>> Stashed changes
