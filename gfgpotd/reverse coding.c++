int sumOfNaturals(int n) {
        // code here
        long sum =((long)n*(n+1))/2;
        long long num=pow(10,9)+7;
        return sum % num;
    }