#include <stdio.h> 
#include <string.h> 
#include <limits.h>

typedef enum { false, true } bool;

int pwr(int base,int exp) {
    int res=1;
     
    while(exp>=1) {
        res*=base;
        exp--;
    }
    return(res);
}

int myatoibase(const char *nptr,const int base)
{

    
	int conv=0;
	int resultat=0;
	int baseTemp = strlen(nptr)-1;
    int i=0;
    bool negative=false;

    if(nptr==NULL) { return 0;}

    if (nptr[0]=='0' || nptr[1]=='0') { return -1;}

    if (base<2 || base>37) { return -2;} 
  

    if (nptr[0]=='-')
    {
        negative = true;
        i=1;
        baseTemp = strlen(nptr)-2;
    }

    while (nptr[i]!='\0') 
    {
      
      char temp = nptr[i];

      	if (temp >= '0' && temp <= '9'){
      		   conv=(int)temp - 48;
      		   if (conv < base)
      		   {
      		   		resultat += conv * pwr(base, baseTemp);
      		   		--baseTemp;
      		   }
	  		   else{
	  		       
	  		   		return -1;
	  		   }
        }
        else
        {
            if (temp>='a' && temp<='z'){
      		   conv=(int)temp - 87;
      		   if (conv < base)
      		   {
      		   		resultat += conv * pwr(base, baseTemp);
      		   		--baseTemp;
      		   }
      		   else{
      		    printf(" az sup a la range");
	  		   	return-1;
	  		   }
        }
        else
        {
          if (temp=='!'){
      		   conv = 36;
      		   if (conv < base)
      		   {
      		   		resultat += conv *pwr(base, baseTemp);
      		   		--baseTemp;
      		   }
      		   else{
	  		   	return-1;
	  		   }
          	} 	
          	else{
          	    return -1;
          	}
          
        }
        	
        }

          i++;

      }
    
      if (negative==true)
      {
      	resultat = -resultat;
      }
      
      if (resultat <= INT_MIN/2 || resultat >= INT_MAX/2){
            return -3;
            
    }
    else
    {
        return resultat;
    }
    


 }


