ll s = 0, t = 0;
    for(int i=0;i<n;i++){
        while(s < t && x[deq[t-1]] >= x[i])t--;
        deq[t++] = i;
 
        if(i - k + 1 >= 0){
            small[i - k + 1] = x[deq[s]];
            if(deq[s] == i - k + 1){
                s++;
            }
        }
    }