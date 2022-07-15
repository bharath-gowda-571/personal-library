#include "hash_util.h"

int Hash::hash(string key){
    int sum=0;
    int len=key.length();
    if(len%2==1) len++;
    for(int j=0;j<len;j+=2)
        sum=(sum+100*key[j]+key[j+1])%100;
    return sum;

}
