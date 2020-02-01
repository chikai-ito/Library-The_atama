//g(S) = sum of f(T) s.t.S <= T
    for(int i=0;i<n;i++){
        for(int bit=0;bit<(1ll << n);bit++){
            if(!(bit >> i & 1))func[bit] += func[bit ^ (1 << i)];
        }
    }
    //g(S) = sum of f(T) s.t. T <= s
    for(int i=0;i<n;i++){
        for(int bit=0;bit<(1ll << n);bit++){
            if(bit >> i & 1)func[bit] += func[bit ^ (1 << i)];
        }
    }
    //inverse of 1
    for(int i=0;i<n;i++){
        for(int bit=0;bit<(1ll << n);bit++){
            if(!(bit >> i & 1))func[bit] -= func[bit ^ (1 << i)];
        }
    }
    //inverse of 2
    for(int i=0;i<n;i++){
        for(int bit=0;bit<(1ll << n);bit++){
            if(bit >> i & 1)func[bit] -= func[bit ^ (1 << i)];
        }
    }
