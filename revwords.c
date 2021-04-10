#include <ctype.h>
#include <string.h> 
#include "revwords.h"

void reverse_substring(char str[], int start, int end) { 
  for (int i=start, j=end;i<j;i++,j--) {
	  char temp = str[i];
	  str[i]=str[j];
	  str[j]=temp;
  }
}

int find_next_start(char str[], int len, int i) { 
  if (i>=len) {
	  return -1;
  } else if (i==0 && ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))) {
	  return 0;
  } else if ((!((str[i-1] >= 97 && str[i-1] <= 122) || (str[i-1] >= 65 && str[i-1] <= 90))) && ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))) {
	  return i;
  } else {
	  //find first non alpha char
	  for(int j=i;j<len;j++) {
		 if (!((str[j] >= 97 && str[j] <= 122) || (str[j] >= 65 && str[j] <= 90)))  {
			 int counter = 1;
			 while (j+counter < len && !((str[j+counter] >= 97 && str[j+counter] <= 122) || (str[j+counter] >= 65 && str[j+counter] <= 90))) {
				 counter++;
			 }
			 if(j+counter == len) {
				 return -1;
			 } else {
				 return j+counter;
			 }
		 }
	  }
	  return -1;
  }
  
}

int find_next_end(char str[], int len, int i) {
  if (i>=len) {
	  return -1;
  } else {
	  while(!(((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)) && !((str[i+1] >= 97 && str[i+1] <= 122) || (str[i+1] >= 65 && str[i+1] <= 90))) && i<len) {
		  i++;
	  }
	  if (i==len) {
		  if (((str[i-1] >= 97 && str[i-1] <= 122) || (str[i-1] >= 65 && str[i-1] <= 90))) {
			  return i-1;
		  } else {
			return -1;
		  }
	  } else {
		 return i; 
	  }
  }
}

void reverse_words(char s[]) { 
  int len = strlen(s);
  int i=0;
  while(i!=-1) {
	 int start = find_next_start(s, len, i);
	 reverse_substring(s,start,find_next_end(s,len,start));
	 i = find_next_start(s,len,i+1);
	 int c=2; 
	 while(i==start && i!=-1) {
		 i=find_next_start(s,len,i+c);
		 c++;
	 }
  }
}
