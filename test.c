// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

void itoa(int n, char *str){
	int temp, len;
	temp = n;
	len = 1;
	while (temp/10!=0){
		len++;
		temp /= 10;
	}
	for (temp = len; temp > 0; temp--){
		str[temp-1] = (n%10)+48;
		n/=10;
	}
	str[len]='\0';
}

int
main(void)
{
  int pid;
  char path[16];
  pid = getpid();
  strcpy(path, "/proc/");
  itoa(pid, path+6);

  printf(1, "user tries to open path: %s\n", path);


  exit();
}